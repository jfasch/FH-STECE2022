#include "bno055-class.h"
#include "millis.h"
#include <iostream>
#include <cstdio>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/time.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

Bno055::Bno055(char i2cbus[256], char i2caddr[256])
{
    if((_i2cfd = open(i2cbus, O_RDWR)) < 0) {
        std::string i2cbus_string = i2cbus;
        throw std::runtime_error("Error failed to open I2C bus " + i2cbus_string);
    }
    if(_message == 1) printf("Debug: I2C bus device: [%s]\n", i2cbus);
    /* --------------------------------------------------------- *
    * Set I2C device (BNO055 I2C address is  0x28 or 0x29)      *
    * --------------------------------------------------------- */
    int addr = (int)strtol(i2caddr, NULL, 16);
    if(_message == 1) printf("Debug: Sensor address: [0x%02X]\n", addr);

    if(ioctl(_i2cfd, I2C_SLAVE, addr) != 0) {
        throw std::runtime_error("Error can't find sensor at address " + std::to_string(addr));
    }
    /* --------------------------------------------------------- *
    * I2C communication test is the only way to confirm success *
    * --------------------------------------------------------- */
    char reg = BNO055_CHIP_ID_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure register " + std::to_string(reg) + ", sensor addr" + std::to_string(addr) + "?");
    }
    opmode_t newmode = imu;
    set_mode(newmode);
                    
}

void Bno055::debug_message()
{
    _message = 1;
}

void Bno055::power_mode(power_t pwrmode)
{

    // get current mode
    int reg = BNO055_OPR_MODE_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
    }
    unsigned int olddata = 0;
    if(read(_i2cfd, &olddata, 1) != 1) {
        throw std::runtime_error("Error: I2C read failure for register data " + std::to_string(reg));
    }

    // set config mode if not in config mode
    char data[2] = {0};
    data[0] = BNO055_OPR_MODE_ADDR;
    power_t oldmode = (power_t)(olddata & 0x0F);
    if(oldmode == pwrmode) 
    {
        if(_message == 1) printf("Debug: Sensor is already in this mode"); // if new mode is the same
    } 
    else if(oldmode > 0 && pwrmode > 0) // switch to "config" first
    {  
        data[1] = 0x0;
        if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
        if(write(_i2cfd, data, 2) != 2) 
        {
            throw std::runtime_error("Error: I2C write failure for register " + std::to_string(data[0]));
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
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(data[0]));
    }
    usleep(30 * 1000);
}

void Bno055::set_mode(opmode_t newmode)
{
    // get current mode
    int reg = BNO055_OPR_MODE_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
    }
    unsigned int olddata = 0;
    if(read(_i2cfd, &olddata, 1) != 1) {
        throw std::runtime_error("Error: I2C read failure for register " + std::to_string(reg));
    }

    // set config mode if not in config mode
    char data[2] = {0};
    data[0] = BNO055_OPR_MODE_ADDR;
    opmode_t oldmode = (opmode_t)(olddata & 0x0F);
    if(oldmode == newmode) 
    {
        if(_message == 1) printf("Debug: Sensor is already in this mode"); // if new mode is the same
    }
    else if(oldmode > 0 && newmode > 0) // switch to "config" first
    {  
        data[1] = 0x0;
        if(_message == 1) printf("Debug: Write opr_mode: [0x%02X] to register [0x%02X]\n", data[1], data[0]);
        if(write(_i2cfd, data, 2) != 2) 
        {
            throw std::runtime_error("Error: I2C write failure for register " + std::to_string(data[0]));
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
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(data[0]));
    }
}

void Bno055::reset()
{
    char data[2];
    data[0] = BNO055_SYS_TRIGGER_ADDR;
    data[1] = 0x20;
    if(write(_i2cfd, data, 2) != 2) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(data[0]));
    }

    //wait till sensor is ready after reset
    usleep(650 * 1000);

    if(_message == 1) printf("Debug: BNO055 Sensor Reset complete\n");
}

void Bno055::dump()
{
    int count = 0;

    while(count < 8) {
        char reg = count;
        if(write(_i2cfd, &reg, 1) != 1) {
            throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
        }

        char data[16] = {0};
        if(read(_i2cfd, &data, 16) != 16) {
            throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));               
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
    if(_message == 1)
    {
        printf("Debug: write page-ID: [0x%02X] to register [0x%02X]\n", datapage1[1], datapage1[0]);
    }
    if(write(_i2cfd, datapage1, 2) != 2) 
    {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(datapage1[0]));
    }
    usleep(50 * 1000);
    count = 0;
    while(count < 8) {
        char reg = count;
        if(write(_i2cfd, &reg, 1) != 1) {
            throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
        }

        char data[16] = {0};
        if(read(_i2cfd, &data, 16) != 16) {
            throw std::runtime_error("Error: I2C read failure for register " + std::to_string(reg));               
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
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(datapage0[0]));
    }
    usleep(50 * 1000);
}

