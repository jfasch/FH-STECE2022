#include <base/sysfs-pwm-pin.h>

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "<PIN-DIRECTORY>\n";
        std::cerr << "  e.g.: " << argv[0] << " /sys/class/pwm/pwmchip0/pwm7\n";
        return 1;
    }

    SysFS_PWM_Pin my_pin(argv[1]);

    uint64_t period = my_pin.period();
    uint64_t step = period / 10;
    uint64_t duty_cycle = 0;

    while (true) {
        std::cout << period << ',' << step << ',' << duty_cycle << '\n';

        my_pin.set_duty_cycle(duty_cycle);
        std::this_thread::sleep_for(500ms);
        duty_cycle += step;
        duty_cycle %= period;
    }

    return 0;
}
