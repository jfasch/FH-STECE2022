#pragma once

#include "sysfs-file.h"
#include <filesystem>


class SysFSPWMPin
{
public:
    SysFSPWMPin(const std::filesystem::path& pindir)
    : _period_file(pindir / "period"),
      _duty_cycle_file(pindir / "duty_cycle")
    {}

    int64_t period()
    {
        return -666; // fake news
    }

    int64_t duty_cycle()
    {
        return -666; // fake news
    }

    void set_duty_cycle(uint64_t i)
    {
        // fake news
    }

private:
    SysFSFile _period_file;
    SysFSFile _duty_cycle_file;
};
