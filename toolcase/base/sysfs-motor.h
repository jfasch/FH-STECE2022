#pragma once

#include "sysfs-gpio-pin.h"
#include "sysfs-pwm-pin.h"


/** Motor driver on top of GPIO and PWM

    blah blah blah blah blah blah blah blah blah blah blah blah blah
    blah blah blah blah blah blah blah blah blah blah blah blah blah
    blah blah

 */
class SysFS_Motor
{
public:
    /** Constructor

        @param forward blah blah blah blah blah blah 
        @param backward blah blah blah blah blah blah 
        @param speed blah blah blah blah blah blah 

    */
    SysFS_Motor(SysFS_GPIO_Pin forward, SysFS_GPIO_Pin backward, SysFS_PWM_Pin speed)
    :_forward(forward), _backward(backward), _speed(speed), _was_speed_set(false)
    {}

    /** Set speed

        explain unit of percentage_of_max_speed

        @param percentage_of_max_speed blah blah blah blah blah blah

    */
    void set_speed(int percentage_of_max_speed);

private:
    SysFS_GPIO_Pin _forward;
    SysFS_GPIO_Pin _backward;
    SysFS_PWM_Pin _speed;
    bool _was_speed_set;
};
