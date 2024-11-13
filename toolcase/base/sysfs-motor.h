#pragma once

#include "sysfs-gpio-pin.h"
#include "sysfs-pwm-pin.h"


class SysFSMotor
{
public:
    SysFSMotor(SysFS_GPIO_Pin forward, SysFS_GPIO_Pin backward, SysFS_PWM_Pin speed) {}
    void set_speed(int) {}
};
