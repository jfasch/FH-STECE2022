#pragma once

#include "sysfs-gpio.h"
#include "sysfs-pwm-pin.h"


class SysFSMotor
{
public:
    SysFSMotor(SysFSGPIO forward, SysFSGPIO backward, SysFSPWMPin speed) {}
    void set_speed(int) {}
};
