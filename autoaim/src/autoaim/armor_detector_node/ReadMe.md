# armor_detector节点

## 该节点包含的topic
|type|name|data_struct|description|
|-------|-------|-------|------|
|subscription|image_raw|sensor_msgs::msg::Image||
|subscription|imu_data|sensor_msgs::msg::Imu||
|publisher|detection|aimer::DetectionResult|detection result|