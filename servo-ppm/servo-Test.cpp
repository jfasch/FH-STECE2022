#include <iostream>
#include <thread>
#include <chrono>

#include "../toolcase/base/sysfs-servo.h"
#include "../toolcase/base/sysfs-pwm-pin.h"
//#include "../toolcase/base/sysfs-file.h"

// Function to test the SysFS_Servo class
void test_servo(SysFS_Servo& servo)
{
    for (int position = servo_min; position <= servo_max; position += 20)
    {
        std::cout << "Setting position to: " << position << std::endl;
        servo.set_position(position);

        // Pause for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    for (int position = servo_max; position >= servo_min; position -= 20)
    {
        std::cout << "Setting position to: " << position << std::endl;
        servo.set_position(position);

        // Pause for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    try
    {
        // Specify the PWM pin directory
        std::filesystem::path pwm_pin_dir = "/sys/class/pwm/pwmchip0/pwm0";
        //std::filesystem::path pwm_pin_dir = "/tmp/pwm/pwmchip0/pwm0";

        // Create a SysFS_PWM_Pin instance
        SysFS_PWM_Pin pwm_pin(pwm_pin_dir);

        // Servo mid-point, min, and max duty cycle values
        uint64_t duty_mid = 1400000; // 1.4 ms for mid-point
        uint64_t duty_min = 1100000; // 1.1 ms for min position
        uint64_t duty_max = 1700000; // 1.7 ms for max position

        // Create a SysFS_Servo instance
        SysFS_Servo servo(pwm_pin, duty_mid, duty_min, duty_max);

        // Test the servo
        test_servo(servo);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
