.. ot-task:: crazycar.gyro_bno055

.. include:: <mmlalias.txt>


ACTIVE: Gyroscope (BNO055)
==========================

.. contents::
   :local:

Plan
----

https://github.com/fm4dd/pi-bno055 is a nice commandline tool (under
the MIT license) that appears to work. It is not entirely object
oriented, and it has global variables. Code is clearly structured
though.

Rip it apart, and create a class that can be used like so:

.. code-block:: c++

   BNO055 my_sensor("/dev/i2c-1", 0x23 /*whatever the address is*/);
   auto acc_vector = my_sensor.get_acc(); // and more such methods
   cout << acc_vector.x << ',' << acc_vector.y << ',' << acc_vector.z << '\n';

Status
------

* 2024-11-05: ongoing

Notes
-----

* Terminology:
  https://www.nxp.com/docs/en/quick-reference-guide/SENSORTERMSPG.pdf
* Breakout board:
  https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/arduino-code
* Datasheet:
  https://cdn-learn.adafruit.com/assets/assets/000/125/776/original/bst-bno055-ds000.pdf
* The device emits interrupts |longrightarrow| how could we make use
  of them?
* Arduino Bosch "driver":
  https://github.com/boschsensortec/BNO055_SensorAPI
