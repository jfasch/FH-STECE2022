#pragma once
#include "sysfs-pwm-pin.h"
#include <cstdint>

#define servo_max 100
#define servo_min -100

class servo
{
public:
    servo(SysFSPWMPin PWMpin, uint8_t duty_mid, uint8_t duty_min, uint8_t duty_max);

    void set_position(int position);

private:
    SysFSPWMPin _pwm;
    const uint64_t _duty_cycle_mid;
    const uint64_t _duty_cycle_min;
    const uint64_t _duty_cycle_max;
};
