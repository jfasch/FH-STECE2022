#include <base/sysfs-file.h>

#include <cstdio>
#include <unistd.h>
#include <iostream>

//test commit


int main() {
    SysFS_File exporT("/sys/class/pwm/pwmchip0/export");
    SysFS_File unexporT("/sys/class/pwm/pwmchip0/unexport");
    SysFS_File enable("/sys/class/pwm/pwmchip0/pwm0/enable");
    SysFS_File period("/sys/class/pwm/pwmchip0/pwm0/period");
    SysFS_File duty_cycle("/sys/class/pwm/pwmchip0/pwm0/duty_cycle"); 

    exporT.write_int64(0);
    sleep(1); 
    enable.write_int64(1);
    period.write_int64(1000000); 
    duty_cycle.write_int64(500000); 

    sleep(10); 

    enable.write_int64(0);
    unexporT.write_int64(0);

    sleep(1);

    return 0;
}
