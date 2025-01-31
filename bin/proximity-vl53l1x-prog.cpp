#include <stdio.h>
#include <iostream>

#include <base/vl53l1x.h>

/** @brief VL53L1X Time-of-Flight (ToF) Sensor Usage

    This program is used for testing the Time-of-Flight sensor implementation.
    The standard I²C Adress is used (0x29).
 */


int main() {

    VL53L1X sensor(0x29);

    sensor.startContinuous(50);

    while(true)
    {
        std::cout << sensor.read_sensor() << std::endl;
     if (sensor.timeoutOccurred()) { std::cout << " TIMEOUT" << "\n" << std::endl; }
     usleep(1000000);
    }

    return 0;
}
