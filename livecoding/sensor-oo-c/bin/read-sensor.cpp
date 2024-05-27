#include <sensor.h>
#include <stdio.h>
#include <stdlib.h>

/* struct Sensor */
/* { */
/*     const char* filename; */
/* }; */
/* void sensor_init(struct Sensor* obj, const char& filename); */
/* int sensor_get_temperature(struct Sensor* obj, double* temperature); */

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <temperature-file>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];

    struct Sensor sensor;
    sensor_init(&sensor, filename);

    double temperature;
    int error = sensor_get_temperature(&sensor, &temperature);
    if (error) {
        fprintf(stderr, "NIX GUT: %d\n", error);
        return 2;
    }

    printf("%lf\n", temperature);
    return 0;
}
