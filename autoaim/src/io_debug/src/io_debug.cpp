// 线程安全、包含serial实现的节点
// This is a debug version.
// 通用版本的io改进, 对comm相关的操作都会被上锁
// 修改了RobotCmdConvert函数
// 要最小化线程持有锁的时间
#include <bitset>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <my_interfaces/msg/detail/robot_status__struct.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node_options.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>

#include <stdexcept>
#include <string>
#include <thread>

// sources, linking in libraries
#include "minipc_comm/minipc_comm.hpp"
#include "minipc_comm/minipc_protocol.hpp"
#include "minipc_comm/robot.hpp"
#include "minipc_comm/robot_comm_middleware.hpp"

// ROS2
#include "my_interfaces/msg/robot_cmd.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "rclcpp/rclcpp.hpp"

// serial comm
#include "serial/serial.h"

// Node register
#include "rclcpp_components/register_node_macro.hpp"

#define DETAIL_LOGGER // 参数打印
// 两个都注释是正常，注释其中一个是只看对方，不能两个都不注释。
//#define ONLY_RX // debug Rx
//#define ONLY_TX // debug Tx
// todo: base include and webview.

using namespace std::chrono_literals;

//  car5 board 的串口是 "USB VID:PID=10c4:ea60 SNR=b87a75e913eeec11abfd2cf90f611b40" ?
const std::string ROBOT_USB_HID =
    "USB VID:PID=10c4:ea60 SNR=b87a75e913eeec11abfd2cf90f611b40"; //根据车车上面的修改
const auto SERIAL_RECONNECT_PERIOD = 500ms;
const auto continuous_write_interval = 7ms;
const auto contibuous_read_interval = 10ms; // 读取线程5ms一次
const unsigned int COMMUNICATE_ERROR_THRES = 10; // Modified to better locate, default 10
const uint32_t BAUDRATE = 115200;
const std::string sub_topic_name = "robot_cmd";
const std::string pub_topic_name = "minipc_topic";
const int info_freq = 1000;

namespace minipc {
class SubscriberError: public std::runtime_error {
protected:
    using std::runtime_error::runtime_error;
};

class SubscriberError_NullCmd: public SubscriberError {
public:
    SubscriberError_NullCmd():
        SubscriberError("Cmd point to a nullptr. Try to check subscallback.") {}
};

class MiniPcNode: public rclcpp::Node {
public:
    explicit MiniPcNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~MiniPcNode() override;

private:
    // 节点初始化
    void init_node();
    // 查找并打开串口
    bool SerialAutoConnect(serial::Serial& serial_port, const std::string& usb_hid);
#if !defined(ONLY_RX)
    // 串口发送数据、错误处理
    void robotCommTx(serial::Serial& serial_port, std::shared_ptr<MiniPCComm> comm);
    // 串口放送线程
    void robotCommTxThread_loop(serial::Serial& serial_port, std::shared_ptr<MiniPCComm> comm);
#endif
#if !defined(ONLY_TX)
    // 串口接受线程
    void robotCommRxThread_loop(serial::Serial& serial_port, std::shared_ptr<MiniPCComm> comm);
#endif
#if !defined(ONLY_RX)
    // 订阅callback (这样的引用是否可以用sharedptr替代)
    // publisher 的回调参数用sptr
    void sub_callback(const my_interfaces::msg::RobotCmd::SharedPtr recv_msg);
#endif
    // 将Status消息转化成ros2能publish的
    my_interfaces::msg::RobotStatus StatusMsg_gen(const std::shared_ptr<RobotStatus> status);

#ifdef DETAIL_LOGGER
    void detail_publish(const std::shared_ptr<RobotStatus> status);
    // 计数器，用来减少打印的次数？
    unsigned long long logger_cnt = 0;
#endif

private:
    rclcpp::Publisher<my_interfaces::msg::RobotStatus>::SharedPtr publisher_;
    // 需要向webview发送的信息的pub
    rclcpp::Subscription<my_interfaces::msg::RobotCmd>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::shared_ptr<RobotStatus> status_;
    std::shared_ptr<MiniPCComm> comm_;
    std::shared_ptr<RobotCmd> cmd_;

