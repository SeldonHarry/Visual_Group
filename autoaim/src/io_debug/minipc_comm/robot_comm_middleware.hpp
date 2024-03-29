#ifndef ROBOT_COMM_MIDDLEWARE_HPP
#define ROBOT_COMM_MIDDLEWARE_HPP

#include <memory>

#include "minipc_comm.hpp" 
#include "robot.hpp"

void robotCmdConvert(std::shared_ptr<MiniPCComm> comm, const RobotCmd& cmd);

// 暂时只先用后者，前者在我们的node里是subscribe的存在
// 在这个函数里同时应当实现ros的msg的赋值
void robotStatusConvert(std::shared_ptr<MiniPCComm> comm, std::shared_ptr<RobotStatus> status);

#endif // ROBOT_COMM_MIDDLEWARE_HPP
