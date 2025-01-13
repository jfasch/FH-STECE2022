#include <stdio.h>
#include <iostream>

#include "VL53L1X.h"

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
