#include "fixture-tmpdir.h"
#include <base/sysfs-gpio-pin.h>
#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>

#include <sys/stat.h>
#include <assert.h>
#include <fstream>

struct motor_suite : public tmpdir_fixture
{
    motor_suite()
    : forward(""), backward(""), speed(""), motor(forward, backward, speed)
    {
        std::filesystem::path speed_path = dirname / "speed";
        std::filesystem::path forward_path = dirname / "forward";
        std::filesystem::path backward_path = dirname / "backward";

        int error;
        error = mkdir(speed_path.c_str(), 0700);
        assert(error == 0);
        error = mkdir(forward_path.c_str(), 0700);
        assert(error == 0);
        error = mkdir(backward_path.c_str(), 0700);
        assert(error == 0);

        std::ofstream(speed_path / "period", std::ios::out) << 10*1000*1000 << '\n';
        std::ofstream(speed_path / "duty_cycle", std::ios::out) << 0 << '\n';

        std::ofstream(forward_path / "value", std::ios::out) << 0 << '\n';
        std::ofstream(forward_path / "direction", std::ios::out) << "out" << '\n';

        std::ofstream(backward_path / "value", std::ios::out) << 0 << '\n';
        std::ofstream(backward_path / "direction", std::ios::out) << "out" << '\n';

        forward = SysFS_GPIO_Pin(forward_path);
        backward = SysFS_GPIO_Pin(backward_path);
        speed = SysFS_PWM_Pin(speed_path);

        motor = SysFS_Motor(forward, backward, speed);
    }

    SysFS_GPIO_Pin forward;
    SysFS_GPIO_Pin backward;
    SysFS_PWM_Pin speed;

    SysFS_Motor motor;
};

TEST_F(motor_suite, forward_slightly)
{
    motor.set_speed(10);
    ASSERT_EQ(speed.duty_cycle(), speed.period()/10);
    ASSERT_TRUE(forward.state());
    ASSERT_FALSE(backward.state());
}

TEST_F(motor_suite, backward_slightly)
{
    motor.set_speed(-10);
    ASSERT_EQ(speed.duty_cycle(), speed.period()/10);
    ASSERT_FALSE(forward.state());
    ASSERT_TRUE(backward.state());
}

TEST_F(motor_suite, zero_no_speed_before)
{
    motor.set_speed(0);
    ASSERT_EQ(speed.duty_cycle(), 0);
    ASSERT_FALSE(forward.state());
    ASSERT_FALSE(backward.state());
}

TEST_F(motor_suite, zero_speed_set_before)
{
    motor.set_speed(50);
    motor.set_speed(0);
    ASSERT_EQ(speed.duty_cycle(), 0);
    ASSERT_NE(forward.state(), backward.state());
}

TEST_F(motor_suite, forward_invalid_positive_value)
{
    motor.set_speed(180);
    ASSERT_EQ(speed.duty_cycle(), speed.period());
    ASSERT_TRUE(forward.state());
    ASSERT_FALSE(backward.state());
}

TEST_F(motor_suite, forward_invalid_negative_value)
{
    motor.set_speed(-180);
    ASSERT_EQ(speed.duty_cycle(), speed.period());
    ASSERT_FALSE(forward.state());
    ASSERT_TRUE(backward.state());
}

