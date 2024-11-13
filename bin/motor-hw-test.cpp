#include <base/sysfs-pwm-pin.h>
#include <base/sysfs-motor.h>

#include <iostream>


int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << argv[0] << "<GPIO-forward> <GPIO-backward> <PWM-dir>\n";
        return 1;
    }

    SysFS_GPIO_Pin forward_pin(argv[1]);
    SysFS_GPIO_Pin backward_pin(argv[2]);
    SysFS_PWM_Pin pwm_pin(argv[3]);

    SysFS_Motor motor(forward_pin, backward_pin, pwm_pin);

    while (! std::cin.eof()) {
        int speed;

        std::cout << "enter speed:";
        std::cin >> speed;
        motor.set_speed(speed);
    }
    
    return 0;
}
