.. ot-topic:: crazycar.servo_motor
   :dependencies: crazycar.sysfs_pwm

.. include:: <mmlalias.txt>


RC Servo Motor Control
======================

.. contents::
   :local:

.. sidebar:: Lecture Coverage

   * :ref:`2024-10-08-linux-and-pwm`
   * :ref:`2024-10-08-linux-and-spi`

Facts
-----

* `Guide to PWM and PPM <http://www.endurance-rc.com/ppmtut.php>`__
* `RC Hobby Servo PWM vs PPM
  <https://www.codrey.com/learn/rc-hobby-servo-pwm-vs-ppm/>`__

Notes
-----

* Discrete pre-configured servo positions
* Userspace SPI 

Software Interface
------------------

.. code-block:: c++

   class DerEineRCServoUeberPWM
   {
       // hmm ... find out ...
   };

**Usage/Unit test**

.. code-block:: c++

   DerEineRCServoUeberPWM rc(pwm7);
   rc.set(0.0); // middle position

   double degrees = -45.7;

   rc.set_absolute_angle(degrees); // 45.7 degrees left


