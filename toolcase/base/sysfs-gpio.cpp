#include "sysfs-gpio.h"

#include <cassert>


SysFSGPIO::SysFSGPIO(const std::filesystem::path& pindir)
: _value_file(pindir / "value"),
  _direction_file(pindir / "direction")
{}

SysFSGPIO::Direction SysFSGPIO::direction()
{
    std::string direction_str = _direction_file.read_string();
    if (direction_str == "in")
        return IN;
    else if (direction_str == "out")
        return OUT;

    assert(!"todo: error handling");
    return IN;
}

bool SysFSGPIO::state()
{
    return _value_file.read_uint64() == 1;
}

void SysFSGPIO::set_state(bool state)
{
    assert(direction() == OUT); // todo: error handling, speed optimization
    _value_file.write_uint64(state);
}
