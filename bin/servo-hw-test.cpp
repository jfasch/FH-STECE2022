#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-servo.h>

#include <iostream>


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <PWM-dir>\n";
        return 1;
    }

    SysFS_PWM_Pin pwm(argv[1]);

    // these are taken from the servo tests: how are they related to
    // PWM period? can we decouple and derive them from period?
    uint64_t duty_cycle_mid = 1.4*1000*1000;
    uint64_t duty_cycle_min = 1.1*1000*1000;
    uint64_t duty_cycle_max = 1.7*1000*1000;
    SysFS_Servo servo(pwm, duty_cycle_min, duty_cycle_mid, duty_cycle_max);

    while (! std::cin.eof()) {
        int position;

        std::cout << "enter position: ";
        std::cin >> position;
        servo.set_position(position);
    }
    
    return 0;
}
