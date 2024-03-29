# 自瞄数据包(电控->视觉) id-0x11
# yaw左+右-，pitch下+上-(ZYX欧拉角，右手定则)
uint8 self_id # 用于判断红蓝方

float32 yaw_angle # deg

float32 pitch_angle # deg

float32 yaw_speed # dps

float32 pitch_speed # dps

float32 yaw_offset # deg，电控yaw补偿

float32 pitch_offset # deg，电控pitch补偿

float32 dist # m,电控测量距离

float32 shoot_speed # m/s，射速

uint8 shoot_delay # ms，发射延时

uint32 shoot_id_fdb # 发射id反馈(=对应的shoot_id)

uint8 is_big_energy # 0-小符，1-大符

float32 chassis_vx # m/s，底盘前后速度，前+后-，用于预测和发射判断

float32 chassis_vy # m/s，底盘前后速度，前+后-，用于预测和发射判断