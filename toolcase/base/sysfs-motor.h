#pragma once

#include "sysfs-gpio-pin.h"
#include "sysfs-pwm-pin.h"


class SysFS_Motor
{
public:
    SysFS_Motor(SysFS_GPIO_Pin forward, SysFS_GPIO_Pin backward, SysFS_PWM_Pin speed)
    :_forward(forward), _backward(backward), _speed(speed), _was_speed_set(false)
    {}

    void set_speed(int speed) {

        if(speed > 100)
        {
            speed = 100;
        }

        if(speed < -100)
        {
            speed = -100;
        }

        if (speed > 0)
        {
            _forward.set_state(true);
            _backward.set_state(false);
            _speed.set_duty_cycle(_speed.period() / 100 * std::abs(speed));  
            _was_speed_set = true;  
        }

        else if(speed < 0)
        {
            _forward.set_state(false);
            _backward.set_state(true);
            _speed.set_duty_cycle(_speed.period() / 100 * std::abs(speed));
            _was_speed_set = true;
        }

        else if(speed == 0 && _was_speed_set == false)
        {
            _forward.set_state(false);
            _backward.set_state(false);
            _speed.set_duty_cycle(_speed.period() / 100 * std::abs(speed));
        }

        else
        {
            _speed.set_duty_cycle(_speed.period() / 100 * std::abs(speed));
        }
        
    }

private:
SysFS_GPIO_Pin _forward;
SysFS_GPIO_Pin _backward;
SysFS_PWM_Pin _speed;
bool _was_speed_set;
};

