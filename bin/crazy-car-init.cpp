#include <ipc/vehicle-protocol.h>

#include <mqueue.h>
#include <cstdio>


int main()
{
    struct mq_attr attr = {
        .mq_maxmsg = 10,
        .mq_msgsize = sizeof(VehicleMessage)
    };
    
    mqd_t message_queue = mq_open("/crazy-car", O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }
    return 0;
}
