#include <gtest/gtest.h>

#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-file.h>
#include <base/servo.h>

#include "fixture-tmpdir.h"
#include <fstream>

struct sweet_servo_suite : tmpdir_fixture 
{
    uint64_t PERIOD_NS_INIT = 20*1000*1000;

    SysFSFile period_file;
    SysFSFile duty_cycle_file;
    SysFSPWMPin pin;
    uint64_t duty_cycle_mid;
    uint64_t duty_cycle_min;
    uint64_t duty_cycle_max;
    servo best_servo;

    sweet_servo_suite()
    : period_file(dirname / "period"),
      duty_cycle_file(dirname / "duty_cycle"),
      pin(dirname),
      duty_cycle_mid(1.4*1000*1000),
      duty_cycle_min(1.1*1000*1000),
      duty_cycle_max(1.7*1000*1000),
      best_servo(pin, duty_cycle_mid, duty_cycle_min, duty_cycle_max)
    {
        // create files (SysFSFile insists)
        std::ofstream(dirname / "period", std::ios::out);
        std::ofstream(dirname / "duty_cycle", std::ios::out);

        // write initial content
        period_file.write_int64(PERIOD_NS_INIT);
        duty_cycle_file.write_int64(0);
    }
};

TEST_F(sweet_servo_suite, sunny)
{
    ASSERT_EQ(pin.period(), PERIOD_NS_INIT);
    
    best_servo.set_position(servo_min);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_min);
    
    best_servo.set_position(0);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_mid);
    
    best_servo.set_position(servo_max);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_max);

    uint64_t range_positive = duty_cycle_max - duty_cycle_mid;
    uint64_t range_negative = duty_cycle_mid - duty_cycle_min;

    best_servo.set_position(servo_max/2);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_max - range_positive / 2);

    best_servo.set_position(servo_min/2);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_min + range_negative / 2);
}

TEST_F(sweet_servo_suite, out_of_range)
{    
    best_servo.set_position(servo_min - 1);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_min);
    best_servo.set_position(servo_min * 20);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_min);
    
    best_servo.set_position(servo_max + 1);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_max);
    best_servo.set_position(servo_max * 20);
    ASSERT_EQ(pin.duty_cycle(), duty_cycle_max);
}

// TEST_F(sweet_servo_suite, faulty_input)
// {    
//     best_servo.set_position("asdf");
//     ASSERT_EQ(duty_cycle_file.read_int64(), duty_cycle_min);
//     best_servo.set_position(-2000);
//     ASSERT_EQ(duty_cycle_file.read_int64(), duty_cycle_min);
    
//     best_servo.set_position(101);
//     ASSERT_EQ(duty_cycle_file.read_int64(), duty_cycle_max);
//     best_servo.set_position(2000);
//     ASSERT_EQ(duty_cycle_file.read_int64(), duty_cycle_max);
// }

