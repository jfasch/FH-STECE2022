#include "fixture-tmpdir.h"
#include <base/sysfs-gpio.h>
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

        forward = SysFSGPIO(forward_path);
        backward = SysFSGPIO(backward_path);
        speed = SysFSPWMPin(speed_path);

        motor = SysFSMotor(forward, backward, speed);
    }

    SysFSGPIO forward;
    SysFSGPIO backward;
    SysFSPWMPin speed;

    SysFSMotor motor;
};

TEST_F(motor_suite, forward_slightly)
{
    motor.set_speed(10);
    ASSERT_EQ(speed.duty_cycle(), speed.period()/10);
}

TEST_F(motor_suite, zero)
{
    motor.set_speed(0);
    ASSERT_EQ(speed.duty_cycle(), 0);
    ASSERT_NE(forward.state(), backward.state());
}

