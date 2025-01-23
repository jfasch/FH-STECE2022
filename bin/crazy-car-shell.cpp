#include "crazy-car-config.h"

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_WRONLY);

    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    std::string input;
    char command;
    int value;

    std::cout << "Hello and welcome to the crazy car control programm!" << std::endl;
    while(true)
    {
        int priority = 1;
        CrazyCarMessage msg;

        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        command = input[0]; // First character is the command
        try{
            value = std::stoi(input.substr(2));
        } catch (const std::invalid_argument& e) {
            std::cout << "ERROR: Invalid input." << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cout << "ERROR: Invalid input." << std::endl;
            continue;
        }

        if(command == 's')
        {
            if(value < -100 || value > 100)
            {
                std::cout << "ERROR: Invalid Input for servo position! Choose a value between -100 and 100." << std::endl;
                continue;
            }
            else
            {
                std::cout << "Servo-position set to: " << value << std::endl;
                msg = {
                    .command = SERVO_SET_ANGLE_PERCENT,
                    .value = value
                };
            }
        }
        else if (command == 'd')
        {
            if(value < -100 || value > 100)
            {
                std::cout << "ERROR: Invalid Input for motor speed! Choose a value between -100 and 100." << std::endl;
                continue;
            }
            else
            {
                std::cout << "Motor-speed set to: " << value << std::endl;

                msg = {
                    .command = MOTOR_SET_FRACTION_SPEED_PERCENT,
                    .value = value
                };
            }
        }
        else 
        {
            std::cout << "ERROR: Unknown command!" << std::endl;
            continue;
        }

        ssize_t n_bytes_written = mq_send(message_queue, (char*)&msg, sizeof(msg), priority);
        
        if (n_bytes_written == -1) 
        {
            std::cout << "Error" << std::endl;
            perror("mq_send");
            return 1;
        }
        assert(n_bytes_written == 0);
    }

    return 0;
}
