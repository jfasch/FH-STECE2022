#pragma once
#include "sysfs-pwm-pin.h"
#include <fstream>

class servo
{
public:
    servo(SysFSPWMPin PWMpin) 
    : _pwm(PWMpin)
    {}

    void set_position(int);

private:
    const SysFSPWMPin _pwm;
    const uint64_t _duty_cycle_mid;
    const uint64_t _duty_cycle_max;
    const uint64_t _duty_cycle_min;
};
