#include <sensor.h>

#include "fixture-sensor.h"

#include <fcntl.h>


TEST_F(sensor_fixture, sunny)
{
    change_temperature(42.666);

    double temperature;
    int error = read_temperature(sensor_file.c_str(), &temperature);

    ASSERT_EQ(error, 0);
    ASSERT_FLOAT_EQ(temperature, 42.666);
}

TEST_F(sensor_fixture, sensor_file_not_exist)
{
    double temperature = -273.15;
    int error = read_temperature("/a/file/that/does/not/exist", &temperature);

    ASSERT_EQ(error, -1);
    ASSERT_FLOAT_EQ(temperature, -273.15);
}

TEST_F(sensor_fixture, sensor_file_no_permission)
{
    int error = chmod(sensor_file.c_str(), 0);
    ASSERT_EQ(error, 0);

    double temperature = -273.15;
    error = read_temperature(sensor_file.c_str(), &temperature);

    ASSERT_EQ(error, -2);
    ASSERT_FLOAT_EQ(temperature, -273.15);
}

TEST_F(sensor_fixture, sensor_file_bad_content)
{
    int fd = open(sensor_file.c_str(), O_WRONLY);
    ASSERT_NE(fd, -1);
    const char bad_content[] = "bad-content";
    ssize_t nwritten = write(fd, bad_content, sizeof(bad_content));
    ASSERT_EQ(nwritten, sizeof(bad_content));
    close(fd);

    double temperature = -273.15;
    int error = read_temperature(sensor_file.c_str(), &temperature);

    ASSERT_EQ(error, -3);
    ASSERT_FLOAT_EQ(temperature, -273.15);
}
