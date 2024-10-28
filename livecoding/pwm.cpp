#include <gpio.h>

int main()
{
    GPIO io(18, OUT);

    // RT properties in Linux

    bool state = false;
    while (true) {
        io.set(state);
        sleep(10us);
        state = !state;
    }

    return 0;
}
