#include "getbno055.h"
#include <iostream>
#include <cstdio>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

struct bnogyr{
   double gdata_x;   // gyroscope data, X-axis
   double gdata_y;   // gyroscope data, Y-axis
   double gdata_z;   // gyroscope data, Z-axis
};

class Bno055
{

    private:

        int _i2cfd;
        int _message = 0;

    public:

        Bno055(char i2cbus[256], char i2caddr[256])
        {
            get_i2cbus(i2cbus, i2caddr);
            opmode_t newmode = gyronly;
            set_mode(newmode);
                    
        }

        void debug_message()
        {
            _message = 1;
        }

        void get_i2cbus(char i2cbus[256], char i2caddr[256])
        {
            if((_i2cfd = open(i2cbus, O_RDWR)) < 0) {
                printf("Error failed to open I2C bus [%s].\n", i2cbus);
                exit(-1);
            }
            if(_message == 1) printf("Debug: I2C bus device: [%s]\n", i2cbus);
            /* --------------------------------------------------------- *
            * Set I2C device (BNO055 I2C address is  0x28 or 0x29)      *
            * --------------------------------------------------------- */
            int addr = (int)strtol(i2caddr, NULL, 16);
            if(_message == 1) printf("Debug: Sensor address: [0x%02X]\n", addr);

            if(ioctl(_i2cfd, I2C_SLAVE, addr) != 0) {
                printf("Error can't find sensor at address [0x%02X].\n", addr);
                exit(-1);
            }
            /* --------------------------------------------------------- *
            * I2C communication test is the only way to confirm success *
            * --------------------------------------------------------- */
            char reg = BNO055_CHIP_ID_ADDR;
            if(write(_i2cfd, &reg, 1) != 1) {
                printf("Error: I2C write failure register [0x%02X], sensor addr [0x%02X]?\n", reg, addr);
                exit(-1);
            }
        }

        void power_mode(power_t pwrmode)
        {

            // get current mode
            int reg = BNO055_OPR_MODE_ADDR;
            if(write(_i2cfd, &reg, 1) != 1) {
                printf("Error: I2C write failure for register 0x%02X\n", reg);
                exit(-1);
            }
            unsigned int olddata = 0;
            if(read(_i2cfd, &olddata, 1) != 1) {
                printf("Error: I2C read failure for register data 0x%02X\n", reg);
                exit(-1);
            }

            // set config mode if not in config mode
            char data[2] = {0};
            data[0] = BNO055_OPR_MODE_ADDR;
            power_t oldmode = (power_t)(olddata & 0x0F);
            if(oldmode == pwrmode) {if(_message == 1) printf("Debug: Sensor is already in this mode");} // if new mode is the same
            else if(oldmode > 0 && pwrmode > 0) // switch to "config" first
            {  
                data[1] = 0x0;
                if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
                if(write(_i2cfd, data, 2) != 2) 
                {
                    printf("Error: I2C write failure for register 0x%02X\n", data[0]);
                    exit(-1);
                }
                /* --------------------------------------------------------- *
                * switch time: any->config needs 7ms + small buffer = 10ms  *
                * --------------------------------------------------------- */
                usleep(10 * 1000);
            }

            data[0] = BNO055_PWR_MODE_ADDR;
            data[1] = pwrmode;
            if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
            if(write(_i2cfd, data, 2) != 2) {
                printf("Error: I2C write failure for register 0x%02X\n", data[0]);
                exit(-1);
            }
            usleep(30 * 1000);
        }
        
        void set_mode(opmode_t newmode)
        {
            // get current mode
            int reg = BNO055_OPR_MODE_ADDR;
            if(write(_i2cfd, &reg, 1) != 1) {
                printf("Error: I2C write failure for register 0x%02X\n", reg);
                exit(-1);
            }
            unsigned int olddata = 0;
            if(read(_i2cfd, &olddata, 1) != 1) {
                printf("Error: I2C read failure for register data 0x%02X\n", reg);
                exit(-1);
            }

            // set config mode if not in config mode
            char data[2] = {0};
            data[0] = BNO055_OPR_MODE_ADDR;
            opmode_t oldmode = (opmode_t)(olddata & 0x0F);
            if(oldmode == newmode) {if(_message == 1) printf("Debug: Sensor is already in this mode");} // if new mode is the same
            else if(oldmode > 0 && newmode > 0) // switch to "config" first
            {  
                data[1] = 0x0;
                if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
                if(write(_i2cfd, data, 2) != 2) 
                {
                    printf("Error: I2C write failure for register 0x%02X\n", data[0]);
                    exit(-1);
                }
                /* --------------------------------------------------------- *
                * switch time: any->config needs 7ms + small buffer = 10ms  *
                * --------------------------------------------------------- */
                usleep(10 * 1000);
            }

            // set mode
            data[1] = newmode;
            if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
            if(write(_i2cfd, data, 2) != 2) 
            {
                printf("Error: I2C write failure for register 0x%02X\n", data[0]);
                exit(-1);
            }
        }

