#include "sysfs-gpio-pin.h"

#include <cassert>


SysFS_GPIO_Pin::SysFS_GPIO_Pin(const std::string& pindir)
: _value_file(pindir + "/value"),
  _direction_file(pindir + "/direction")
{}

SysFS_GPIO_Pin::Direction SysFS_GPIO_Pin::direction()
{
    std::string direction_str = _direction_file.read_string();
    if (direction_str == "in")
        return IN;
    else if (direction_str == "out")
        return OUT;

    assert(!"todo: error handling");
    return IN;
}

bool SysFS_GPIO_Pin::state()
{
    return _value_file.read_uint64() == 1;
}

void SysFS_GPIO_Pin::set_state(bool state)
{
    assert(direction() == OUT); // todo: error handling, speed optimization
    _value_file.write_uint64(state);
}
