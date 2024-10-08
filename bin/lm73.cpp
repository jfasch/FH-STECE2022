#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <linux/i2c-dev.h>

using namespace std;

int main(int argc, char** argv)
{
    int err, dev_fd;

    if (argc != 2) {
        cerr << argv[0] << " i2c-device" << endl;
        return 1;
    }

    if ((dev_fd = open(argv[1], O_RDWR)) == -1) {
        perror("open");
        return 1;
    }

    if ((err = ioctl(dev_fd, I2C_SLAVE, 0x49)) == -1) {
        perror("set address");
        return 1;
    }

    /* set register address for next read operation */
    uint8_t byte = 0x0;
    if ((err = write(dev_fd, &byte, 1)) != 1) {
        cerr << err << endl;
        perror("write");
        return 1;
    }

    /* read temperature */
    uint8_t msb_lsb[2];
    if ((err = read(dev_fd, msb_lsb, 2)) != 2) {
        perror("read");
        return 1;
    }

    close(dev_fd);

    cout << (double)((msb_lsb[0]<<24)|(msb_lsb[1]<<16)) / 65535 / 128 << endl;
    return 0;
}
