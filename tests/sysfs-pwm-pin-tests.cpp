#include <gtest/gtest.h>

#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-file.h>

#include "fixture-tmpdir.h"
#include <fstream>


// tmpdir_fixture.dirname is used as pin directory, initially
// containing files

// * ``period`` containing PERIOD_NS_INIT
// * ``duty_cycle`` containing 0
struct sysfs_pwm_pin_suite : tmpdir_fixture 
{
    uint64_t PERIOD_NS_INIT = 10*1000*1000;

    SysFSFile period_file;
    SysFSFile duty_cycle_file;

    sysfs_pwm_pin_suite()
    : period_file(dirname / "period"),
      duty_cycle_file(dirname / "duty_cycle")
    {
        // create files (SysFSFile insists)
        std::ofstream(dirname / "period", std::ios::out);
        std::ofstream(dirname / "duty_cycle", std::ios::out);

        // write initial content
        period_file.write_int64(PERIOD_NS_INIT);
        duty_cycle_file.write_int64(0);
    }
};


TEST_F(sysfs_pwm_pin_suite, get_period)
{
    SysFSPWMPin pin(dirname);

    ASSERT_EQ(pin.period(), PERIOD_NS_INIT);
    ASSERT_EQ(pin.duty_cycle(), 0);

    pin.set_duty_cycle(PERIOD_NS_INIT/2);

    ASSERT_EQ(pin.duty_cycle(), PERIOD_NS_INIT/2);
    ASSERT_EQ(period_file.read_int64(), PERIOD_NS_INIT);
    ASSERT_EQ(duty_cycle_file.read_int64(), PERIOD_NS_INIT/2);
}

// more
// ----

// * duty_cycle exceeds period -> error
