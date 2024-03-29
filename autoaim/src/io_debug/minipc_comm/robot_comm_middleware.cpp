#include "robot_comm_middleware.hpp"
#include <memory>
// 由于开发时打算弃用umt库所以使用shared_ptr类型来处理

// 旧版协议RobotCmd转换为新版协议中数据，按新版通信协议发送
void robotCmdConvert(std::shared_ptr<MiniPCComm> comm, const RobotCmd& cmd) {
    // 自瞄数据转换
    comm->aim_shoot_pc2board_msg_.yaw_angle = cmd.yaw;
    comm->aim_shoot_pc2board_msg_.pitch_angle = -cmd.pitch;
    comm->aim_shoot_pc2board_msg_.yaw_speed = cmd.yaw_v;
    comm->aim_shoot_pc2board_msg_.pitch_speed = -cmd.pitch_v;
    comm->aim_shoot_pc2board_msg_.dist = cmd.dist;
    comm->aim_shoot_pc2board_msg_.enemy_id = cmd.car_id;
    comm->aim_shoot_pc2board_msg_.shoot_flag = (uint8_t)cmd.shoot;
    comm->aim_shoot_pc2board_msg_.shoot_id = (uint32_t)cmd.aim_id;
    // 导航数据转换（todo）
    return;
} //这是minipc节点subscriber需要收到的数据

void robotStatusConvert(std::shared_ptr<MiniPCComm> comm, std::shared_ptr<RobotStatus> status) {
    // mode (general)
    // 这里需要加入check修改
    if (comm->general_connect_.check()) {
        MiniPCMode mode = (MiniPCMode)comm->general_board2pc_msg_.mode; // 前提是comm
        if (mode == MiniPCMode::IDLE) {
            status->program_mode = ProgramMode::NOT_RECEIVED;
        } else if (mode == MiniPCMode::AUTOAIM) {
            status->program_mode = ProgramMode::AUTOAIM;
        } else if (mode == MiniPCMode::ENERGY) {
            status->program_mode = ProgramMode::ENERGY_HIT;
        } else if (mode == MiniPCMode::ENERGY_DISTURB) {
            status->program_mode = ProgramMode::ENERGY_DISTURB;
        } else if (mode == MiniPCMode::NAVIGATION) {
            status->program_mode = ProgramMode::AUTOAIM; //todo
        } else if (mode == MiniPCMode::DECISION) {
            status->program_mode = ProgramMode::AUTOAIM; //todo
        }
    }

    // shoot & aim
    status->bullet_speed = comm->aim_shoot_board2pc_msg_.shoot_speed;
    status->yaw_compensate = comm->aim_shoot_board2pc_msg_.yaw_offset;
    status->pitch_compensate = comm->aim_shoot_board2pc_msg_.pitch_offset;
    if (comm->aim_shoot_board2pc_msg_.self_id < 100) {
        status->enemy_color = EnemyColor::BLUE;
    } else {
        status->enemy_color = EnemyColor::RED;
    }
    status->is_big_energy = comm->aim_shoot_board2pc_msg_.is_big_energy;
    status->latency_cmd_to_fire = comm->aim_shoot_board2pc_msg_.shoot_delay;
    status->last_shoot_aim_id = comm->aim_shoot_board2pc_msg_.shoot_id_fdb;
    status->laser_distance = comm->aim_shoot_board2pc_msg_.dist;

    return;
} // 这是
