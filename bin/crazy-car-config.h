#pragma once

#define CRAZY_CAR_MQ_NAME "/crazy-car"

// struct pwm_config
// {
//     int chip;
//     int pin;
//     int hw_gpio; // from pi pinout

// };

// struct gpio_config
// {
//     int gpio;   // from pi pinout
// };

// pwm_config servo_pwm_config = {  // -> /sys/class/pwm/pwmchip0/pwm0
//     .chip = 0, 
//     .pin = 0,
//     .hw_gpio = 18,
// };
// pwm_config motor_pwm_config = {
//     // ...
// };
// // motor_pwm = pwm(pwmchip 0, pwmpin 1, gpio 19); // -> /sys/class/pwm/pwmchip0/pwm1

// gpio_config motor_forward = {
//     .gpio = 7,
// };
// // motor_backward ...

