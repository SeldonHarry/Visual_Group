#

## 注意
这是之后在minipc上传输的数据包的msg类型定义pkg。在修改时一定注意msg变量的命名规则（按编译器报错修改就好）。

## 内容
+ PCWorkMode是MINIPC工作状态的定义类型
+ DPackIdentifier是数据包的识别符

##
- 这些信息只有RobotCmd和RobotStatus会在minipc上传递，通过umt通信和robot_comm_middleware.cpp指定
- 但是一些变量的初始化怎么处理？