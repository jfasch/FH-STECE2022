#include <gtest/gtest.h>

#include <base/sysfs-gpio-pin.h>
#include <base/sysfs-file.h>

#include "fixture-tmpdir.h"
#include <fstream>


struct sysfs_gpio_suite : tmpdir_fixture 
{
    SysFS_File direction_file;
    SysFS_File value_file;

    sysfs_gpio_suite()
    : direction_file(dirname / "direction"),
      value_file(dirname / "value")
    {
        std::ofstream(dirname / "direction", std::ios::out) << "out\n";
        std::ofstream(dirname / "value", std::ios::out) << 0 << '\n';
    }
};


TEST_F(sysfs_gpio_suite, basic)
{
    SysFS_GPIO_Pin gpio(dirname);
    ASSERT_EQ(gpio.state(), false);
    ASSERT_EQ(gpio.direction(), SysFS_GPIO_Pin::OUT);

    gpio.set_state(true);

    SysFS_File value_file(dirname / "value");
    ASSERT_EQ(value_file.read_uint64(), 1);
}
