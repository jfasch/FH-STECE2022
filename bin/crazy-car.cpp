#include "crazy-car-config.h"
#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>

//I need this libraries, therefore I had to include also toolcase-base in the target-link-libraries in the CMakeLists.txt. 
//When the Initialization is done in the crazy car init program this is obsolete but then that header file must be included. 
#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>
#include <base/sysfs-servo.h>

//This initialization should be done in the motor init program
//For the guy who does the init program please note that the pins must me exported before so that paths exist 
// e.g. echo 7 > /sys/class/gpio/export
// e.g. echo out > /sys/class/gpio/gpio7/direction

//e.g. echo 2 > /sys/class/pwm/pwmchip0/export
SysFS_GPIO_Pin forward_pin("/sys/class/gpio/gpio7"); 
SysFS_GPIO_Pin backward_pin("/sys/class/gpio/gpio8");  
SysFS_PWM_Pin motor_pwm_pin("/sys/class/pwm/pwmchip0/pwm2"); 
SysFS_Motor motor(forward_pin, backward_pin, motor_pwm_pin);

SysFS_PWM_Pin servo_pwm_pin("/sys/class/pwm/pwmchip0/pwm1"); 
uint64_t duty_cycle_mid = 1.4 * 1000 * 1000;
uint64_t duty_cycle_min = 1.1 * 1000 * 1000;
uint64_t duty_cycle_max = 1.7 * 1000 * 1000;
SysFS_Servo servo(servo_pwm_pin, duty_cycle_min, duty_cycle_mid, duty_cycle_max);

int main()
{
    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_RDONLY); 
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }
    while (true) {
        CrazyCarMessage cur_msg;
        unsigned int priority;

        ssize_t n_bytes_read = mq_receive(message_queue, (char*)&cur_msg, sizeof(cur_msg), &priority);
        if (n_bytes_read == -1) {
            perror("mq_receive");
            return 2;
        }
        assert(n_bytes_read == sizeof(cur_msg));
        
        switch (cur_msg.command) {
            case MOTOR_SET_FRACTION_SPEED_PERCENT:
                std::cout << "Motor: set speed as a fraction of max speed in percent (-100 to 100%) " << cur_msg.value << std::endl;
                motor.set_speed(cur_msg.value);
                break;
            case SERVO_SET_ANGLE_PERCENT:
                std::cout << "Servo: set angle in percent from -100 to 100% " << cur_msg.value << std::endl;
                servo.set_position(cur_msg.value);
                break;
            default:
                assert("bad command");
                break;
        }
    }
    
    return 0;
}
