#include <sensor.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>


int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <temperature-file>\n", argv[0]);
        return 1;
    }
    std::string filename = argv[1];

    struct Sensor sensor;
    sensor_init(&sensor, filename);

    try {
        double temperature = sensor_get_temperature(&sensor);
        printf("%lf\n", temperature);
    }
    catch (SensorError e) {
        fprintf(stderr, "NIX GUT: %d (%s)\n", e.error, e.message.c_str());
        return 2;
    }

    return 0;
}
