#include "sensor.h"

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void sensor_init(struct Sensor* sensor, const char* filename)
{
    sensor->filename = filename;
}

int sensor_get_temperature(struct Sensor* sensor, double* temperature)
{
    int retval = 0;

    int fd = open(sensor->filename, O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT) {
            retval = -1;
            goto cleanup_exit;
        }
        if (errno == EACCES) {
            retval = -2;
            goto cleanup_exit;
        }

        perror("open");
        retval = -42; // todo
        goto cleanup_exit;
    }

    char buffer[64];
    memset(buffer, 0, sizeof(buffer));
    ssize_t nread = read(fd, buffer, sizeof(buffer)-1);
    if (nread == -1) {
        perror("read");
        retval = -42;
        goto cleanup_exit;
    }

cleanup_exit:
    if (fd != -1)
        close(fd);
    if (retval != 0)
        return retval;

    int millidegrees;
    int nconverted = sscanf(buffer, "%d", &millidegrees);

    if (nconverted != 1)
        return -3;

    *temperature = (double)millidegrees/1000;

    return 0;
}
