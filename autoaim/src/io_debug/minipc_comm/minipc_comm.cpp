/**
 ******************************************************************************
 * @file    minipc_comm.cpp/h
 * @brief   MiniPC communication(UART). MiniPC通信(UART)
 * @author  Spoon Guan
 ******************************************************************************
 * @protocol 通信协议
 * 1. UART config 串口配置
 *    波特率115200，8位数据位，1位停止位，无硬件流控，无校验位
 * 2. frame format 数据帧格式
 *    header(3-byte)+data(n-byte)+tail(2-byte)
 *    header: SOF(1-byte, 0x23)+pack_id(1-byte)+data_len(1-byte,=n)
 *    data: n-byte
 *    tail: CRC16(2-byte)
 ******************************************************************************
 * Copyright (c) 2023 Team JiaoLong-SJTU
 * All rights reserved.
 ******************************************************************************
 */

#include "minipc_comm.hpp"

#include "serial_comm/include/crc.h"
#include <cstdint>

// 三个输出开关方便debug ：如果final output成功的话就说明数据获取成功
// #define WARNING_OUTPUT
//#define DETAIL_LOGGER
#define FINAL_OUTCOME
#if defined(DETAIL_LOGGER) || defined(FINAL_OUTCOME)
    #include "rclcpp/rclcpp.hpp"
bool logger_on_ = true;
auto logger = rclcpp::get_logger("rxCallback");
unsigned long long logger_cnt = 0;
const int info_freq = 1; // 值越大频率越低
#else
bool logger_on_ = false;
#endif

const uint32_t minipc_comm_timout = 1000; // ms

MiniPCComm::MiniPCComm():
    unpack_step_(WAIT),
    general_connect_(minipc_comm_timout),
    aim_shoot_connect_(minipc_comm_timout),
    navigation_connect_(minipc_comm_timout),
    game_status_connect_(minipc_comm_timout),
    continus_error_cnt(0) {}

// Handle
void MiniPCComm::handle(void) { // 除了通信检查以外还有视觉工作模式反馈
    general_connect_.check();
    aim_shoot_connect_.check();
    navigation_connect_.check();
    game_status_connect_.check();

    if (general_connect_.check()) {
        mode_ = (MiniPCMode
        )general_board2pc_msg_.mode; // 这个mode会由之后的节点修改，然后在这里反馈给mode_fdb
    }
    general_pc2board_msg_.mode_fdb = (uint8_t)mode_;
}

// Data transmit 数据发送
void MiniPCComm::txMsgHandle(MiniPCCommMsgStream msg_stream, MiniPCCommMsgType msg_type) {
    // start of frame(0x23)
    tx_.frame.sof = minipc_comm_sof;
    memcpy(tx_.buf, &tx_.frame.sof, sizeof(tx_.frame.sof));
    tx_.pack_size = sizeof(tx_.frame.sof);

    // pack id
    tx_.frame.pack_id = (uint8_t)msg_stream + (uint8_t)msg_type;
    memcpy(tx_.buf + tx_.pack_size, &tx_.frame.pack_id, sizeof(tx_.frame.pack_id));
    tx_.pack_size += sizeof(tx_.frame.pack_id);

    // data
    if (msg_stream == MiniPCCommMsgStream::PC2BOARD) {
        if (msg_type == MiniPCCommMsgType::GENERAL) {
            appendTxData(general_pc2board_msg_);
        } else if (msg_type == MiniPCCommMsgType::AIM_SHOOT) {
            appendTxData(aim_shoot_pc2board_msg_);
        } else if (msg_type == MiniPCCommMsgType::NAVIGATION) {
            appendTxData(navigation_pc2board_msg_);
        } else if (msg_type == MiniPCCommMsgType::GAME_STATUS) {
            appendTxData(game_status_pc2board_msg_);
        }
    } else if (msg_stream == MiniPCCommMsgStream::BOARD2PC) {
        if (msg_type == MiniPCCommMsgType::GENERAL) {
            appendTxData(general_board2pc_msg_);
        } else if (msg_type == MiniPCCommMsgType::AIM_SHOOT) {
            appendTxData(aim_shoot_board2pc_msg_);
        } else if (msg_type == MiniPCCommMsgType::NAVIGATION) {
            appendTxData(navigation_board2pc_msg_);
        } else if (msg_type == MiniPCCommMsgType::GAME_STATUS) {
            appendTxData(game_status_board2pc_msg_);
        }
    }

    // tail(crc16)
    tx_.pack_size += sizeof(tx_.frame.crc16);
    CRC16_Append(tx_.buf, tx_.pack_size);
}

