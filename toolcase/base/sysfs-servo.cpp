#include "sysfs-servo.h"

#include <fstream>
#include <iostream>

SysFS_Servo::SysFS_Servo(SysFS_PWM_Pin pwm, uint64_t duty_mid, uint64_t duty_min, uint64_t duty_max)
: _pwm(pwm),
  _duty_cycle_mid(duty_mid),
  _duty_cycle_min(duty_min),
  _duty_cycle_max(duty_max)  
{}

void SysFS_Servo::set_position(int position) {
    //error handling

    // std::cout << "\n\n" << position << "\n\n";

    if (position == 0) {
        _pwm.set_duty_cycle(_duty_cycle_mid);
        // std::cout << "\n\n position == 0 \n\n";
    } 
    else if(position <= servo_min) {
        _pwm.set_duty_cycle(_duty_cycle_min);
        // std::cout << "\n\n" << _duty_cycle_min << "\n\n";
        // std::cout << "\n\n position <= 0 \n\n";
    } 
    else if (position >= servo_max) {
        _pwm.set_duty_cycle(_duty_cycle_max);
    } 
    else if (position < 0) {
        int64_t range_negative = _duty_cycle_mid - _duty_cycle_min;
        int64_t duty_cycle_value = _duty_cycle_mid - range_negative * position / servo_min;
        _pwm.set_duty_cycle(duty_cycle_value);
    } 
    else if (position > 0) {
        int64_t range_positive = _duty_cycle_max - _duty_cycle_mid;
        int64_t duty_cycle_value = _duty_cycle_mid + range_positive * position / servo_max;
        _pwm.set_duty_cycle(duty_cycle_value);
    } else {
        std::cout << "How did I end up here?";
    }
}
