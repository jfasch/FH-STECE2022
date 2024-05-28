#pragma once

#include <string>


struct Sensor
{
    std::string filename;
};
void sensor_init(struct Sensor* sensor, std::string filename);
double sensor_get_temperature(struct Sensor* sensor);

struct SensorError
{
    SensorError(int error, std::string message)
    {
        this->error = error;
        this->message = message;
    };

    int error;
    std::string message;
};
