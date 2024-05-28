#include "sensor.h"

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


void sensor_init(struct Sensor* sensor, std::string filename)
{
    sensor->filename = filename;
}

double sensor_get_temperature(struct Sensor* sensor)
{
    int fd = open(sensor->filename.c_str(), O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT)
            throw SensorError(-1, "file does not exist");
        if (errno == EACCES)
            throw SensorError(-2, "file nix permission");

        perror("open");
        throw SensorError(-42, "todo"); // todo
    }

    char buffer[64];
    memset(buffer, 0, sizeof(buffer));
    ssize_t nread = read(fd, buffer, sizeof(buffer)-1);
    if (nread == -1) {
        perror("read");
        close(fd);
        throw SensorError(-42, "todo");
    }

    close(fd);

    int millidegrees;
    int nconverted = sscanf(buffer, "%d", &millidegrees);

    if (nconverted != 1)
        throw SensorError(-3, "bad content");

    return (double)millidegrees/1000;
}
