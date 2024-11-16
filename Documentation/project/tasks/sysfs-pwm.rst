.. ot-task:: crazycar.sysfs_pwm

.. include:: <mmlalias.txt>


DONE: PMW Abstraction On Top Of ``/sys/class/pwm/``
===================================================

.. contents::
   :local:

* See also
  :doc:`jfasch:trainings/material/soup/linux/hardware/pwm/topic`

Plan
----

.. code-block:: c++

   class PWMPin
   {
       // hmm, lets see ...
   };

For functionality, start with test, like ...

.. code-block:: c++

   PWMPin pwm7("/sys/class/pwm/pwmchip0/pwm7");

   uint64_t period = pwm7.period(); // read ./period
   uint64_t a_third = period/3;
   pwm7.set_duty_cycle(a_third);

Status
------

* 2024-11-05: done (`toolcase/base/sysfs-pwm-pin.h
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-pwm-pin.h>`__)

Facts
-----

* As an implementation detail (reading and writing small files in
  ``/sys/class/pwm/``)
* Use `class SysFSFile
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-file.h>`__
  to read and write e.g. ``/sys/class/pwm/pwmchip0/pin7/duty_cycle``.

  `How to use class SysFSFile
  <https://github.com/jfasch/FH-STECE2022/blob/main/tests/sysfs-file-tests.cpp>`__

* Implementation in `toolcase/base/sysfs-pwm-pin.h
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-pwm-pin.h>`__.

