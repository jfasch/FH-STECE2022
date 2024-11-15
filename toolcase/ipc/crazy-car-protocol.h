#pragma once

#include <cstdint>


enum CrazyCarCommand: uint8_t
{
    MOTOR_SET_RPM,       // TODO: is the unit RPM? rename accordingly
    SERVO_SET_ANGLE,     // TODO: is the unit the angle? rename accordingly
};

struct CrazyCarMessage
{
    CrazyCarCommand command;
    int value;
};
