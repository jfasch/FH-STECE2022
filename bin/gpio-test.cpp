#include <base/sysfs-gpio.h>

int main()
{
    SysFSGPIO gpio("/sys/class/gpio/gpio25");
    gpio.set_state(true);
    return 0;
}
