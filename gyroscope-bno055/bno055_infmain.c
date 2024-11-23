#include "bno055_class.h"
#include <stdio.h>
#define ADDR "0x29";
#define I2CBUS1 "/dev/i2c-1";

int main()
{

    bnogyr test;
    char senaddr[256] = ADDR;
    char i2c_bus[256] = I2CBUS1;
    Bno055(i2c_bus, senaddr);
    while(1)
    {
        Bno055::reset();
        test = Bno055::get_sensor_data_gyr();
        Bno055::print_sensor_data_gyr();
    }

}