    std::mutex sub_mutex_;

    std::deque<RobotCmd> robot_cmd_queue_;

    std::thread Rx_loop_thread_;
    std::thread Tx_loop_thread_;

    serial::Serial serial_port_;

    int fail_count_ = 0;
#ifdef DETAIL_LOGGER
    int cnt_ = 0;
    bool logger_on_ = true;
#else
    bool logger_on_ = false;
#endif
};
} // namespace minipc

minipc::MiniPcNode::MiniPcNode(const rclcpp::NodeOptions& options): Node("minipc_node", options) {
    RCLCPP_INFO(this->get_logger(), "ROS2 Node starting.");

    init_node();
    // RCLCPP_INFO(this->get_logger(), "ROS2 Node created.");
#if !defined(ONLY_TX)
    //开启线程:注意这里的线程需要传入参数
    Rx_loop_thread_ =
        std::thread(&MiniPcNode::robotCommRxThread_loop, this, std::ref(serial_port_), comm_);
    RCLCPP_INFO(this->get_logger(), "Running Rx thread.");
#endif
#if !defined(ONLY_RX)
    Tx_loop_thread_ =
        std::thread(&MiniPcNode::robotCommTxThread_loop, this, std::ref(serial_port_), comm_);
    RCLCPP_INFO(this->get_logger(), "Running Tx thread.");
#endif
}

minipc::MiniPcNode::~MiniPcNode() {
    RCLCPP_INFO(this->get_logger(), "Trying to destroy the node.");
    serial_port_.close();
    RCLCPP_INFO(this->get_logger(), "Serial Port closed.");
    rclcpp::shutdown();
#if !defined(ONLY_TX)
    if (Rx_loop_thread_.joinable()) {
        Rx_loop_thread_.join();
    }
#endif
#if !defined(ONLY_RX)
    if (Tx_loop_thread_.joinable()) {
        Tx_loop_thread_.join();
    }
#endif
    RCLCPP_INFO(this->get_logger(), "ROS2 Node destructred.");
}

void minipc::MiniPcNode::init_node() {
    RCLCPP_INFO(this->get_logger(), "Initializing the node.");
    comm_ = std::make_shared<MiniPCComm>();
    status_ = std::make_shared<RobotStatus>();
    cmd_ = std::make_shared<RobotCmd>();
    // todo qos的回调函数
#if !defined(ONLY_TX)
    publisher_ = this->create_publisher<my_interfaces::msg::RobotStatus>(
        pub_topic_name,
        rclcpp::QoS(10)
    ); // may drop packs if needed, can be modified
#endif
#if !defined(ONLY_RX)
    subscriber_ = this->create_subscription<my_interfaces::msg::RobotCmd>(
        sub_topic_name,
        rclcpp::QoS(10),
        std::bind(&MiniPcNode::sub_callback, this, std::placeholders::_1)
    );
#endif
    // 串口初始化
    SerialAutoConnect(serial_port_, ROBOT_USB_HID);
    RCLCPP_INFO(this->get_logger(), "Node inited.");
    return;
}

#if !defined(ONLY_RX)
void minipc::MiniPcNode::sub_callback(const my_interfaces::msg::RobotCmd::SharedPtr recv_msg) {
    if (logger_on_) {
        RCLCPP_INFO(this->get_logger(), "Subscriber callback. RobotCmd Modified.");
    }

    // 对着类型在check一遍，是否需要强制类型转换
    cmd_->start = (unsigned)'s'; // start 直接强制给sof
    cmd_->seq_id = recv_msg->seq_id;
    cmd_->aim_id = recv_msg->aim_id;
    cmd_->car_id = recv_msg->car_id;
    cmd_->detection_info = recv_msg->detection_info;
    cmd_->yaw = recv_msg->yaw;
    cmd_->pitch = recv_msg->pitch;
    cmd_->yaw_v = recv_msg->yaw_v;
    cmd_->pitch_v = recv_msg->pithc_v; // 打错了需要修改
    cmd_->dist = recv_msg->dist;
    cmd_->shoot = (ShootMode)recv_msg->shoot; //注意这是uint8
    cmd_->period = recv_msg->period;
    cmd_->lrc = recv_msg->lrc; // 对面到底发不发这个？
    cmd_->lock_yaw = recv_msg->lock_yaw; //默认是false，对面到底改不改这个
    cmd_->end = (unsigned)'e'; //结束符
    if (logger_on_)
        RCLCPP_INFO(this->get_logger(), "Recv checking: --pitch %f", cmd_->pitch);

    std::unique_lock<std::mutex> lock(sub_mutex_);
    robot_cmd_queue_.push_back(*cmd_);
    return;
}
#endif

