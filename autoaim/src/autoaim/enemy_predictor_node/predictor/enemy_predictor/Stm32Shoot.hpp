#include <deque>
#include <chrono>
#include "param/param.hpp"

/// @class BulletId 注意是 debug
// 想要实现的功能：模拟子弹的序号
// 几乎每一帧都会有信号
// 电控每一帧能更新的就是最近一发发出子弹的 id
// 我在镜头静止时，只能模拟的是每一发子弹都发射出去
// 视频帧率为二十几帧，不允许每发都发射
// 你给我所有 aim 的 id 和 t，访问时我直接给你最近一个子弹
class Stm32Shoot {
public:
    explicit Stm32Shoot(const param::ParamVisitor & param_visitor);
    auto add(const int& id, const double& img_t) -> void;
    auto get_last_shoot_id(const double& img_t) -> int;

private:
    struct IdT {
        int id;
        double img_t;
    };
    std::deque<IdT> pending_signals;
    IdT last_shoot { 0, 0. };
    static constexpr std::size_t MAX_SZ = 100u;
    static constexpr double SHOOT_LATENCY = 60e-3;
    param::ParamVisitor param_visitor_;
};