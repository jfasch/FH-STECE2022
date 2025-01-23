#pragma once

#include "sysfs-file.h"


/** A GPIO pin, as represented in `/sys/class/gpio/gpio25/`

    Encapsulates an exported `sysfs` GPIO pin. It does not export the
    pin itself (by writing to `/sys/class/gpio/export`); rather, you
    have to make sure that the pin directory exists, and is configured
    correctly.
 */
class SysFS_GPIO_Pin
{
public:
    enum Direction
    {
        IN,
        OUT,
    };

public:
    /** Constructor

        @param pindir The `sysfs` pin directory; e.g. `/sys/class/gpio/gpio25`
     */
    SysFS_GPIO_Pin(const std::string& pindir);

    /** Get direction */
    Direction direction();
    /** Get state */
    bool state();
    /** Set state

        Note that it does not make sense to set the state of a GPIO
        pin that is configured as input.
     */
    void set_state(bool);

private:
    SysFS_File _value_file;
    SysFS_File _direction_file;
};
