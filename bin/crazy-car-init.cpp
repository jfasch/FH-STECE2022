#include "crazy-car-config.h"
#include <base/sysfs-gpio-pin.h> // maybe not needed?? it's included in the sysfs-motor.h
#include <base/sysfs-file.h>
#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>
#include <base/sysfs-servo.h>

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <cstdio>
#include <iostream>
#include <string>

int main()
{
    struct mq_attr attr = {
        .mq_maxmsg = 10,
        .mq_msgsize = sizeof(CrazyCarMessage)
    };
    
    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    // ---------- PWM Configuration ----------
    initialize_pwm(motor_pwm_config.chip, motor_pwm_config.pin, motor_pwm_config.period);
    initialize_pwm(servo_pwm_config.chip, servo_pwm_config.pin, servo_pwm_config.period);


    // ---------- GPIO Configuration ----------
    initialize_gpio(motor_forward.gpio, "out");
    initialize_gpio(motor_backward.gpio, "out");



    // Clean-up
    mq_close(message_queue);
    return 0;
}


void initialize_pwm(int chip, int pin, uint64_t period) {

    SysFS_File pwm_export("/sys/class/pwm/pwmchip" + std::to_string(chip) + "/export");
    pwm_export.write_uint64(pin);

    SysFS_File pwm_enable("/sys/class/pwm/pwmchip" + std::to_string(chip) + "/pwm" + std::to_string(pin) + "/enable");
    pwm_enable.write_string("1");

    SysFS_File pwm_period("/sys/class/pwm/pwmchip" + std::to_string(chip) + "/pwm" + std::to_string(pin) + "/period");
    pwm_period.write_uint64(period);

    SysFS_File pwm_duty_cycle("/sys/class/pwm/pwmchip" + std::to_string(chip) + "/pwm" + std::to_string(pin) + "/duty_cycle");
    pwm_duty_cycle.write_uint64(0); 
}

void initialize_gpio(int gpio, const std::string& direction) {
    SysFS_File gpio_export("/sys/class/gpio/export ");
    gpio_export.write_uint64(gpio);

    SysFS_File gpio_direction("/sys/class/gpio/gpio" + std::to_string(gpio) + "/direction ");
    gpio_direction.write_string(direction);

    SysFS_File gpio_value("/sys/class/gpio/gpio" + std::to_string(gpio) + "/value ");
    gpio_value.write_string("0"); 
}

