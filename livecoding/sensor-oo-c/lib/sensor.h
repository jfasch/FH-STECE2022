#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Sensor
{
    const char* filename;
};
void sensor_init(struct Sensor* sensor, const char* filename);
int sensor_get_temperature(struct Sensor* sensor, double* temperature);

#ifdef __cplusplus
}
#endif
