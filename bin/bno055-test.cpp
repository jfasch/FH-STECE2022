#include <base/bno055-class.h>
#include <iostream>
#define ADDR "0x28";
#define I2CBUS1 "/dev/i2c-1";

int main()
{

    bno SensorData;
    char senaddr[256] = ADDR;
    char i2c_bus[256] = I2CBUS1;
    Bno055 sensor(i2c_bus, senaddr);
    while(1)
    {
        SensorData = sensor.get_sensor_data_gyr();
        std::cout <<"Gyroscope: X " <<SensorData.data_x<<"Y "<<SensorData.data_y<<"Z "<<SensorData.data_z<<std::endl;
        SensorData = sensor.get_sensor_data_eul();
        std::cout <<"Orientation: "<<SensorData.data_x<<std::endl;
        sleep(1);
    }

}