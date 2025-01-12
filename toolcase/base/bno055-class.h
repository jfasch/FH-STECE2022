#ifndef BNO055_CLASS
#define BNO055_CLASS

#include "bno055.h"
#include <iostream>
#include <cstdio>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

struct bno{
   double data_x;   //data, X-axis
   double data_y;   //data, Y-axis
   double data_z;   //data, Z-axis
   uint64_t millis; //unix time
};

class Bno055
{

    private:

        int _i2cfd;
        bool _message = 0;

    public:

        Bno055(char i2cbus[256], char i2caddr[256]);
        void debug_message();
        void power_mode(power_t pwrmode);       
        void set_mode(opmode_t newmode);
        void reset();
        void dump();
        bno get_sensor_data_gyr();        
        bno get_sensor_data_eul();       
        bno get_sensor_data_acc();
        bno millis();
        void csv_bno055_create(char csvfile[256], bool newfile);

};

#endif
