#include "crazy-car-config.h"

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <string>

int send_msg(mqd_t message_queue, int command, int value);

int main(int argc, char** argv)
{
    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_WRONLY);

    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    std::string command;
    int value;

    while(true)
    {
        std::cin >> command;
        std::cin >> value;
        int priority = 1;
        CrazyCarMessage msg;

        // switch (command)
        // {
        //     case "s":
        //     if(value < -100 || value > 100)
        //         {
        //             std::cout << "ERROR: Invalid Input for servo position! Choose a value between -100 and 100." << std::endl;
        //         }
        //         else
        //         {
        //             send_msg(message_queue, SERVO_SET_ANGLE, value);
        //         }

        //     case "d":
        //         if(value < -100 || value > 100)
        //         {
        //             std::cout << "ERROR: Invalid Input for motor speed! Choose a value between -100 and 100." << std::endl;
        //         }
        //         else
        //         {
        //             send_msg(message_queue, MOTOR_SET_RPM, value);
        //         }

        //     default:
        //         std::cout << "ERROR: Unknown command!" << std::endl;
        // }

        if(command == "s")
        {
            if(value < -100 || value > 100)
            {
                std::cout << "ERROR: Invalid Input for servo position! Choose a value between -100 and 100." << std::endl;
            }
            else
            {
                // TO-DO: CHANGE SERVO_SET_ANGLE ACCORDING TO NEW OFFICIAL VALUE
                msg = {
                    .command = SERVO_SET_ANGLE,
                    .value = value
                };
            }
        }
        else if (command == "d")
        {
            if(value < -100 || value > 100)
            {
                std::cout << "ERROR: Invalid Input for motor speed! Choose a value between -100 and 100." << std::endl;
            }
            else
            {
                // TO-DO: CHANGE MOTOR_SET_RPM ACCORDING TO NEW OFFICIAL VALUE
                msg = {
                    .command = MOTOR_SET_RPM,
                    .value = value
                };
            }
        }
        else 
        {
            std::cout << "ERROR: Unknown command!" << std::endl;
        }

        ssize_t n_bytes_written = mq_send(message_queue, (char*)&msg, sizeof(msg), priority);
        if (n_bytes_written == -1) {
            perror("mq_send");
            return 1;
        }
        assert(n_bytes_written == 0);
    
        std::cout << command << " " << value << std::endl;
    }

    return 0;
}

// command = 0 for motor
// command = 1 for servo
// int send_msg(mqd_t message_queue, CrazyCarMessage command, int value)
// {
//     // TO-DO: change the .command names accodring to changes!
//     CrazyCarMessage msg = {
//         .command = command,
//         .value = value
//     };

//     int priority = 1;

//     ssize_t n_bytes_written = mq_send(message_queue, (char*)&msg, sizeof(msg), priority);
//     if (n_bytes_written == -1) {
//         perror("mq_send");
//         return 1;
//     }
//     assert(n_bytes_written == 0);

//     return 0;
// }