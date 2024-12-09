#pragma once

#define CRAZY_CAR_MQ_NAME "/crazy-car"

// depends on /boot/config.txt
// #define CRAZY_CAR_MOTOR_SPEED_PWM_DIR "/sys/class/pwm/pwmchip{0,1}/pwm2"
// #define CRAZY_CAR_MOTOR_FORWARD_PIN "/sys/class/gpio/gpio8"
// ...


// sensor address conflict
// - gyro is at 0x28 by default
// - tof is at 0x29 by default BUT WE HAVE THREE OF THEM

// - crazy-car-init: time-of-flight sensor address config

//      - order 3 breakouts with *six* pins (including XSHUT (hardware suspend))
//      - connect XSHUT to dedicated GPIOS
//      - hold all in hardware suspend
//      - release one after the other, configuring addresses in software as we go
