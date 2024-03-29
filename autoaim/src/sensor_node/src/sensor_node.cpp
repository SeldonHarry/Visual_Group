#include "sensor_node.hpp"
#include "MvCameraControl.h"
#include <chrono>
#include <rcl_interfaces/msg/detail/parameter_type__struct.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/utilities.hpp>
#include <string>
#include <thread>

sensor::SensorNode::SensorNode(const rclcpp::NodeOptions& options): Node("sensor", options) {
    init_cam_device();
    load_cam_info();
    init_cam_param();
    init_imu_device();
    init_node();
    //注册该节点的参数回调函数，注意参数回调函数必须在所有参数都声明完之后注册！！！要不然声明参数报错！！！
    params_callback_handle_ =
        this->add_on_set_parameters_callback([this](const std::vector<rclcpp::Parameter>& params) {
            return parameters_callback(params);
        });
    //注意：imu应在相机启动前启动，因为相机要接收到imu的触发信号后才会记录帧！
    start_imu();
    start_camera();
}

void sensor::SensorNode::init_cam_device() {
    RCLCPP_INFO(this->get_logger(), "Starting initiating hik camera!");

    //枚举相机设备并打印数量
    MV_CC_DEVICE_INFO_LIST device_list;
    nRet = MV_CC_EnumDevices(MV_USB_DEVICE, &device_list);
    RCLCPP_INFO(this->get_logger(), "Found camera count = %d", device_list.nDeviceNum);

    //找不到相机的话，每隔1s试着重新获取一次
    while (device_list.nDeviceNum == 0 && rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "No camera found!");
        RCLCPP_INFO(this->get_logger(), "Enum state: [%x]", nRet);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        nRet = MV_CC_EnumDevices(MV_USB_DEVICE, &device_list);
    }

    //使用设备中的第一个相机创建相机句柄
    MV_CC_CreateHandle(&camera_handle_, device_list.pDeviceInfo[0]);
    MV_CC_OpenDevice(camera_handle_); //打开相机句柄
    MV_CC_GetImageInfo(camera_handle_, &img_info_); //获取相机信息
}

void sensor::SensorNode::init_imu_device() {
    RCLCPP_INFO(this->get_logger(), "Starting initiating imu device!");
    std::string imu_usb_hid;
    this->declare_parameter("imu_usb_hid", "USB VID:PID=0483:5740 SNR=35A4337F3237");
    this->get_parameter("imu_usb_hid", imu_usb_hid);
    for (const auto& port_info: serial::list_ports()) {
        std::cerr << "hardware_id: " << port_info.hardware_id << ", port: " << port_info.port
                  << std::endl;
        if (port_info.hardware_id == imu_usb_hid) {
            std::cerr << "imu found!  "
                      << "hardware_id: " << port_info.hardware_id << ", port: " << port_info.port
                      << std::endl;
            imu.setPort(port_info.port);
            auto timeout = serial::Timeout::simpleTimeout(serial::Timeout::max());
            break;
        }
    }
    imu.open();
    if (!imu.isOpen()) {
        RCLCPP_ERROR(this->get_logger(), "imu init failed!");
    } else {
        RCLCPP_INFO(this->get_logger(), "imu init successfully!");
    }
}

void sensor::SensorNode::init_node() {
    image_msg_.data.reserve(img_info_.nHeightMax * img_info_.nWidthMax * 3); //为data分配空间

    bool use_sensor_data_qos;
    this->get_parameter("use_sensor_data_qos", use_sensor_data_qos);
    auto qos = use_sensor_data_qos ? rmw_qos_profile_sensor_data
                                   : rmw_qos_profile_default; //set data qos method
    camera_pub_ =
        image_transport::create_camera_publisher(this,
                                                 "image_raw",
                                                 qos); //create camera image_raw topic publisher
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("imu_data", 10);

    cam_interval = 0;
    this->declare_parameter("interval", cam_interval);
    this->get_parameter("interval", cam_interval);
}

