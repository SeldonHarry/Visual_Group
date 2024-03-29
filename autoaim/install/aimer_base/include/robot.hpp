//
// Created by xinyang on 2021/3/7.
//
// ver. 22-11-13

#ifndef CORE_IO_ROBOT_HPP
#define CORE_IO_ROBOT_HPP

#include <cstdint>

enum class ArmorColor : uint8_t {
    BLUE = 0,
    RED = 1,
    GRAY = 2,
    PURPLE = 3,
};

enum class EnemyColor : uint8_t {
    BLUE = 0,
    RED = 1,
};

enum class ProgramMode : uint8_t {
    MANUAL = 0,
    AUTOAIM = 1,
    ANTITOP = 2,
    ENERGY_HIT = 4,
    ENERGY_DISTURB = 5,
    NOT_RECEIVED = 8,
};

enum class ShootMode : uint8_t {
    TRACKING = 0,
    SHOOT_NOW = 1,
    IDLE = 2, // 空闲状态
};

struct __attribute__((packed)) RobotStatus {
    float bullet_speed = 12.345678f;
    float yaw_compensate = 1.f;
    float pitch_compensate = -1.f;
    // 此处分配 1 位，所以仅能表示 0 或 1
    ::EnemyColor enemy_color : 1 = ::EnemyColor::BLUE; // 这是字节
    uint8_t is_big_energy : 1 = false;
    ::ProgramMode program_mode : 6 = ::ProgramMode::NOT_RECEIVED;
    uint8_t latency_cmd_to_fire = 40; // (ms) 电控计算得指令到开火延迟
    int last_shoot_aim_id = 0;
    float laser_distance = 0.f;
    /* !!! 不要把数据放在 lrc 校验位后面 !!! */
    uint8_t lrc = 0;
    RobotStatus() = default;
};

static_assert(sizeof(RobotStatus) != 0);

// 如果拆分协议，恶心点在于电控在不同模式下塞入相同的东西
// 而我在本地如何管理这些不同的包？
// 事实上，视觉所有线程均需要一个状态包来决定自己是否休眠
// 即使不在吊射模式，也需要给吊射线程发包
// 全局 mode？然而糟糕的是，我们无法根据 mode 决定收什么包
// 我们只能先收包

struct __attribute__((packed)) RobotCmd {
    uint8_t start = (unsigned)'s';
    /* !!! 不要把数据放在 start 起始位前面 !!! */
    uint8_t seq_id = 0; // 丢包率测试
    int aim_id = 0;
    uint16_t car_id : 4; // 正在击打的目标
    uint16_t detection_info : 12; // 识别到的序列(0-8装甲板, 9-10能量机关)
    float yaw = 0.f;
    float pitch = 0.f;
    float yaw_v = 0.f;
    float pitch_v = 0.f;
    float dist = 0.f;
    ::ShootMode shoot = ::ShootMode::TRACKING;
    uint16_t period = 0; // 2021 版反陀螺的延迟发射要求
    /* !!! 不要把数据放在 lrc 校验位后面 !!! */
    uint8_t lrc = 0;
    bool lock_yaw = false;
    uint8_t end = (unsigned)'e';
};

// 看看大小
static_assert(sizeof(RobotCmd) != 0);

#endif // CVRM2021_ROBOT_HPP
