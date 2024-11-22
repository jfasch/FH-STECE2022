#pragma once

#include "sysfs-gpio-pin.h"
#include "sysfs-pwm-pin.h"


class SysFS_Motor
{
public:
    SysFS_Motor(SysFS_GPIO_Pin forward, SysFS_GPIO_Pin backward, SysFS_PWM_Pin speed)
    :_forward(forward), _backward(backward), _speed(speed), _was_speed_set(false)
    {}

    void set_speed(int speed);

private:
    SysFS_GPIO_Pin _forward;
    SysFS_GPIO_Pin _backward;
    SysFS_PWM_Pin _speed;
    bool _was_speed_set;
};
