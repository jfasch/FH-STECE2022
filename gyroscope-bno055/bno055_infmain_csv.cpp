#include "bno055_class.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#define ADDR "0x28";
#define I2CBUS1 "/dev/i2c-1";
#define CSVFILE "sensor_data.csv";
#define NEWFILE false;

int main()
{
    bno SensorData;

    char senaddr[256] = ADDR;
    char i2c_bus[256] = I2CBUS1;
    char csvfile[256] = CSVFILE;
    bool newfile = NEWFILE;
    Bno055 sensor(i2c_bus, senaddr);
    while(1)
    {

        sensor.print_sensor_data_gyr();
        sensor.print_sensor_data_acc();
        SensorData = sensor.get_sensor_data_eul();
        std::cout <<"Orientation:"<<SensorData.data_x<<std::endl;
        sleep(1);
        
        std::ifstream ifcsv;
        ifcsv.open(csvfile);
        if (!ifcsv || newfile) 
        {
            std::ofstream csv(csvfile);
            csv << "Oriantation,GyrX,GyrY,GyrZ,AccX,AccY,AccZ" << std::endl;
            csv.close();
            newfile = 0;
        }
        std::ofstream csv;
        csv.open(csvfile, std::ofstream::app);

        SensorData = sensor.get_sensor_data_eul();
        csv << SensorData.data_x << ",";
        SensorData = sensor.get_sensor_data_gyr();
        csv << SensorData.data_x << "," << SensorData.data_y << "," << SensorData.data_z << ",";
        SensorData = sensor.get_sensor_data_acc();
        csv << SensorData.data_x << "," << SensorData.data_y << "," << SensorData.data_z << "," << std::endl;

        csv.close();

    }
}
