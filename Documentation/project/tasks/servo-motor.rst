.. ot-task:: crazycar.servo_motor
   :dependencies: crazycar.sysfs_pwm

.. include:: <mmlalias.txt>


ACTIVE: RC Servo Control
========================

.. contents::
   :local:

.. sidebar:: Lecture Coverage

   * :ref:`2024-10-08-linux-and-pwm`
   * :ref:`2024-10-08-linux-and-spi`

Plan
----

Use :doc:`sysfs-pwm`. In a TDD style (see
:doc:`jfasch:trainings/material/soup/unittest/group`), wrap a class
around it, like

.. code-block:: c++

   SysFSPWMPin my_pin("/sys/class/pwm/pwmchip0/pwm7");
   Servo my_servo(my_pin);
   my_servo.set(-73); // -100: max left; 0: middle; 100: max right

Status
------

* 2024-11-05: ongoing. Test written.

* 2024-11-25

  * Pi PWM goes mad. Tried with systemd servie, does not work. Maybe
    use PCA on CrazyPi.
  * Error handling

Notes
-----

* `Guide to PWM and PPM <http://www.endurance-rc.com/ppmtut.php>`__
* `RC Hobby Servo PWM vs PPM
  <https://www.codrey.com/learn/rc-hobby-servo-pwm-vs-ppm/>`__
