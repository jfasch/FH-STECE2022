#pragma once

#include "sysfs-file.h"

#include <filesystem>


class SysFS_GPIO_Pin
{
public:
    enum Direction
    {
        IN,
        OUT,
    };

public:
    SysFS_GPIO_Pin(const std::filesystem::path& pindir);

    Direction direction();
    bool state();
    void set_state(bool);

private:
    SysFS_File _value_file;
    SysFS_File _direction_file;
};
