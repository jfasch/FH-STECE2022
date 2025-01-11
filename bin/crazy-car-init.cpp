#include "crazy-car-config.h"
#include <base/sysfs-gpio-pin.h> // maybe not needed?? it's included in the sysfs-motor.h

#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>
#include <base/sysfs-servo.h>

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <cstdio>
#include <iostream>



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
    // Motor Control - PWM Pin
    SysFS_File pwm_export(printf("/sys/class/pwm/pwmchip%d/export", motor_pwm_config.chip));
    pwm_export.write_uint64(motor_pwm_config.pin);

    SysFS_File pwm_enable(printf("/sys/class/pwm/pwmchip%d/pwm%d/enable ", motor_pwm_config.chip, motor_pwm_config.pin));
    pwm_enable.write_string("1");

    SysFS_File pwm_period(printf("/sys/class/pwm/pwmchip%d/pwm%d/period", motor_pwm_config.chip, motor_pwm_config.pin));
    pwm_period.write_uint64(motor_pwm_config.period);

    SysFS_File pwm_duty_cycle(printf("/sys/class/pwm/pwmchip%d/pwm%d/duty_cycle", motor_pwm_config.chip, motor_pwm_config.pin));
    pwm_duty_cycle.write_uint64(0); 


    // Servo Control - PWM Pin
    SysFS_File pwm_export(printf("/sys/class/pwm/pwmchip%d/export", servo_pwm_config.chip));
    pwm_export.write_uint64(servo_pwm_config.pin);
    
    SysFS_File pwm_enable(printf("/sys/class/pwm/pwmchip%d/pwm%d/enable ", servo_pwm_config.chip, servo_pwm_config.pin));
    pwm_enable.write_string("1");

    SysFS_File pwm_period(printf("/sys/class/pwm/pwmchip%d/pwm%d/period", servo_pwm_config.chip, servo_pwm_config.pin));
    pwm_period.write_uint64(servo_pwm_config.period);

    SysFS_File pwm_duty_cycle(printf("/sys/class/pwm/pwmchip%d/pwm%d/duty_cycle", servo_pwm_config.chip, servo_pwm_config.pin));
    pwm_duty_cycle.write_uint64(0); 

    



    // ---------- GPIO Configuration ----------
    // Motor Control - Forward Pin
    SysFS_File gpio_export("/sys/class/gpio/export ");
    gpio_export.write_uint64(motor_forward.gpio);

    SysFS_File gpio_direction(printf("/sys/class/gpio/gpio%d/direction ", motor_forward.gpio));
    gpio_direction.write_string("out");

    SysFS_File gpio_value(printf("/sys/class/gpio/gpio%d/value ", motor_forward.gpio));
    gpio_value.write_string("0"); 


    // Motor Control - Backward Pin
    SysFS_File gpio_export("/sys/class/gpio/export ");
    gpio_export.write_uint64(motor_backward.gpio);

    SysFS_File gpio_direction(printf("/sys/class/gpio/gpio%d/direction ", motor_backward.gpio));
    gpio_direction.write_string("out");

    SysFS_File gpio_value(printf("/sys/class/gpio/gpio%d/value ", motor_backward.gpio));
    gpio_value.write_string("0"); 






    // ---------- Create Elements for further use ----------
    //Create Paths for each Pin that is used
    SysFS_GPIO_Pin forward_pin("/sys/class/gpio/gpio%d", motor_forward.gpio); 
    SysFS_GPIO_Pin backward_pin("/sys/class/gpio/gpio%d", motor_backward.gpio); 
    SysFS_PWM_Pin motor_pwm_pin("/sys/class/pwm/pwmchip%d/pwm%d", motor_pwm_config.chip, motor_pwm_config.pin); 

    SysFS_Motor motor(forward_pin, backward_pin, motor_pwm_pin);

    SysFS_PWM_Pin servo_pwm_pin("/sys/class/pwm/pwmchip%d/pwm%d", servo_pwm_config.chip, servo_pwm_config.pin); 




    // Clean-up
    mq_close(message_queue);
    return 0;
}

