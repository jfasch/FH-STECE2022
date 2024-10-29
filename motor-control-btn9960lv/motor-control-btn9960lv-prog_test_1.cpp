#include <base/sysfs-file.h>

#include <cstdio>
#include <unistd.h>
#include <iostream>


int main() {
    SysFSFile exporT("/sys/class/pwm/pwmchip0/export");
    SysFSFile unexporT("/sys/class/pwm/pwmchip0/unexport");
    SysFSFile enable("/sys/class/pwm/pwmchip0/pwm0/enable");
    SysFSFile period("/sys/class/pwm/pwmchip0/pwm0/period");
    SysFSFile duty_cycle("/sys/class/pwm/pwmchip0/pwm0/duty_cycle"); 

    exporT.write_int(0);
    sleep(1); 
    enable.write_int(1);
    period.write_int(1000000); 
    duty_cycle.write_int(500000); 

    sleep(10); 

    enable.write_int(0);
    unexporT.write_int(0);

    sleep(1);

    return 0;
}
