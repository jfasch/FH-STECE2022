#pragma once

#include "sysfs-gpio-pin.h"
#include "sysfs-pwm-pin.h"


class SysFSMotor
{
public:
    SysFSMotor(SysFS_GPIO_Pin forward, SysFS_GPIO_Pin backward, SysFSPWMPin speed) {}
    void set_speed(int) {}
};