        void sensor_cal_gyr()
        {

        }

        void reset()
        {
            char data[2];
            data[0] = BNO055_SYS_TRIGGER_ADDR;
            data[1] = 0x20;
            if(write(_i2cfd, data, 2) != 2) {
                printf("Error: I2C write failure for register 0x%02X\n", data[0]);
                exit(-1);
            }
        
            //wait till sensor is ready after reset
            usleep(650 * 1000);

            if(_message == 1) printf("Debug: BNO055 Sensor Reset complete\n");
        }

        void dump()
        {
            int count = 0;

            while(count < 8) {
                char reg = count;
                if(write(_i2cfd, &reg, 1) != 1) {
                    printf("Error: I2C write failure for register 0x%02X\n", reg);
                    exit(-1);
                }

                char data[16] = {0};
                if(read(_i2cfd, &data, 16) != 16) {
                    printf("Error: I2C read failure for register 0x%02X\n", reg);
                    exit(-1);
                
                }
                printf("[0x%02X] %02X %02X %02X %02X %02X %02X %02X %02X",
                        (reg*16), data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
                printf(" %02X %02X %02X %02X %02X %02X %02X %02X\n",
                        data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);
                count++;
            }

            char datapage1[2] = {0};
            datapage1[0] = BNO055_PAGE_ID_ADDR;
            datapage1[1] = 0x1;
            if(verbose == 1) printf("Debug: write page-ID: [0x%02X] to register [0x%02X]\n", datapage1[1], datapage1[0]);
            if(write(_i2cfd, datapage1, 2) != 2) 
            {
                printf("Error: I2C write failure for register 0x%02X\n", datapage1[0]);
                exit(-1);
            }
            usleep(50 * 1000);
            count = 0;
            while(count < 8) {
                char reg = count;
                if(write(_i2cfd, &reg, 1) != 1) {
                    printf("Error: I2C write failure for register 0x%02X\n", reg);
                    exit(-1);
                }

                char data[16] = {0};
                if(read(_i2cfd, &data, 16) != 16) {
                    printf("Error: I2C read failure for register 0x%02X\n", reg);
                    exit(-1);
                
                }
                printf("[0x%02X] %02X %02X %02X %02X %02X %02X %02X %02X",
                        (reg*16), data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
                printf(" %02X %02X %02X %02X %02X %02X %02X %02X\n",
                        data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);
                count++;
            }

            char datapage0[2] = {0};
            datapage0[0] = BNO055_PAGE_ID_ADDR;
            datapage0[1] = 0x0;
            if(_message == 1) printf("Debug: write page-ID: [0x%02X] to register [0x%02X]\n", datapage0[1], datapage0[0]);
            if(write(_i2cfd, datapage0, 2) != 2) 
            {
                printf("Error: I2C write failure for register 0x%02X\n", datapage0[0]);
                exit(-1);
            }
            usleep(50 * 1000);
        }

        bnogyr get_sensor_data_gyr()
        {
            bnogyr sensordata;

            char reg = BNO055_GYRO_DATA_X_LSB_ADDR;
            if(write(_i2cfd, &reg, 1) != 1) {
                printf("Error: I2C write failure for register 0x%02X\n", reg);
                exit(-1);
            }

            char data[6] = {0};
            if(read(_i2cfd, data, 6) != 6) {
                printf("Error: I2C read failure for register data 0x%02X\n", reg);
                exit(-1);
            }

            int16_t buf = ((int16_t)data[1] << 8) | data[0];
            if(_message == 1) printf("Debug: Gyroscope Data X: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[0], data[1],buf);
            sensordata.gdata_x = (double) buf / 16.0;

            buf = ((int16_t)data[3] << 8) | data[2];
            if(_message == 1) printf("Debug: Gyrosscope Data Y: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[2], data[3],buf);
            sensordata.gdata_y = (double) buf / 16.0;

            buf = ((int16_t)data[5] << 8) | data[4];
            if(_message == 1) printf("Debug: Gyroscope Data Z: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[4], data[5],buf);
            sensordata.gdata_z = (double) buf / 16.0;

            return sensordata;
        }

        void print_sensor_data_gyr()
        {
            bnogyr sensorprint =  get_sensor_data_gyr();
            printf("GYR %3.2f %3.2f %3.2f\n", sensorprint.gdata_x, sensorprint.gdata_y, sensorprint.gdata_z);
        }

};

int main()
{

    exit(0);
}