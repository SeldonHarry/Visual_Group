#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP
#include "cv_drawer.hpp"
#include "my_interfaces/srv/debug_info.hpp"
#include "param/param.hpp"
#include "rclcpp/rclcpp.hpp"
#include <cv_bridge/cv_bridge.h>
#include <fmt/color.h>
#include <queue>
#include <rclcpp/client.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/timer.hpp>
#include <string>

namespace ros2addon::debug {
class ProcessTimer {
public:
    void process_begin();
    void print_process_time(const char* str) const;
    double get_process_time() const;

private:
    std::chrono::microseconds begin_time;
};

struct StartEndTime {
    std::string start;
    std::string end;
    std::chrono::microseconds::rep time;
};

class RegisterTimer {
public:
    auto get_and_register(const std::string& stamp_name) -> StartEndTime {
        debug::StartEndTime res;
        std::chrono::microseconds cur = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch());
        res.start = this->cur_name;
        res.end = stamp_name;
        res.time = cur.count() - this->cur_time.count();
        this->cur_time = cur;
        this->cur_name = stamp_name;
        return res;
    }

private:
    std::string cur_name;
    std::chrono::microseconds cur_time;
};

class Debugger: public RegisterTimer, public ProcessTimer, public CvDrawer {
public:
    enum class LogLevel { INFO, WARNING, ERROR, FATAL };
    explicit Debugger(const rclcpp::Node::SharedPtr ros_node,
                      const param::ParamVisitor& param_visitor);
    void send_to_webpage(const std::string& key, const std::string& value);
    void print_duration(const std::string& name);

    template<typename... Args>
    void print_on_screen(LogLevel log_level, const std::string& content, const Args&... args);
    template<typename T>
    std::string vec_to_str(const std::vector<T>& vec) {
        std::string str = "[";
        for (const auto& ele: vec) {
            str += fmt::format("{}", ele);
            if (&ele != &vec.back()) {
                str += ", ";
            }
        }
        str += "]";
        return str;
    }

    FlaskStream flask_aim;
    FlaskStream flask_map;

private:
    rclcpp::Node::SharedPtr ros_node_;
    rclcpp::Client<my_interfaces::srv::DebugInfo>::SharedPtr client_;
};

template<typename ValueT, typename PeriodT>
class PeriodicRecorder {
public:
    PeriodicRecorder(const std::function<bool(const ValueT&, const ValueT&)>& cmp,
                     const PeriodT& init_stamp):
        cmp(cmp),
        stamp(init_stamp) {}
    void update(const ValueT& value, const PeriodT& stamp, const PeriodT& period) {
        if (stamp - this->stamp >= period) {
            // 本帧超时则本帧不计入
            this->last_record = this->record;
            this->record = value;
            this->stamp = stamp;
        } else {
            if (this->cmp(this->record, value)) {
                this->record = value;
            }
        }
    }
    ValueT get() const {
        return this->last_record;
    }

private:
    std::function<bool(const ValueT&, const ValueT&)> cmp;
    ValueT last_record = ValueT();
    ValueT record = ValueT();
    PeriodT stamp;
};

template<typename ValueT, typename PeriodT>
class PeriodicAverage {
public:
    PeriodicAverage(const std::size_t& buf_size, const PeriodT& init_stamp):
        buf_size(buf_size),
        stamp(init_stamp) {}

    void update(const ValueT& value, const PeriodT& stamp, const PeriodT& period) {
        if (stamp - this->stamp >= period) {
            this->last_period_ave = this->data.empty() ? ValueT() : ([&]() {
                std::size_t size = this->data.size();
                ValueT tot = this->data.front();
                this->data.pop();
                while (!this->data.empty()) {
                    tot += this->data.front();
                    this->data.pop();
                }
                return tot * (1. / double(size));
            }());
            this->stamp = stamp;
        }
        if (this->data.size() + 1u > this->buf_size && !this->data.empty()) {
            this->data.pop();
        }
        if (this->data.size() + 1u <= this->buf_size) {
            this->data.push(value);
        }
    }

    ValueT get() const {
        return this->last_period_ave;
    }

private:
    const std::size_t buf_size;
    ValueT last_period_ave = ValueT();
    std::queue<ValueT> data;
    PeriodT stamp;
};
} // namespace ros2addon::debug
#endif