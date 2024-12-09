#pragma once

#include <cstdint>


enum CrazyCarCommand: uint8_t
{
    MOTOR_SET_FRACTION_SPEED_PERCENT,       // TODO: is the unit RPM? rename accordingly
    SERVO_SET_ANGLE_PERCENT,     // TODO: is the unit the angle? rename accordingly
};

struct CrazyCarMessage
{
    CrazyCarCommand command;
    int value;
};
