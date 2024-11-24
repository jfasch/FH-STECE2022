#include "bno055_class.h"
#include <iostream>
#define ADDR "0x29";
#define I2CBUS1 "/dev/i2c-1";

int main()
{

    bnogyr test_data;
    char senaddr[256] = ADDR;
    char i2c_bus[256] = I2CBUS1;
    Bno055 sensor(i2c_bus, senaddr);
    while(1)
    {
        test_data = sensor.get_sensor_data_gyr();
        printf("getsenor data: %3.2f %3.2f %3.2f\n", test_data.gdata_x, test_data.gdata_y, test_data.gdata_z);
        sensor.print_sensor_data_gyr();
        sleep(1);
    }

}