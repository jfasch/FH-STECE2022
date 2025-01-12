#include "crazy-car-config.h"

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <RPM>\n";
        return 1;
    }
    int rpm = std::stoi(argv[1]);

    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_WRONLY);
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    CrazyCarMessage msg = {
        .command = MOTOR_SET_FRACTION_SPEED_PERCENT,
        .value = rpm
    };

    unsigned int priority = 0;

    ssize_t n_bytes_written = mq_send(message_queue, (char*)&msg, sizeof(msg), priority);
    if (n_bytes_written == -1) {
        perror("mq_send");
        return 1;
    }
    assert(n_bytes_written == 0);

    return 0;
}