void sensor::SensorNode::init_cam_param() {
    // Init convert param
    convert_param_.nWidth = img_info_.nWidthValue;
    convert_param_.nHeight = img_info_.nHeightValue;
    convert_param_.enDstPixelType = PixelType_Gvsp_RGB8_Packed;

    rcl_interfaces::msg::ParameterDescriptor param_desc;
    MVCC_FLOATVALUE f_value;
    param_desc.integer_range.resize(1);
    param_desc.integer_range[0].step = 1;
    // Set exposure time from param file
    param_desc.description = "Exposure time in microseconds";
    MV_CC_GetFloatValue(camera_handle_, "ExposureTime", &f_value);
    param_desc.integer_range[0].from_value = f_value.fMin;
    param_desc.integer_range[0].to_value = f_value.fMax;
    int exposure_time;
    this->declare_parameter("exposure_time", 5000);
    this->get_parameter("exposure_time", exposure_time);
    MV_CC_SetFloatValue(camera_handle_, "ExposureTime", exposure_time);
    RCLCPP_INFO(this->get_logger(), "Exposure time: %d", exposure_time);

    // Set gain from param file
    param_desc.description = "Gain";
    MV_CC_GetFloatValue(camera_handle_, "Gain", &f_value);
    param_desc.integer_range[0].from_value = f_value.fMin;
    param_desc.integer_range[0].to_value = f_value.fMax;
    double gain;
    this->declare_parameter("gain", 32.0);
    this->get_parameter("gain", gain);
    MV_CC_SetFloatValue(camera_handle_, "Gain", gain);
    RCLCPP_INFO(this->get_logger(), "Gain: %f", gain);

    //Set camera feature from mfs file
    nRet = MV_CC_FeatureLoad(camera_handle_, camera_cfg_name_.c_str());
    if (MV_OK != nRet) {
        RCLCPP_WARN(this->get_logger(),
                    "fail to load camera configuration file: %s, nRet: [%x]",
                    camera_cfg_name_.c_str(),
                    nRet);
    }

    // use bilinearity bayer interpolation
    nRet = MV_CC_SetBayerCvtQuality(camera_handle_, 1);
    if (MV_OK != nRet) {
        RCLCPP_WARN(this->get_logger(),
                    "fail to enable bilinearity bayer interpolation, nRet: [%x]",
                    nRet);
    }
}

rcl_interfaces::msg::SetParametersResult sensor::SensorNode::parameters_callback(
    const std::vector<rclcpp::Parameter>& parameters) //参数回调函数，有参数修改时会被触发
{
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    for (const auto& param: parameters) {
        if (param.get_name() == "exposure_time") { //modify exposure time
            int status = MV_CC_SetFloatValue(camera_handle_, "ExposureTime", param.as_int());
            RCLCPP_INFO(this->get_logger(), "Exposure time set to: %ld", param.as_int());
            if (MV_OK != status) {
                result.successful = false;
                result.reason = "Failed to set exposure time, status = " + std::to_string(status);
            }
        } else if (param.get_name() == "gain") { //modify gain
            int status = MV_CC_SetFloatValue(camera_handle_, "Gain", param.as_double());
            RCLCPP_INFO(this->get_logger(), "Exposure time set to: %f", param.as_double());
            if (MV_OK != status) {
                result.successful = false;
                result.reason = "Failed to set gain, status = " + std::to_string(status);
            }
        } else {
            result.successful = false;
            result.reason = "Unknown parameter: " + param.get_name();
        }
    }
    return result;
}

void sensor::SensorNode::load_cam_info() {
    // Load camera name
    this->declare_parameter("camera_name", "camera_right");
    this->get_parameter("camera_name", camera_name_);
    RCLCPP_INFO(this->get_logger(), "Camera Name: %s", camera_name_.c_str());

    //create camera info manager
    camera_info_manager_ =
        std::make_unique<camera_info_manager::CameraInfoManager>(this, camera_name_);

    // load camera info url
    this->declare_parameter("camera_info_url", "package://sensor/config/camera_info.yaml");
    std::string camera_info_url;
    this->get_parameter("camera_info_url", camera_info_url);
    RCLCPP_INFO(this->get_logger(), "Camera info url: %s", camera_info_url.c_str());

    // load camera info from the info yaml file
    if (camera_info_manager_->validateURL(camera_info_url)) {
        camera_info_manager_->loadCameraInfo(camera_info_url);
        camera_info_msg_ = camera_info_manager_->getCameraInfo();
    } else {
        RCLCPP_WARN(this->get_logger(), "Invalid camera info URL: %s", camera_info_url.c_str());
    }

    //load camera config file location
    this->declare_parameter("camera_config_url", "MV-CA016-10UC_00K31937955.mfs");
    this->get_parameter("camera_config_url", camera_cfg_name_);
}

