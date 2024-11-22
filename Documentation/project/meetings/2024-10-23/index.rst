.. include:: <mmlalias.txt>


2024-10-23(6): Project: Linux I2C/PWM/SPI
=========================================

.. contents::
   :local:

I2C
---

Our project has two I2C devices that need to be programmed from
userspace (we want to create prototypes that can be used in other
contexts, and therefore cannot use Linux kernel drivers).

These devices are:

* :doc:`/project/tasks/proximity-vl53l1x`
* :doc:`/project/tasks/gyroscope-bno055`

Go over Linux userspace I2C:

* :doc:`jfasch:trainings/material/soup/linux/hardware/i2c/topic`

Explain difference between userspace I2C, and a kernel driver -
coincidentally using a driver for a PWM device:

* :doc:`jfasch:trainings/material/soup/linux/hardware/pwm/topic`

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Userspace I2C
     * Reading device registers
     * Kernel OO/UML
   * * .. image:: userspace-i2c.jpg
     * .. image:: userspace-i2c-read-registers.jpg
     * .. image:: kernel-oo.jpg

PWM
---

* :doc:`/project/tasks/motor-control-btn9960lv`

  That device is controlled via two PWM channels. The Raspberry has
  only one (pin 18 has an alternative setting), so we use a PCA9685
  which is connected over I2C.

  |longrightarrow|
  :doc:`jfasch:trainings/material/soup/linux/hardware/pwm/topic`

* :doc:`/project/tasks/servo-motor`
