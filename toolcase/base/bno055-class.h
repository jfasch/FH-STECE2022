/***************************************************************
Original Library by Frank4DD
License information '/Documentation/toolcase/sensor-bno055.rst'
****************************************************************/
Frank4DD 
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

/** Class for Bno055 to measure with the gyroscope and accelerator for the rp

   The mode is set by default to measure with the gyroscope and accelerator. The class has 3 functions to read 
   the measurements and a function to create a csv file with a timestamp, Orientation, gyroscope Data and accelerator Data.
 */
class Bno055
{

    private:

        int _i2cfd;
        bool _message = 0;

    public:

        /** Parameters of the constructor

            @param i2cbus     This is the i2cbus, which is used for the communication with the sensor. 
            
            @param i2caddr    This is the adress of the sensor. The sensor can use two addresses 0x28 or 0x29.
                              The sensor has a the adress 0x28 when the ADD Pin is connected to ground and 
                              0x29 when it is not connected.

            The constructor also starts the i2c communication with sensor with the parameters from before.
            It also sets the mod for the used sensors and the fusion data, which is calculated by the sensor.  
        */
        Bno055(const char* i2cbus, const char* i2caddr);
        void debug_message();
        void power_mode(power_t pwrmode);       
        void set_mode(opmode_t newmode);
        void reset();
        void dump();
        /** Dump the register pages of the Sensor            
            This function reads the hole register of the sensor and displays it on the consol.
         */
        bno get_sensor_data_gyr();        
        /** Reading the gyroscope data
		      This function reads 3 Values out of the register of the Sensor and writes the values in a struct.
		      This Values are values are the x, y and z values of the gyroscope from the sensor.
         */
        bno get_sensor_data_eul();       
        /** Reading the fusion data data
      		This function reads 3 Values out of the register of the Sensor and writes the values in a struct.
      		This Values are calculated values from the sensor. In this class the 
      		values are caculated with the gyroscope and accelerator data.
         */
        bno get_sensor_data_acc();

        /** Reading the accelerator data
		      This function reads 3 Values out of the register of the Sensor and writes the values in a struct.
		      This Values are values are the x, y and z values of the accelerator from the sensor.
         */
        void csv_bno055_create(const char* csvfile, bool newfile);

         /** Creating a csv file from the gyr, acc and eul data
      		This function creats a csv file with the following parameters: Timestamp,Orientation,Gyroscope X-Data,
      		Gyroscope Y-Data,Gyroscope Z-Data,Accelerator X-Data,Accelerator Y-Data and Accelerator Z-Data.
      		For the Orientation the function get-sensor_data_eul() was used and the Orientation is writen in 
      		data_x of the struct.
      		This function opens and closes the csv every time.
         */
};

#endif