void sensor::SensorNode::capture_thread_loop() {
    MV_FRAME_OUT out_frame;

    RCLCPP_INFO(this->get_logger(), "image thread started!");

    image_msg_.header.frame_id = "camera_optical_frame";
    image_msg_.encoding = "rgb8";
    auto last_t = std::chrono::system_clock::now();
    int fps;

    while (capture_run_flag_) {
        nRet = MV_CC_GetImageBuffer(camera_handle_, &out_frame, 1000);
        if (MV_OK == nRet) {
            convert_param_.pDstBuffer = image_msg_.data.data();
            convert_param_.nDstBufferSize = image_msg_.data.size();
            convert_param_.pSrcData = out_frame.pBufAddr;
            convert_param_.nSrcDataLen = out_frame.stFrameInfo.nFrameLen;
            convert_param_.enSrcPixelType = out_frame.stFrameInfo.enPixelType;

            MV_CC_ConvertPixelType(camera_handle_, &convert_param_);

            image_msg_.header.stamp = this->now();
            image_msg_.height = out_frame.stFrameInfo.nHeight;
            image_msg_.width = out_frame.stFrameInfo.nWidth;
            image_msg_.step = out_frame.stFrameInfo.nWidth * 3;
            image_msg_.data.resize(image_msg_.width * image_msg_.height * 3);

            camera_info_msg_.header = image_msg_.header;
            camera_pub_.publish(image_msg_, camera_info_msg_);

            MV_CC_FreeImageBuffer(camera_handle_, &out_frame);
            fail_conut_ = 0;
            rclcpp::sleep_for(std::chrono::milliseconds(cam_interval));
            auto t = std::chrono::system_clock::now();
            fps = 1000 / std::chrono::duration_cast<std::chrono::milliseconds>(t - last_t).count();
            last_t = t;
            RCLCPP_INFO(this->get_logger(), "publish image, current fps = %d", fps);
        } else {
            RCLCPP_WARN(this->get_logger(), "Get buffer failed! nRet: [%x]", nRet);
            MV_CC_StopGrabbing(camera_handle_);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            MV_CC_StartGrabbing(camera_handle_);
            RCLCPP_WARN(this->get_logger(), "Cam restarted! trying to get frame again...");
            fail_conut_++;
        }

        if (fail_conut_ > 5) {
            RCLCPP_FATAL(this->get_logger(), "Camera failed!");
            rclcpp::shutdown();
        }
    }
}

void sensor::SensorNode::imu_thread_loop() {
    ExtImu::SensorData sensor_data {};
    RCLCPP_INFO(this->get_logger(), "imu thread started!");
    while (imu_run_flag_) {
        imu.read_sensor(&sensor_data);
        imu_msg_.header.stamp = this->now();

        imu_msg_.orientation.x = sensor_data.q[3];
        imu_msg_.orientation.y = sensor_data.q[0];
        imu_msg_.orientation.z = sensor_data.q[1];
        imu_msg_.orientation.w = sensor_data.q[2];

        imu_msg_.angular_velocity.x = sensor_data.gyro[0];
        imu_msg_.angular_velocity.y = sensor_data.gyro[1];
        imu_msg_.angular_velocity.z = sensor_data.gyro[2];

        imu_msg_.linear_acceleration.x = sensor_data.acc[0];
        imu_msg_.linear_acceleration.y = sensor_data.acc[1];
        imu_msg_.linear_acceleration.z = sensor_data.acc[2];

        imu_pub_->publish(imu_msg_);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void sensor::SensorNode::close_camera() {
    capture_run_flag_ = false;
    if (capture_thread_.joinable()) {
        capture_thread_.join();
    }
    if (camera_handle_ != nullptr) {
        MV_CC_StopGrabbing(camera_handle_);
        MV_CC_CloseDevice(camera_handle_);
        MV_CC_DestroyHandle(&camera_handle_);
    }
    RCLCPP_INFO(this->get_logger(), "camera successfully closed!");
}

void sensor::SensorNode::close_imu() {
    imu_run_flag_ = false;
    if (capture_thread_.joinable()) {
        capture_thread_.join();
    }
    imu.stop_trigger();
    imu.close();
    RCLCPP_INFO(this->get_logger(), "imu successfully closed!");
}

void sensor::SensorNode::start_camera() {
    //相机开始抓取
    MV_CC_StartGrabbing(camera_handle_);
    capture_thread_ = std::thread(&SensorNode::capture_thread_loop, this);
}

void sensor::SensorNode::start_imu() {
    imu.periodic_trigger(sync_period_ms); //使imu进入触发模式
    //陀螺仪开始抓取
    imu_thread_ = std::thread(&SensorNode::imu_thread_loop, this);
}

sensor::SensorNode::~SensorNode() {
    close_camera();
    close_imu();
}

#include <rclcpp_components/register_node_macro.hpp> //这个头文件一定要放在最后引入，顺序不能变
//register the node to workspace
RCLCPP_COMPONENTS_REGISTER_NODE(sensor::SensorNode)