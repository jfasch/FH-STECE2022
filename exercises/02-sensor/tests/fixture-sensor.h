#pragma once

#include "fixture-tmpdir.h"

#include <gtest/gtest.h>

#include <cstdlib>
#include <unistd.h>
#include <stdexcept>
#include <string>


struct sensor_fixture : public tmpdir_fixture
{
    void SetUp() override
    {
        char filename_pattern[] = "w1_sensor_suite-XXXXXX";
        
        fd = mkstemp(filename_pattern);
        if (fd == -1)
            throw std::runtime_error("nix mkstemp()");

        sensor_file = filename_pattern;
    }

    void TearDown() override
    {
        if (fd != -1) {
            close(fd);
            unlink(sensor_file.c_str());
        }
    }

    void change_temperature(double temperature)
    {
        unsigned temp_milli = temperature * 1000;

        std::string content = std::to_string(temp_milli);

        off_t pos = ::lseek(fd, 0, SEEK_SET);
        ASSERT_EQ(pos, 0);

        ssize_t nwritten = ::write(fd, content.c_str(), content.size());
        ASSERT_EQ(nwritten, content.size());
    }

    int fd;
    std::string sensor_file;
};
