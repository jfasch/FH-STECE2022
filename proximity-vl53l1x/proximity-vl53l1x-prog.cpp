#include <stdio.h>
#include <iostream>

#include <base/vl53l1x.h>


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
