#pragma once

#include "sysfs-file.h"

#include <filesystem>


class SysFSGPIO
{
public:
    enum Direction
    {
        IN,
        OUT,
    };

public:
    SysFSGPIO(const std::filesystem::path& pindir);

    Direction direction();
    bool state();
    void set_state(bool);

private:
    SysFS_File _value_file;
    SysFS_File _direction_file;
};
