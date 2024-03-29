#include "Stm32Shoot.hpp"

Stm32Shoot::Stm32Shoot(const param::ParamVisitor & param_visitor): param_visitor_(std::move(param_visitor)) {}

/**@class Stm32Shoot **/
auto Stm32Shoot::add(const int& id, const double& img_t) -> void {
    // 时间超过 t + latency 后可以发射
    if (this->pending_signals.size() + 1 <= Stm32Shoot::MAX_SZ) {
        this->pending_signals.push_back(Stm32Shoot::IdT { id, img_t });
    }
}

auto Stm32Shoot::get_last_shoot_id(const double& img_t) -> int {
    // 实际上是传输过去有延迟，
    while (!this->pending_signals.empty()
           && img_t >= this->pending_signals.front().img_t + Stm32Shoot::SHOOT_LATENCY)
    {
        // 信号已经到达，进行信号处理
        if (this->pending_signals.front().img_t >= this->last_shoot.img_t
                + param::get_param<double>(("auto-aim.ec-simulator.shoot-interval"),param_visitor_))
        {
            this->last_shoot = this->pending_signals.front();
        }
        this->pending_signals.pop_front();
    }
    return this->last_shoot.id;
}