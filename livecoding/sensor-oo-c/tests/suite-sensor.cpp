#include <sensor.h>

#include "fixture-sensor.h"

#include <gtest/gtest.h>
#include <fcntl.h>


TEST_F(sensor_fixture, sunny)
{
    change_temperature(42.666);

    Sensor sensor;
    sensor_init(&sensor, sensor_file.c_str());

    double temperature = sensor_get_temperature(&sensor);

    ASSERT_FLOAT_EQ(temperature, 42.666);
}

TEST_F(sensor_fixture, sensor_file_not_exist)
{
    Sensor sensor;
    sensor_init(&sensor, "/a/file/that/does/not/exist");

    try {
        sensor_get_temperature(&sensor);
        FAIL();
    }
    catch (SensorError e) {
        ASSERT_EQ(e.error, -1);
    }
}

TEST_F(sensor_fixture, sensor_file_no_permission)
{
    Sensor sensor;
    sensor_init(&sensor, sensor_file.c_str());

    int error = chmod(sensor_file.c_str(), 0);
    ASSERT_EQ(error, 0);

    try {
        sensor_get_temperature(&sensor);
        FAIL();
    }
    catch (SensorError e) {
        ASSERT_EQ(e.error, -2);
    }
}

TEST_F(sensor_fixture, sensor_file_bad_content)
{
    int fd = open(sensor_file.c_str(), O_WRONLY);
    ASSERT_NE(fd, -1);
    const char bad_content[] = "bad-content";
    ssize_t nwritten = write(fd, bad_content, sizeof(bad_content));
    ASSERT_EQ(nwritten, sizeof(bad_content));
    close(fd);

    struct Sensor sensor;
    sensor_init(&sensor, sensor_file.c_str());

    try {
        sensor_get_temperature(&sensor);
        FAIL();
    }
    catch (SensorError e) {
        ASSERT_EQ(e.error, -3);
    }
}

