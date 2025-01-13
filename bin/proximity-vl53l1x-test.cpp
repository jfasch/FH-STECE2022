#include <stdio.h>
#include <iostream>

<<<<<<<< HEAD:proximity-vl53l1x/proximity-vl53l1x-prog.cpp
#include "VL53L1X.h"
========
#include <base/vl53l1x.h>
>>>>>>>> upstream/main:bin/proximity-vl53l1x-test.cpp

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
