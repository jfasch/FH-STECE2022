.. include:: <mmlalias.txt>


2024-12-09(3): Project
======================

.. contents::
   :local:

* :doc:`/project/tasks/driving-stage-1`

  * :doc:`/project/tasks/crazy-car`
  * :doc:`/project/tasks/commandline-driving`
  * :doc:`/project/tasks/hardware-init`
  * Do we have a list of hardware issues?

* FH-ECE21/toolcase/base/MQTT_publisher.h -> Kotschnig, Eingang
* centralize time: VL53L1X::millis(): beide sensor-gruppen

  * VL53L1X::checkTimeoutExpired(): overflow from uint16_t cast?

* open issues

  * VL53L1X address config and boot behavior

    * gyro is at 0x28 by default                                                                          
    * VL53L1X is at 0x29 by default BUT WE HAVE THREE OF THEM
    * order 3 VL53L1X breakouts with *six* pins (including XSHUT
      (hardware suspend)). jjj krenn which?
    * connect XSHUT to dedicated GPIOS
    * hold all in hardware suspend                                                                                        
    * release one after the other, configuring addresses in software
      as we go
    * to be implemented in bin/crazy-car-init

  * bigger caps for servo

  * i2c race condition in read calls -> don't use write/read
    non-atomically, but rather the dedicated ioctl(I2C_RDWR)

    struct i2c_rdwr_ioctl_data {
        struct i2c_msg *msgs;   /* pointers to i2c_msgs */
        __u32 nmsgs;            /* number of i2c_msgs */
    };

  * VL53L1X::read_sensor() polls heavily (while (!dataReady())). use
    interrupts instead

* todo

  * kotschnig sagen wegen race condition und time intervall abhaengig
    von genauigkeit
