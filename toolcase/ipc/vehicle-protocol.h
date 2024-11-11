#pragma once

#include <cstdint>


enum VehicleCommand: uint8_t
{
    MOTOR_SET_RPM,
    SERVO_SET_ANGLE,
};

struct VehicleMessage
{
    VehicleCommand command;
    int value;
};
