#include "crazy-car-config.h"

#include <base/sysfs-servo.h>
#include <base/sysfs-motor.h>
#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <memory>


int main(int argc, char** argv)
{
    const std::string simu_arg = "simulation";
    bool simulation_mode;
    if (argc == 1)
        simulation_mode = false;
    else if (argc == 2) {
        if (simu_arg == argv[1])
            simulation_mode = true;
        else {
            std::cerr << "Usage: " << argv[0] << " [simulation]\n";
            return 1;
        }
    }
    else {
        std::cerr << "Usage: " << argv[0] << " [simulation]\n";
        return 1;
    }

    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_RDONLY); 
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    std::unique_ptr<SysFS_Motor> motor;
    std::unique_ptr<SysFS_Servo> servo;

    if (! simulation_mode) {
        SysFS_GPIO_Pin forward_pin("/sys/class/gpio/gpio"+ std::to_string(motor_forward.gpio)); 
        SysFS_GPIO_Pin backward_pin("/sys/class/gpio/gpio"+ std::to_string(motor_backward.gpio)); 
        SysFS_PWM_Pin motor_pwm_pin("/sys/class/pwm/pwmchip" + std::to_string(motor_pwm_config.chip) +
                                    "/pwm" + std::to_string(motor_pwm_config.pin)); 

        motor = std::make_unique<SysFS_Motor>(forward_pin, backward_pin, motor_pwm_pin);

        SysFS_PWM_Pin servo_pwm_pin("/sys/class/pwm/pwmchip" + std::to_string(servo_pwm_config.chip) +
                                    "/pwm"+ std::to_string(servo_pwm_config.pin)); 
        servo = std::make_unique<SysFS_Servo>(servo_pwm_pin, duty_cycle_mid, duty_cycle_min, duty_cycle_max);
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
                std::cout << "Motor: set power in % " << cur_msg.value << std::endl;
                if (motor)
                    motor->set_speed(cur_msg.value);
                break;
            case SERVO_SET_ANGLE_PERCENT:
                std::cout << "Servo: set angle to " << cur_msg.value << std::endl;
                if (servo)
                    servo->set_position(cur_msg.value);
                break;
            default:
                assert("bad command");
                break;
        }
    }
    
    return 0;
}
