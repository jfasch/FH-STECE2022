#pragma once
#include "sysfs-pwm-pin.h"
#include <cstdint>

#define servo_max 100
#define servo_min -100

/** PPM servo driver on top of PWM

    blah blah blah blah blah blah blah blah blah blah blah blah blah
    blah blah blah blah blah blah blah blah blah blah blah blah blah
    blah blah

 */
class SysFS_Servo
{
public:
    /** Constructor

        @param pwm blah blah blah blah blah blah 
        @param duty_mid blah blah blah blah blah blah 
        @param duty_min blah blah blah blah blah blah 
        @param duty_max blah blah blah blah blah blah 

    */
    SysFS_Servo(SysFS_PWM_Pin pwm, uint64_t duty_mid, uint64_t duty_min, uint64_t duty_max);

    /** Set position

        explain unit of position

        @param position blah blah blah blah blah blah

    */
    void set_position(int position);

private:
    SysFS_PWM_Pin _pwm;
    const uint64_t _duty_cycle_mid;
    const uint64_t _duty_cycle_min;
    const uint64_t _duty_cycle_max;
};
