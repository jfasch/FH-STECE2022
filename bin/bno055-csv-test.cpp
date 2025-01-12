#include <base/bno055-class.h>
#include <iostream>
#define ADDR "0x28";
#define I2CBUS1 "/dev/i2c-1";
#define CSVFILE "sensor_data.csv";
#define NEWFILE false;

int main()
{
    char senaddr[256] = ADDR;
    char i2c_bus[256] = I2CBUS1;
    char csvfile[256] = CSVFILE;
    bool newfile = NEWFILE;
    Bno055 sensor(i2c_bus, senaddr);

    while(1)
    {
        sensor.csv_bno055_create(csvfile, newfile);
    }

}