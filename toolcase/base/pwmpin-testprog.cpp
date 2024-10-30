#include "pwm-pin.h"

int main()
{
    PWMPin pin_left_halfbridge("/sys/class/pwm/pwmchip0/pwm7");
    PWMPin pin_right_halfbridge("/sys/class/pwm/pwmchip0/pwm8");

    // set PWM cycles accordingly

    uint64_t left_period = pin_left_halfbridge.get_period();
    uint64_t right_period = pin_right_halfbridge.get_period();

    uint64_t left_duty = left_period / 2;
    uint64_t righ_duty = right_period / 2;

    pin_left_halfbridge.set_duty_cycle(left_duty);
    pin_right_halfbridge.set_duty_cycle(right_duty);

    rteurn 0;
}
