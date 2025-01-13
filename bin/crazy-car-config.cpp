#include "crazy-car-config.h"

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>

// ---------- PWM Configuration - external PWM device (PCA9685) ----------
pwm_config servo_pwm_config = {  // -> /sys/class/pwm/pwmchip0/pwm3
    .chip = 0, 
    .pin = 3,
    .gpio = 18,
    .period = 20000000,
};
pwm_config motor_pwm_config = { // -> /sys/class/pwm/pwmchip0/pwm2
    .chip = 0, 
    .pin = 2,
    .gpio = 19,
    .period = 20000000,
};

// Define the GPIO configurations
gpio_config motor_forward = { .gpio = 8 };
gpio_config motor_backward = { .gpio = 7 };
gpio_config button_start = { .gpio = 5 };
gpio_config button_stop = { .gpio = 6 };
gpio_config TOF_int01 = { .gpio = 23 };
gpio_config TOF_int02 = { .gpio = 24 };
gpio_config TOF_int03 = { .gpio = 25 };
gpio_config ADS7128_int = { .gpio = 17 };
gpio_config BNO055_rst = { .gpio = 27 };
gpio_config VBAT_s_on = { .gpio = 22 };

