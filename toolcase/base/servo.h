#pragma once
#include "sysfs-pwm-pin.h"
#include <fstream>

class servo
{
public:
    servo(SysFSPWMPin PWMpin, uint8 duty_mid, uint8 duty_min, uint8 duty_max) 
    : _pwm(PWMpin),
      _duty_cycle_mid(duty_mid),
      _duty_cycle_min(duty_min),
      _duty_cycle_max(duty_max)  
    {
        asdfe
    }

    void set_position(int);

private:
    const SysFSPWMPin _pwm;
    const uint64_t _duty_cycle_mid;
    const uint64_t _duty_cycle_max;
    const uint64_t _duty_cycle_min;
};
