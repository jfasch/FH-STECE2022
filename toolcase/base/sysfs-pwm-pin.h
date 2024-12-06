#pragma once

#include "sysfs-file.h"


class SysFS_PWM_Pin
{
public:
    SysFS_PWM_Pin(const std::string& pindir)
    : _period_file(pindir + "/period"),
      _duty_cycle_file(pindir + "/duty_cycle")
    {}

    uint64_t period() { return _period_file.read_uint64(); }
    uint64_t duty_cycle() { return _duty_cycle_file.read_uint64(); }
    void set_duty_cycle(uint64_t i);

private:
    SysFS_File _period_file;
    SysFS_File _duty_cycle_file;
};
