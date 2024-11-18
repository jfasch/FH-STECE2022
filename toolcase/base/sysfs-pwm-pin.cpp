#include "sysfs-pwm-pin.h"

#include <filesystem>


void SysFS_PWM_Pin::set_duty_cycle(uint64_t i)
{
    if (i > period())
    {
        throw std::invalid_argument("Duty cycle is bigger than period");
    }
    else
    {
        _duty_cycle_file.write_uint64(i);
    }
}
