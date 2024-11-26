#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <iostream>
#include <sys/time.h>

#include <VL53L1X.h>

#define I2C_DEV_FILE "/dev/i2c-1" // I2C-Gerätedatei für Raspberry Pi
#define VL53L1X_ADDR 0x29         // Standard-I2C-Adresse des VL53L1X

int main() {
    int file;
    
    const char *filename = I2C_DEV_FILE;

    // I2C-Gerät öffnen
    if ((file = open(filename, O_RDWR)) == -1) {
        perror("Failed to open the i2c bus");
        return 1;
    }
    // VL53L1X-Adresse festlegen
    if (ioctl(file, I2C_SLAVE, VL53L1X_ADDR) == -1) {
        perror("Failed to acquire bus access and/or talk to slave");
        return 1;
    }

    VL53L1X sensor(file);
    
    sensor.setTimeout(500);
    if (!sensor.init())
    {
        std::cout << "Failed to detect and initialize sensor!"<< std::endl;
        while (1);
    }

    sensor.setDistanceMode(VL53L1X::Long);
    sensor.setMeasurementTimingBudget(50000);
    std::cout << "Distancemode" << sensor.getDistanceMode() << std::endl;

    sensor.startContinuous(50);

    while(true)
    {
        std::cout << sensor.read_sensor() << std::endl;
        std::cout << ' ' << std::endl;
     if (sensor.timeoutOccurred()) { std::cout << " TIMEOUT" << "\n" << std::endl; }
    }

    close(file);

    return 0;
}
