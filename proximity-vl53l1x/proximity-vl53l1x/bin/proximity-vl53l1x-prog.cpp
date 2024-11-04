#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <iostream>

#include <VL53L1X.h>

#define I2C_DEV_FILE "/dev/i2c-1" // I2C-Gerätedatei für Raspberry Pi
#define VL53L1X_ADDR 0x29         // Standard-I2C-Adresse des VL53L1X

// Funktion zum Schreiben eines Wertes auf den Sensor
int i2c_write(int file, uint8_t reg, uint8_t value) {
    uint8_t buf[2] = {reg, value};
    if (write(file, buf, 2) != 2) {
        return -1; // Fehler beim Schreiben
    }
    return 0;
}

// Funktion zum Lesen eines Wertes vom Sensor
int i2c_read(int file, uint8_t reg, uint8_t *buf, uint8_t len) {
    if (write(file, &reg, 1) != 1) {
        return -1; // Fehler beim Setzen des Registers
    }
    if (read(file, buf, len) != len) {
        return -1; // Fehler beim Lesen
    }
    return 0;
}



int main() {
    int file;

    const char *filename = I2C_DEV_FILE;

    // I2C-Gerät öffnen
    if ((file = open(filename, O_RDWR)) < 0) {
        perror("Failed to open the i2c bus");
        return -1;
    }
    // VL53L1X-Adresse festlegen
    if (ioctl(file, I2C_SLAVE, VL53L1X_ADDR) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        return -1;
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

    sensor.startContinuous(50);

    while(true)
    {
      std::cout << sensor.read() << std::endl;
     if (sensor.timeoutOccurred()) { std::cout << " TIMEOUT" << "\n" << std::endl; }
    }






/*


    // Sensor initialisieren (z.B. Start der Messung)
    // Hier kann je nach Bedarf ein Initialisierungscode hinzugefügt werden
    i2c_write(file, 0x00, 0x01); // Beispielhafte Initialisierung

    // Warten auf Messung (hier ggf. Verzögerung oder Polling)
    sleep(1);

    // Entfernung auslesen (Register 0x01 für Distance High und Low Byte)
    if (i2c_read(file, 0x01, distance_buf, 2) < 0) {
        perror("Failed to read distance data");
        return -1;
    }

    // Entfernung berechnen (High-Byte + Low-Byte)
    uint16_t distance = (distance_buf[0] << 8) | distance_buf[1];
    printf("Measured Distance: %d mm\n", distance);
*/
    // I2C-Gerät schließen
    close(file);

    return 0;
}
