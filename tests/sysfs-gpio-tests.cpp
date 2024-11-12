#include <gtest/gtest.h>

#include <base/sysfs-gpio.h>
#include <base/sysfs-file.h>

#include "fixture-tmpdir.h"
#include <fstream>


// tmpdir_fixture.dirname is used as pin directory, initially
// containing files

// * ``period`` containing PERIOD_NS_INIT
// * ``duty_cycle`` containing 0
struct sysfs_gpio_suite : tmpdir_fixture 
{
    SysFSFile direction_file;
    SysFSFile value_file;

    sysfs_gpio_suite()
    : direction_file(dirname / "direction"),
      value_file(dirname / "value")
    {
        // create files (SysFSFile insists that they exist, it doesn't
        // create any file)
        std::ofstream(dirname / "direction", std::ios::out);
        std::ofstream(dirname / "value", std::ios::out);

        // write initial content
        direction_file.write_string("out");
        value_file.write_uint64(0);
    }
};


TEST_F(sysfs_gpio_suite, basic)
{
    SysFSGPIO gpio(dirname);
    ASSERT_EQ(gpio.state(), false);
    ASSERT_EQ(gpio.direction(), SysFSGPIO::OUT);

    gpio.set_state(true);

    SysFSFile value_file(dirname / "value");
    ASSERT_EQ(value_file.read_uint64(), 1);
}
