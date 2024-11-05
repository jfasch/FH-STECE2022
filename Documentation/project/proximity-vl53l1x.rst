.. ot-topic:: crazycar.proximity_vl53l1x

.. include:: <mmlalias.txt>


Proximity Sensor: VL53L1X
=========================

.. contents::
   :local:

.. sidebar:: Lecture Coverage

   * :ref:`2024-10-08-linux-and-i2c`

Facts
-----

Time-of-Flight (ToF) ranging sensor.

* Breakout board: https://shop.pimoroni.com/products/vl53l1x-breakout
* Data sheet:
  https://www.st.com/en/imaging-and-photonics-solutions/vl53l1x.html

Arduino Implementation
----------------------

* Arduino: https://github.com/pololu/vl53l1x-arduino

Notes
-----

* There is a Linux implementation,
  https://github.com/mjbogusz/vl53l1x-linux, but lets not use that (it
  handles the address change operation in a way that we don't want).
* The device emits interrupts |longrightarrow| how could we make use
  of them?
* Linux kernel driver exists for VL53L0X
  https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c

  User space access for that driver yet unclear, research needed