bno Bno055::get_sensor_data_gyr()
{
    bno sensordata;

    char reg = BNO055_GYRO_DATA_X_LSB_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
    }

    char data[6] = {0};
    if(read(_i2cfd, data, 6) != 6) {
        throw std::runtime_error("Error: I2C read failure for register " + std::to_string(reg));
    }

    int16_t buf = ((int16_t)data[1] << 8) | data[0];
    if(_message == 1) printf("Debug: Gyroscope Data X: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[0], data[1],buf);
    sensordata.data_x = (double) buf / 16.0;

    buf = ((int16_t)data[3] << 8) | data[2];
    if(_message == 1) printf("Debug: Gyrosscope Data Y: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[2], data[3],buf);
    sensordata.data_y = (double) buf / 16.0;

    buf = ((int16_t)data[5] << 8) | data[4];
    if(_message == 1) printf("Debug: Gyroscope Data Z: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[4], data[5],buf);
    sensordata.data_z = (double) buf / 16.0;

    return sensordata;
}

bno Bno055::get_sensor_data_eul()
{
    bno sensordata;

    char reg = BNO055_EULER_H_LSB_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
    }

    char data[6] = {0};
    if(read(_i2cfd, data, 6) != 6) {
        throw std::runtime_error("Error: I2C read failure for register " + std::to_string(reg));
    }

    int16_t buf = ((int16_t)data[1] << 8) | data[0];
    if(_message == 1) printf("Debug: Gyroscope Data X: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[0], data[1],buf);
    sensordata.data_x = (double) buf / 16.0;

    buf = ((int16_t)data[3] << 8) | data[2];
    if(_message == 1) printf("Debug: Gyrosscope Data Y: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[2], data[3],buf);
    sensordata.data_y = (double) buf / 16.0;

    buf = ((int16_t)data[5] << 8) | data[4];
    if(_message == 1) printf("Debug: Gyroscope Data Z: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[4], data[5],buf);
    sensordata.data_z = (double) buf / 16.0;

    return sensordata;
}

bno Bno055::get_sensor_data_acc()
{
    bno sensordata;

    char reg = BNO055_GYRO_DATA_X_LSB_ADDR;
    if(write(_i2cfd, &reg, 1) != 1) {
        throw std::runtime_error("Error: I2C write failure for register " + std::to_string(reg));
    }

    char data[6] = {0};
    if(read(_i2cfd, data, 6) != 6) {
        throw std::runtime_error("Error: I2C read failure for register " + std::to_string(reg));
    }

    int16_t buf = ((int16_t)data[1] << 8) | data[0];
    if(_message == 1) printf("Debug: Gyroscope Data X: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[0], data[1],buf);
    sensordata.data_x = (double) buf;

    buf = ((int16_t)data[3] << 8) | data[2];
    if(_message == 1) printf("Debug: Gyrosscope Data Y: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[2], data[3],buf);
    sensordata.data_y = (double) buf;

    buf = ((int16_t)data[5] << 8) | data[4];
    if(_message == 1) printf("Debug: Gyroscope Data Z: LSB [0x%02X] MSB [0x%02X] INT16 [%d]\n", data[4], data[5],buf);
    sensordata.data_z = (double) buf;

    return sensordata;
}

void Bno055::csv_bno055_create(char csvfile[256], bool newfile)
{

    bno SensorData;

    std::ifstream ifcsv;
    ifcsv.open(csvfile);
    if (!ifcsv || newfile) 
    {
        std::ofstream csv(csvfile);
        csv << "Time,Orientation,GyrX,GyrY,GyrZ,AccX,AccY,AccZ" << std::endl;
        csv.close();
        newfile = 0;
    }
    std::ofstream csv;
    csv.open(csvfile, std::ofstream::app);

    csv << millis() << ",";
    SensorData = get_sensor_data_eul();
    csv << SensorData.data_x << ",";
    SensorData = get_sensor_data_gyr();
    csv << SensorData.data_x << "," << SensorData.data_y << "," << SensorData.data_z << ",";
    SensorData = get_sensor_data_acc();
    csv << SensorData.data_x << "," << SensorData.data_y << "," << SensorData.data_z << std::endl;

    csv.close();

}