bool minipc::MiniPcNode::SerialAutoConnect(
    serial ::Serial& serial_port,
    const std::string& usb_hid
) {
    RCLCPP_INFO(this->get_logger(), "Finding serial port\n");
    for (const auto& port_info: serial::list_ports()) {
        if (logger_on_) {
            RCLCPP_INFO_STREAM(
                this->get_logger(),
                "listing port: " << port_info.port << " | " << port_info.hardware_id
            );
        }
        if (port_info.hardware_id == usb_hid) {
            RCLCPP_INFO_STREAM(
                this->get_logger(),
                "Find port: " << port_info.port << "|" << port_info.hardware_id << std::endl
            );
            serial_port.setPort(port_info.port);
            serial_port.setBaudrate(BAUDRATE);
            auto time_out =
                serial::Timeout::simpleTimeout(serial::Timeout::max()); // 可以修改timeout的最大时长
            serial_port.setTimeout(time_out);
            // 串口打开检查
            try {
                serial_port.open();
            } catch (serial::SerialException& e) {
                // 之后可以试着加上颜色
                RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
            } catch (serial::IOException& e) {
                RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
            }
            break;
        }
    }

    if (!serial_port.isOpen()) {
        RCLCPP_WARN(this->get_logger(), "[EEROR] (robot_io_usb): robot serial open failed.\n");
        return false;
    } else {
        RCLCPP_INFO(this->get_logger(), "(robot_io_usb): robot serial opened successfully.\n");
        return true;
    }
}

#if !defined(ONLY_RX)
void minipc::MiniPcNode::robotCommTx(
    serial::Serial& serial_port,
    std::shared_ptr<MiniPCComm> comm
) {
    if (serial_port.isOpen()) {
        try {
            serial_port.write(comm->tx_.buf, comm->tx_.pack_size); // 向串口发送data
        } catch (serial::SerialException& e) {
            // 发送失败的错误
            RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
            serial_port.close();
            std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD);
        } catch (serial::IOException& e) {
            RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
            serial_port.close();
            std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD);
        }
        if (logger_on_) {
            RCLCPP_INFO(
                this->get_logger(),
                "Serial Port done Transmit to Board. Message Attribute: %u , Direction: %u .",
                (uint8_t)(comm->tx_.frame.pack_id && 0x0f),
                (uint8_t)(comm->tx_.frame.pack_id & 0xf0)
            ); // direction 0000 PC2BOARD 1111 BOARD2PC
        }
    } else {
        std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD);
    }
    return;
}

