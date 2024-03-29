//
// Created by xinyang on 2021/3/3.
//

#include "ExtImu.hpp"

void ExtImu::stop_trigger() {
    idle_var = 0;
    int32_t ch = 0;
    Serial::write((uint8_t *) &ch, 4);
}

void ExtImu::once_trigger(int32_t delay_ms) {
    idle_var = 1;
    if (delay_ms < 0) throw std::logic_error("ExtImu::once_trigger() assert failed: 'delay_ms >= 0'");
    delay_ms = -(delay_ms + 1);
    Serial::write((uint8_t *) &delay_ms, 4);
}

void ExtImu::periodic_trigger(int32_t period_ms) {
    idle_var = 2;
    if (period_ms <= 0) throw std::logic_error("ExtImu::periodic_trigger() assert failed: 'period_ms > 0'");
    Serial::write((uint8_t *) &period_ms, 4);
}

void ExtImu::read_sensor(SensorData *p_data) {
    idle_var = 3;
    Serial::read((uint8_t *) p_data, sizeof(SensorData));
}