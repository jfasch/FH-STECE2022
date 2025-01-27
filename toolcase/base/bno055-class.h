#ifndef BNO055_CLASS
#define BNO055_CLASS

#include "bno055.h"
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

struct bno{
   double data_x;   //data, X-axis
   double data_y;   //data, Y-axis
   double data_z;   //data, Z-axis
};

/** Blah title blah

    blah text blah blah text blah blah text blah blah text blah blah
    text blah blah text blah blah text blah blah text blah blah text
    blah blah text blah blah text blah blah text blah blah text blah
    blah text blah blah text blah
 */
class Bno055
{

    private:

        int _i2cfd;
        bool _message = 0;

    public:

        /** Blah ctor title blah

            @param i2cbus     blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah 
            @param i2caddr    blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah 

        */
        Bno055(const char* i2cbus, const char* i2caddr);
        void debug_message();
        void power_mode(power_t pwrmode);       
        void set_mode(opmode_t newmode);
        void reset();
        void dump();
        /** Blah title

            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah
         */
        bno get_sensor_data_gyr();        
        /** Blah title

            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah
         */
        bno get_sensor_data_eul();       
        /** Blah title

            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah
         */
        bno get_sensor_data_acc();

        /** Blah title

            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah blah
            blah blah blah blah blah blah blah blah blah blah
         */
        void csv_bno055_create(const char* csvfile, bool newfile);

};

#endif
