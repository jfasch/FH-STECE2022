#include <unistd.h>
#include <sched.h>
#include <stdio.h>


int main()
{ 
    sched_param param = { .sched_priority = SCHED_FIFO };

    int error = sched_setscheduler(getpid(), SCHED_FIFO, &param);
    if (error) {
        perror("sched_setscheduler");
        return 1;
    }

    return 0;
}
