.. include:: <mmlalias.txt>


VL53L1X: Proximity/Time-Of-Flight Sensor
========================================

This is a port of an Arduino implementation
(https://github.com/pololu/vl53l1x-arduino). It uses Linux userspace
I2C, as described in :ref:`2024-10-08-linux-and-i2c`.

See the :doc:`task description </project/tasks/proximity-vl53l1x>` for
additional info.

.. _open-issues-vl53l1x:

VL53L1X Open Issues
-------------------

.. _open-issues-vl53l1x-address-coordination:

VL53L1X Address Coordination
............................

VL53L1X is at 0x29 by default **but we have three of them**
|longrightarrow| coordination needed.

**Idea**

* Initially, hold all down via their XSHUT ("hardware suspend") pins

  * |longrightarrow| need a breakout which exposes XSHUT, and the
    interrupt pin too (see :ref:`open-issues-vl53l1x-heavy-polling`)
  * connect XSHUT to dedicated GPIOS

* Release one after the other, configuring addresses in software as we
  go
* Address coordination to be implemented in :doc:`initialization`

.. _open-issues-vl53l1x-heavy-polling:

VL53L1X: Polling: Heavy I2C And CPU Load
........................................

``VL53L1X::read_sensor()`` polls heavily (``while
(!dataReady())``). 

**Use interrupts instead!!**

.. _open-issues-vl53l1x-race-condition:

VL53L1X: Race Condition On I2C Bus
..................................

* I2C writes use *one* ``write()`` system call. This is
  uninterruptible (think: another process interleaves - *scheduling*),
  and that's what we need.
* I2C read, though, are split in two.

  * First, a ``write()`` (of two bytes - the address to be read from
    next) to the address register
  * Second, a ``read()`` of N bytes; implicitly from the address
    transmitted by the preceding ``write()``

  **This is a classic race condition!!**

Solution: don't use write/read non-atomically, but rather the
dedicated ``ioctl(I2C_RDWR)``

.. code-block:: c

   struct i2c_rdwr_ioctl_data {
       struct i2c_msg *msgs;   /* pointers to i2c_msgs */
       __u32 nmsgs;            /* number of i2c_msgs */
   };

