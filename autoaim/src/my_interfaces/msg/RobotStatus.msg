# EnemyColor
uint8 BLUE=0

uint8 RED=1
# ProgramMode
uint8 MANUAL=0

uint8 AUTOAIM=1

uint8 ANTITOP=2

uint8 ENERGY_HIT=4

uint8 ENERGY_DISTURB=5

uint8 NOT_RECEIVED=8
# parameters
float32 bullet_speed

float32 yaw_compensate # offset 4

float32 pitch_compensate # offset 8

uint8 enemy_color

uint8 is_big_energy

uint8 program_mode

uint8 latency_cmd_to_fire

int32 last_shoot_aim_id

float32 laser_distance
# lrc校验位
uint8 lrc
# 不要把数据放到lrc位后面