void minipc::MiniPcNode::robotCommTxThread_loop(
    serial::Serial& serial_port,
    std::shared_ptr<MiniPCComm> comm
) {
    RCLCPP_INFO(this->get_logger(), "Subscribing RobotCmd.");
    // todo here need something for the webview.
    while (rclcpp::ok()) {
        MiniPCCommMsgStream stream = MiniPCCommMsgStream::PC2BOARD;
        {
            std::unique_lock<std::mutex> lock(sub_mutex_);
            comm->handle(); // handle 函数会更新mode_
            // 放送通用数据包
            comm->txMsgHandle(stream, MiniPCCommMsgType::GENERAL);
            robotCommTx(serial_port, comm);
        } // 释放互斥锁

        std::this_thread::sleep_for(continuous_write_interval);
        // 放送功能数据包
        // 自瞄/打符/反符
        if (comm->mode_ == MiniPCMode::AUTOAIM || comm->mode_ == MiniPCMode::ENERGY
            || comm->mode_ == MiniPCMode::ENERGY_DISTURB)
        {
    #ifdef DETAIL_LOGGER
            RCLCPP_INFO(this->get_logger(), "[TxThread] In Autoaim/Energy/Energy_Disturb Mode.");
    #endif
            for (int i = 0; i < 20; i++) {
                if (!robot_cmd_queue_.empty()) {
                    std::unique_lock<std::mutex> lock(sub_mutex_);
                    robotCmdConvert(comm, robot_cmd_queue_.front());
                    robot_cmd_queue_.pop_front();
                    comm->txMsgHandle(stream, MiniPCCommMsgType::AIM_SHOOT);
                    robotCommTx(serial_port, comm);
                }
                std::this_thread::sleep_for(continuous_write_interval);
            }

        } //导航
        else if (comm->mode_ == MiniPCMode::NAVIGATION)
        {
    #ifdef DETAIL_LOGGER
            RCLCPP_INFO(this->get_logger(), "[TxThread] In Navigation Mode.");
    #endif
            for (int i = 0; i < 20; i++) {
                if (!robot_cmd_queue_.empty()) {
                    std::unique_lock<std::mutex> lock(sub_mutex_);
                    robotCmdConvert(comm, robot_cmd_queue_.front());
                    robot_cmd_queue_.pop_front();
                    comm->txMsgHandle(stream, MiniPCCommMsgType::NAVIGATION);
                    robotCommTx(serial_port, comm);
                }
                std::this_thread::sleep_for(continuous_write_interval);
            }
        } // 决策（导航+自瞄）
        else if (comm->mode_ == MiniPCMode::DECISION)
        {
    #ifdef DETAIL_LOGGER
            RCLCPP_INFO(this->get_logger(), "[TxThread] In Decision Mode.");
    #endif
            for (int i = 0; i < 10; i++) {
                // pack1
                if (!robot_cmd_queue_.empty()) {
                    std::unique_lock<std::mutex> lock(sub_mutex_);
                    robotCmdConvert(comm, robot_cmd_queue_.front());
                    robot_cmd_queue_.pop_front();
                    comm->txMsgHandle(stream, MiniPCCommMsgType::AIM_SHOOT);
                    robotCommTx(serial_port, comm);
                }
                std::this_thread::sleep_for(continuous_write_interval);
                //pack2
                if (!robot_cmd_queue_.empty()) {
                    std::unique_lock<std::mutex> lock(sub_mutex_);
                    robotCmdConvert(comm, robot_cmd_queue_.front());
                    robot_cmd_queue_.pop_front();
                    comm->txMsgHandle(stream, MiniPCCommMsgType::NAVIGATION);
                    robotCommTx(serial_port, comm);
                }
                std::this_thread::sleep_for(continuous_write_interval);
                // 在等待的时间中可能有包进入
            }
        } else {
            // comm->mode是 除以上意外的 ：IDLE
            std::this_thread::sleep_for(19 * continuous_write_interval);
    #ifdef DETAIL_LOGGER
            RCLCPP_INFO(this->get_logger(), "[TxThread] In Low Data Pack Modle: IDLE.");
    #endif
        }
    }

    rclcpp::shutdown();
    return;
}
#endif

