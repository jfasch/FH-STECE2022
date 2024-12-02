#include "crazy-car-config.h"

#include <ipc/crazy-car-protocol.h>

#include <mqueue.h>
#include <cstdio>


int main()
{
    struct mq_attr attr = {
        .mq_maxmsg = 10,
        .mq_msgsize = sizeof(CrazyCarMessage)
    };
    
    mqd_t message_queue = mq_open(CRAZY_CAR_MQ_NAME, O_CREAT|O_EXCL|O_RDWR, 0666, &attr);
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }


    // configure pwms and gpios according to config

    // write sysfs files, use "#include <sysfs-file.h>" for this ...

    // * export pwm pins
    //   * period (and set duty_cycle to 0?)
    // * export gpio pins
    //   * direction out
    //   * value 0?

    // like so ...

    // SysFS_File(printf("/sys/class/pwm/pwmchip%d/pwm%d/export", motor_pwm_config.chip, motor_pwm_config.pin)).write_string("1");
    // SysFS_File("/sys/class/pwm/pwmchip%d/pwm%d/period", 
    //            motor_pwm_config.chip, motor_pwm_config.pin).write_uint64(motor_pwm_config.period);

    return 0;
}
