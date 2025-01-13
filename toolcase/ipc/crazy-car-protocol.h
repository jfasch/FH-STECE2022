#pragma once

#include <cstdint>


enum CrazyCarCommand: uint8_t
{
    MOTOR_SET_FRACTION_SPEED_PERCENT,       
    SERVO_SET_ANGLE_PERCENT,    
};

struct CrazyCarMessage
{
    CrazyCarCommand command;
    int value;
};