// Data receive callback 接收中断
void MiniPCComm::rxCallback(void) {
#ifdef DETAIL_LOGGER
    // logger_on_ = true;
    if (unpack_step_ == WAIT && logger_on_) {
        RCLCPP_INFO(logger, "CallbackStatus ideal: WAIT. Logger Switch: %u", (uint8_t)logger_on_);
    }
    // logger_on_ = false;
#endif

    // 将接收到的1byte数据存入fifo缓冲区
    rx_.fifo.append(rx_.byte, 1); // what is this? it should be sof else the upack will not start

    // 数据解包
    // 等待阶段
    if (unpack_step_ == WAIT) {
        uint32_t sof_index = rx_.fifo.find(minipc_comm_sof);
        if (sof_index != rx_.fifo.size()) { // 若相等，说明找到队未也没有找到
            // 检测到SOF标志，清除缓冲区无效数据，进入id阶段
            rx_.fifo.remove(sof_index);
            rx_.expect_size = sizeof(rx_.frame.sof) + sizeof(rx_.frame.pack_id);
            unpack_step_ = PACK_ID;
            // detail logger--唯一开启位置
            if (logger_cnt % info_freq == 0) {
                logger_on_ = true;
            }
        } else {
            // 未检测到SOF标志，清空缓冲区
            rx_.fifo.clear();
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
            RCLCPP_WARN(
                logger,
                "================\n[WARNING FAILED TO DETECT SOF. CLEARING BUFFER.\n======================"
            );
            logger_on_ = false;
#endif
        }
    }
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(logger, "\n==============\nStarting Rxcallback.\nRxcalling: Pass Step Wait.");
    }
#endif

    // id阶段
    if (unpack_step_ == PACK_ID) {
        if (rx_.fifo.size() >= rx_.expect_size) {
            // 进入data_len阶段
            memcpy(&rx_.frame.pack_id, rx_.buf + sizeof(rx_.frame.sof), sizeof(rx_.frame.pack_id));
            rx_.expect_size += sizeof(rx_.frame.data_len);
            unpack_step_ = DATA_LEN;
        } else {
            logger_on_ = false;
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
            RCLCPP_WARN(logger, "[ERROR] PACK_ID STEP FALIED.");
#endif
        }
    }
// logger_on_==true == unpack_step_==PACK_ID
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(logger, "Rxcalling: Pass Step Pack_Id.");
    }
#endif

    // data_len阶段，设置data段需接收的数据长度
    if (unpack_step_ == DATA_LEN) {
        if (rx_.fifo.size() >= rx_.expect_size) {
            // 进入data阶段
            memcpy(
                &rx_.frame.data_len,
                rx_.buf + sizeof(rx_.frame.sof) + sizeof(rx_.frame.pack_id),
                sizeof(rx_.frame.data_len)
            );
            rx_.expect_size += rx_.frame.data_len;
            if (rx_.expect_size > rx_.fifo.maxSize()) {
                // 数据长度错误
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
                RCLCPP_WARN(logger, "[ERROR] DATA_LEN EXAMING FAILED.");
                logger_on_ = false;
#endif
                rx_.fifo.clear();
                unpack_error_ = DATA_LEN_OUTRANGE;
                errorHandler(DATA_LEN_OUTRANGE);
                unpack_step_ = WAIT;
            } else {
                unpack_step_ = DATA;
            }
        }
    }
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(logger, "Rxcalling: Pass Step Data_Len.");
    }
#endif

    // data阶段，接收数据量足够后进入帧尾校验阶段
    if (unpack_step_ == DATA) {
        if (rx_.fifo.size() >= rx_.expect_size) {
            // 进入tail阶段
            rx_.expect_size += sizeof(rx_.frame.crc16);
            unpack_step_ = CRC16;
        } else {
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
            RCLCPP_WARN(logger, "[ERROR] DATA STEP FALIED.");
            logger_on_ = false;
#endif
        }
    }
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(logger, "Rxcalling: Pass Step Data.");
    }
#endif

    // 帧尾CRC16校验阶段，接收完帧尾后进行校验
    if (unpack_step_ == CRC16) {
        if (rx_.fifo.size() >= rx_.expect_size) {
            rx_.frame.crc16 = CRC16_Calc(rx_.buf, rx_.expect_size);
            if (CRC16_Verify(rx_.buf, rx_.expect_size)) {
                // CRC校验成功
                unpack_step_ = READ_DATA;
            } else {
                // CRC校验失败
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
                RCLCPP_WARN(logger, "[ERROR] CRC16 FAILED.");
                logger_on_ = false;
#endif
                rx_.fifo.clear();
                unpack_error_ = CRC_FAIL;
                errorHandler(CRC_FAIL);
                unpack_step_ = WAIT;
            }
        }
    }
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(logger, "Rxcalling: Pass Step CRC16. Entering Step Read_Data.");
    }