#if !defined(ONLY_TX)
// 这个函数里面status是来自这个类管理的，comm是参数
void minipc::MiniPcNode::robotCommRxThread_loop(
    serial::Serial& serial_port,
    std::shared_ptr<MiniPCComm> comm
) {
    RCLCPP_INFO(this->get_logger(), "Publishing RobotStatus.");
    while (rclcpp::ok()) {
        if (serial_port.isOpen()) {
            try {
                // debug
                // RCLCPP_INFO(this->get_logger(), "step1\n");
                // end
                serial_port.read(comm->rx_.byte, 1);
                // debug
                // RCLCPP_INFO(this->get_logger(), "step2\n");
                // end
                {
                    std::unique_lock<std::mutex> lock(sub_mutex_);
                    comm->rxCallback(); // 更新将要comm的信息
                    // 会有相关输codeio_node出 // 如果callback没有得到新信息是不是就不该pub？
                    robotStatusConvert(comm, status_);
                }
                // debug
                // RCLCPP_INFO(this->get_logger(), "step3,callback finished.\n");
                // end
                if (comm->unpack_error_ != MiniPCComm::NO_ERROR) {
                    if (comm->continus_error_cnt > COMMUNICATE_ERROR_THRES) {
                        std::string error_code = "serial data unpack error"
                            + std::__cxx11::to_string((int)comm->unpack_error_);
                        throw serial::SerialException(error_code.c_str());
                    }
                }
                publisher_->publish(StatusMsg_gen(status_)
                ); // status信息放送,但可能不是实时的。所以可能重复放送
                // debug
                // RCLCPP_INFO(this->get_logger(), "step5 published");
                // end
            } catch (serial::SerialException& e) {
                RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
                serial_port.close();
                std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD); // thread is declared in
            } catch (serial::IOException& e) {
                RCLCPP_WARN(this->get_logger(), "[ERROR] (robot_io_usb) {}\n", e.what());
                serial_port.close();
                std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD);
            }
            // No Error
            if (logger_on_) {
                detail_publish(status_);
            }
            // 线程休憩中
            std::this_thread::sleep_for(contibuous_read_interval); // 不加这行线程会死循环无法退出
        } else {
            // 串口未能正常打开
            if (logger_on_) {
                cnt_++;
                RCLCPP_WARN(
                    this->get_logger(),
                    "[WARNING] Serial Port faield to open during publishing the %d times.",
                    cnt_
                );
            }
            std::this_thread::sleep_for(SERIAL_RECONNECT_PERIOD);
            // 端口重联，spoon通信中没有，不知道有没有必要加上（防止port在网页端打开后占用串口）
            SerialAutoConnect(serial_port, ROBOT_USB_HID);
        }
    }
    rclcpp::shutdown();
    return;
}
#endif

my_interfaces::msg::RobotStatus
minipc::MiniPcNode::StatusMsg_gen(const std::shared_ptr<RobotStatus> status) {
    auto message = my_interfaces::msg::RobotStatus();

    message.bullet_speed = status->bullet_speed;
    message.yaw_compensate = status->yaw_compensate;
    message.pitch_compensate = status->pitch_compensate;
    message.enemy_color = (uint8_t)status->enemy_color; // in old protocol this only takes up 1 bit
    message.is_big_energy = (uint8_t)status->is_big_energy;
    message.program_mode = (uint8_t)status->program_mode;
    message.latency_cmd_to_fire = status->latency_cmd_to_fire;
    message.last_shoot_aim_id = status->last_shoot_aim_id;
    message.laser_distance = status->laser_distance;

    return message;
}

#ifdef DETAIL_LOGGER
void minipc::MiniPcNode::detail_publish(const std::shared_ptr<RobotStatus> status) {
    // Publish status message for debuging
    if (logger_cnt % info_freq == 0) {
        RCLCPP_INFO(this->get_logger(), "RxThread is spinning.");
        RCLCPP_INFO(this->get_logger(), "successfully published");
        RCLCPP_INFO(
            this->get_logger(),
            "\n--------------\nPublishing DETAILS from Rx\nPROGRAM MODE: %u\nBullet Speed: %f\nYaw compensate: %f\nPitch compensate: %f\nEnemy color: %u\nIs_Big_Energy: %u\nLatency to fire: %u\n-----------\n",
            (uint8_t)status->program_mode,
            status->bullet_speed,
            status->yaw_compensate,
            status->pitch_compensate,
            (uint8_t)status->enemy_color,
            (uint8_t)status->is_big_energy,
            status->latency_cmd_to_fire
        );
        logger_cnt++;
    } else {
        logger_cnt++;
    }
    return;
}
#endif

RCLCPP_COMPONENTS_REGISTER_NODE(minipc::MiniPcNode)