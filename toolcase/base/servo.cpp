#include "servo.h"

servo::servo(SysFSPWMPin PWMpin, uint8_t duty_mid, uint8_t duty_min, uint8_t duty_max)
: _pwm(PWMpin),
    _duty_cycle_mid(duty_mid),
    _duty_cycle_min(duty_min),
    _duty_cycle_max(duty_max)  
{}

void set_position(int position) {
    //error handling
    if(position <= servo_min) {
        _pwm.set_duty(_duty_cycle_min);
    } elseif (position >= servo_max) {
        _pwm.set_duty(_duty_cycle_min);
    } elseif () {
        
    }

}