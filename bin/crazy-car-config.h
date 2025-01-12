#pragma once

#define CRAZY_CAR_MQ_NAME "/crazy-car"

#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>
#include <base/sysfs-servo.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>

// Define pwm_config structure
struct pwm_config {
    int chip;
    int pin;
    int gpio; // from pi pinout
    int period;
};

// Define gpio_config structure
struct gpio_config {
    int gpio;   // from pi pinout
};

// Declare the PWM configurations as extern
extern pwm_config servo_pwm_config;
extern pwm_config motor_pwm_config;

// Declare motor and servo as extern
extern SysFS_Motor motor;
extern SysFS_Servo servo;

// Declare GPIO configurations as extern
extern gpio_config motor_forward;
extern gpio_config motor_backward;
extern gpio_config button_start;
extern gpio_config button_stop;
extern gpio_config TOF_int01;
extern gpio_config TOF_int02;
extern gpio_config TOF_int03;
extern gpio_config ADS7128_int;
extern gpio_config BNO055_rst;
extern gpio_config VBAT_s_on;

// Function declarations from crazy-car-init.cpp
//int GPIO_Init();
void initialize_pwm(int chip, int pin, uint64_t period);
void initialize_gpio(int gpio, const std::string& direction);


