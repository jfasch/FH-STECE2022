#pragma once
#include "sysfs-pwm-pin.h"
#include <cstdint>

#define servo_max 100
#define servo_min -100

class SysFS_Servo
{
public:
    SysFS_Servo(SysFS_PWM_Pin pwm, uint64_t duty_mid, uint64_t duty_min, uint64_t duty_max);

    void set_position(int position);

private:
    SysFS_PWM_Pin _pwm;
    const uint64_t _duty_cycle_mid;
    const uint64_t _duty_cycle_min;
    const uint64_t _duty_cycle_max;
};
