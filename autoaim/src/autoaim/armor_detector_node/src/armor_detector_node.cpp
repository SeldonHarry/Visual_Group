#include "armor_detector_node.hpp"
#include "defs.hpp"
#include "type_convert.hpp"
#include <chrono>
#include <cv_bridge/cv_bridge.h>
#include <eigen3/Eigen/Core>
#include <functional>
#include <image_transport/image_transport.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node_options.hpp>
#include <rclcpp/utilities.hpp>

detector::DetectorNode::DetectorNode(const rclcpp::NodeOptions& options):
    Node("armor_detector", options) {
    RCLCPP_INFO(this->get_logger(), "starting detector node");
    module = std::make_shared<TRTModule>(Attributes { 4, 4, 9, thres_partiel },
                                         "model/best_trt_with_new_sentry_ver_2.onnx");
    RCLCPP_INFO(this->get_logger(), "TRTModule create successfully");
    cam_sub_ = image_transport::create_camera_subscription(
        this,
        "image_raw",
        [this](const sensor_msgs::msg::Image::ConstSharedPtr& image,
               const sensor_msgs::msg::CameraInfo::ConstSharedPtr& cam_info) {
            this->img_frame = cv_bridge::toCvShare(image, "bgr8")->image;
            this->detected_frame_.img = *image;
            run_detector_once();
        },
        "raw");
    RCLCPP_INFO(this->get_logger(), "create image subscription successfully!");
    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "imu_data",
        10,
        [this](const sensor_msgs::msg::Imu::ConstSharedPtr imu_data) {
            this->detected_frame_.q = imu_data->orientation;
        });
    RCLCPP_INFO(this->get_logger(), "create imu data subscription successfully!");
    detect_pub_ = this->create_publisher<my_interfaces::msg::DetectionResult>("detection", 10);
    RCLCPP_INFO(this->get_logger(), "create detection result publisher successfully!");
    robot_status_sub_ = this->create_subscription<my_interfaces::msg::RobotStatus>(
        "minipc_topic",
        10,
        [this](const my_interfaces::msg::RobotStatus::ConstSharedPtr rbt_status_msg) {
            this->ros_msg_to_robot_status(this->robot_status_, rbt_status_msg);
        });
    t1 = std::chrono::system_clock::now();
    RCLCPP_INFO(this->get_logger(), "detector node init finished!");
}

void detector::DetectorNode::run_detector_once() {
    if (robot_status_.program_mode == ProgramMode::ENERGY_HIT
        || robot_status_.program_mode == ProgramMode::ENERGY_DISTURB)
    {
        // 如果不在自瞄模式则不运行网络
        RCLCPP_INFO(this->get_logger(), "detector thread loop sleep!");
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        return;
    }
    if (img_frame.empty()) {
        RCLCPP_WARN(this->get_logger(), "image is empty!");
        rclcpp::sleep_for(std::chrono::milliseconds(200));
        return;
    }
    std::vector<bbox_t> result = (*module)(img_frame);
    last_outputs = result;
    for (const auto& output: result) {
        cv::Point2f pts[4] = {
            output.pts[0],
            output.pts[1],
            output.pts[2],
            output.pts[3],
        };
        my_interfaces::msg::DetectedArmor a_tmp;
        cv_point2f_to_ros_point32(a_tmp.pts[0], pts[0]);
        cv_point2f_to_ros_point32(a_tmp.pts[1], pts[1]);
        cv_point2f_to_ros_point32(a_tmp.pts[2], pts[2]);
        cv_point2f_to_ros_point32(a_tmp.pts[3], pts[3]);
        a_tmp.color = output.color_id;
        a_tmp.number = output.tag_id == 8 ? 6 : output.tag_id;
        // 归并前哨站和水晶小板
        a_tmp.conf = output.confidence;
        a_tmp.conf_class = output.confidence_cls;
        detected_armor_.emplace_back(a_tmp);
    }
    // 根据装甲板大小进行sort
    sort(detected_armor_.begin(),
            detected_armor_.end(),
            [this](my_interfaces::msg::DetectedArmor a1, my_interfaces::msg::DetectedArmor a2) {
                return cmp_armor_center(a1, a2);
            });

    // TODO: 从多个装甲板中选取目标

    // 存储上一次识别的装甲板结果
    //last_armors = armors;
    fps_count++;
    auto t2 = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() >= 1000) {
        fps = fps_count;
        fps_count = 0;
        t1 = t2;
        RCLCPP_INFO(this->get_logger(), "detect frame successfully! fps: %d, armor num: %d",fps,detected_armor_.size());
    }
    detected_frame_.armors = detected_armor_;
    detect_pub_->publish(detected_frame_);
    detected_armor_.clear();
}

// 根据离装甲板中心距离确定
bool detector::DetectorNode::cmp_armor_center(my_interfaces::msg::DetectedArmor a1,
                                              my_interfaces::msg::DetectedArmor a2) {
    cv::Point2d center = { 640, 384 };
    cv::Point2d center1 = { (a1.pts[0].x + a1.pts[1].x + a1.pts[2].x + a1.pts[3].x) / 4.f,
                            (a1.pts[0].y + a1.pts[1].y + a1.pts[2].y + a1.pts[3].y) / 4.f };
    cv::Point2d center2 = { (a2.pts[0].x + a2.pts[1].x + a2.pts[2].x + a2.pts[3].x) / 4.f,
                            (a2.pts[0].y + a2.pts[1].y + a2.pts[2].y + a2.pts[3].y) / 4.f };
    auto dist1 = sqrt(pow(center1.x - center.x, 2) + pow(center1.y - center.y, 2));
    auto dist2 = sqrt(pow(center2.x - center.x, 2) + pow(center2.y - center.y, 2));
    if (dist1 < dist2) {
        return true;
    } else {
        return false;
    }
}

detector::DetectorNode::~DetectorNode() = default;

#include <rclcpp_components/register_node_macro.hpp> //这个头文件一定要放在最后引入，顺序不能变
//register the node to workspace
RCLCPP_COMPONENTS_REGISTER_NODE(detector::DetectorNode)