# Shoot_Mode
uint8 TRACKING=0

uint8 SHOOT_NOW=1

uint8 IDLE=2

# start起始位，不要把数据放到起始位前面
uint8 start

uint8 seq_id # 丢包率测试

int32 aim_id

uint16 car_id

uint16 detection_info

float32 yaw

float32 pitch

float32 yaw_v

float32 pithc_v

float32 dist

uint8 shoot # SHOOT_MODE

uint16 period # 2021反陀螺的延时发射要求

# lrc校验位，不要把数据放在lrc位后面
uint8 lrc

bool lock_yaw

uint8 end


