# 这是zzx的feature

## declare parameter
+ 在initnode时使用 this->declare_parameter()来创建参数。注意，如果这个变量在创建之前被赋过值，那么在declare时会被覆盖。在launch file中添加Node的parameters参数列表，以数组传入，每一个param是以词典类型储存在数组中的。对于需要频繁修改的量应当用parameter传入。declare之后要get！
+ ROS2 launchfile中传入的param只有string类型。
+ 配置参数时，使用yaml文件配置。在python的LaunchDescription中引入config文件的储存位置，然后在param参数列表中列入。注意config文件打头的是node的名字。


## Foxglove
+ run :
```txt
ros2 launch foxglove_bridge foxglove_bridge_launch.xml 
```

## Dairy
| Date       | Task         |
|------------|--------------|
|    3.26        |        解决通信问题：排查可能导致头晃动的问题：互斥锁，但是在同步通信中仍然会出现这种问题，我觉得有可能并不是通信上出的问题;现在把互斥锁上可能的问题都处理了。     |
|            |              |
|            |              |