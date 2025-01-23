#pragma once

#include "sysfs-file.h"


/** A PWM pin, as represented in `/sys/class/pwm/pwmchip0/pwm7/`

    Encapsulates an exported `sysfs` PWM pin. It does not export the
    pin itself (by writing to
    `/sys/class/pwm/pwmchipN/export`). Rather, you have to make sure
    that the pin directory exists, and is configured correctly.

    Note that the pin's `period` property has no setter. This is
    because a PWM pin's period is not subject to change once it has
    been configured (only the `duty_cycle` is).
 */
class SysFS_PWM_Pin
{
public:
    /** Constructor

        @param pindir The `sysfs` pin directory; e.g. `/sys/class/pwm/pwmchip0/pwm7`
     */
    SysFS_PWM_Pin(const std::string& pindir)
    : _period_file(pindir + "/period"),
      _duty_cycle_file(pindir + "/duty_cycle")
    {}

    /** Get period */
    uint64_t period() { return _period_file.read_uint64(); }
    /** Get duty cycle */
    uint64_t duty_cycle() { return _duty_cycle_file.read_uint64(); }
    /** Set duty cycle */
    void set_duty_cycle(uint64_t i);

private:
    SysFS_File _period_file;
    SysFS_File _duty_cycle_file;
};
