#include "crazy-car-config.h"

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>


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
            case MOTOR_SET_RPM:
                std::cout << "Motor: set rpm to " << cur_msg.value << std::endl;
                break;
            case SERVO_SET_ANGLE:
                std::cout << "Servo: set angle to " << cur_msg.value << std::endl;
                break;
            default:
                assert("bad command");
                break;
        }
    }
    
    return 0;
}
