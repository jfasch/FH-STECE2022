.. ot-task:: crazycar.proximity_vl53l1x

.. include:: <mmlalias.txt>


ACTIVE: Proximity Sensor: VL53L1X
=================================

.. contents::
   :local:

Plan
----

Arduino implementation (https://github.com/pololu/vl53l1x-arduino) is
known to work - colleagues are using it. Port it to Linux, following
:ref:`2024-10-08-linux-and-i2c`.

Status
------

* 2024-11-05: ongoing. Reading sensor data yields an all-zeroes block
  (?).
* 2024-11-25. stops working at setcontinuous, which is the first 32bit
  write.

  * try lowering i2c frequency. what does original arduino
    implementation use?
  * check with a scope (comparing arduino and pi)

Notes
-----

* Breakout board: https://shop.pimoroni.com/products/vl53l1x-breakout
* Data sheet:
  https://www.st.com/en/imaging-and-photonics-solutions/vl53l1x.html
* There is a Linux implementation,
  https://github.com/mjbogusz/vl53l1x-linux, but lets not use that (it
  handles the address change operation in a way that we don't want).
* The device emits interrupts |longrightarrow| how could we make use
  of them?
* Linux kernel driver exists for VL53L0X
  https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c

  User space access for that driver yet unclear, research needed