#endif

    // read_data阶段，从缓冲区读取数据
    if (unpack_step_ == READ_DATA) {
        const static uint8_t offset =
            sizeof(rx_.frame.sof) + sizeof(rx_.frame.pack_id) + sizeof(rx_.frame.data_len); // =3
        if ((rx_.frame.pack_id & 0xf0) == (uint8_t)MiniPCCommMsgStream::PC2BOARD) {
            unpack_error_ = NO_ERROR;
            if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::GENERAL) {
                memcpy(&general_pc2board_msg_, rx_.buf + offset, rx_.frame.data_len);
                general_connect_.refresh();
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::AIM_SHOOT) {
                memcpy(&aim_shoot_pc2board_msg_, rx_.buf + offset, rx_.frame.data_len);
                aim_shoot_connect_.refresh(); // Not needed for analog
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::NAVIGATION) {
                memcpy(&navigation_pc2board_msg_, rx_.buf + offset, rx_.frame.data_len);
                navigation_connect_.refresh();
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::GAME_STATUS) {
                memcpy(&game_status_pc2board_msg_, rx_.buf + offset, rx_.frame.data_len);
                game_status_connect_.refresh();
            } else {
                unpack_error_ = ID_UNDEFINED; // 未定义id
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
                RCLCPP_WARN(logger, "[ERROR] UNPACK ERROR: ID_UNDEFINED.\n");
#endif
                errorHandler(ID_UNDEFINED);
            }
        } else if ((rx_.frame.pack_id & 0xf0) == (uint8_t)MiniPCCommMsgStream::BOARD2PC) {
            unpack_error_ = NO_ERROR;
            if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::GENERAL) {
                memcpy(&general_board2pc_msg_, rx_.buf + offset, rx_.frame.data_len);
                general_connect_.refresh();
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::AIM_SHOOT) {
                memcpy(&aim_shoot_board2pc_msg_, rx_.buf + offset, rx_.frame.data_len);
                aim_shoot_connect_.refresh();
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::NAVIGATION) {
                memcpy(&navigation_board2pc_msg_, rx_.buf + offset, rx_.frame.data_len);
                navigation_connect_.refresh();
            } else if ((rx_.frame.pack_id & 0x0f) == (uint8_t)MiniPCCommMsgType::GAME_STATUS) {
                memcpy(&game_status_board2pc_msg_, rx_.buf + offset, rx_.frame.data_len);
                game_status_connect_.refresh();
            } else {
                unpack_error_ = ID_UNDEFINED; // 未定义id
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
                RCLCPP_WARN(logger, "[ERROR] UNPACK ERROR: ID_UNDEFINED.\n");
#endif
                errorHandler(ID_UNDEFINED);
            }
        }
        if (unpack_error_ == NO_ERROR) {
#ifdef DETAIL_LOGGER
            if (logger_on_) {
                RCLCPP_INFO(
                    logger,
                    "No Error occurred. Pass Step Read_Data. Rxcalling back Finished.\n-------"
                );
            }
#endif
#ifdef FINAL_OUTCOME
            RCLCPP_INFO(
                logger,
                "CALLBACK SUCCESSED. PACK ATTRIBUTE: %u , DIRECTION: %u .",
                (uint8_t)(rx_.frame.pack_id & 0x0f),
                (uint8_t)(rx_.frame.pack_id & 0xf0)
            ); // direction 16是1111,为正常方向
#endif
            continus_error_cnt = 0;
        } else {
#if defined(DETAIL_LOGGER) || defined(WARNING_OUTPUT)
            RCLCPP_WARN(
                logger,
                "[ERROR} Pass Step Read_Data. But errors occurred. Rxcalling back Finished."
            );
#endif
        }

        rx_.fifo.remove(rx_.expect_size); // 从缓冲区移除该帧数据
        unpack_step_ = WAIT; // 重置解包状态
    }
#ifdef DETAIL_LOGGER
    if (logger_on_) {
        RCLCPP_INFO(
            logger,
            "RxCallback Finished. total error: %d, logger_cnt: %lld , logger_on: %d, \nexiting rxcallback.\n== == == == == == == == ",
            continus_error_cnt,
            logger_cnt,
            (int)logger_on_
        );
        logger_cnt++; // 一次成功的完整输出
    }
#endif
}
