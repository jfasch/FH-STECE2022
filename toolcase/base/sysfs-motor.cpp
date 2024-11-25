#include "sysfs-motor.h"


void SysFS_Motor::set_speed(int speed)
{

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
