.. include:: <mmlalias.txt>


2024-11-25(3): Project
======================

.. contents::
   :local:

Org
---

* **Licensing**

  * We are under the `GPLv3
    <https://www.gnu.org/licenses/gpl-3.0.en.html>`__
  * BNO055 source was under MIT right? Please check, should be added
    as a note to :doc:`/project/tasks/gyroscope-bno055`.

* **MAC Adresses**

  * Do we have a list?

Material
--------

* :doc:`jfasch:trainings/material/soup/linux/sysprog/ipc-mqueue/topic`
* signed vs. unsigned: C/C++ lets you mix unsigned and signed entities
  as you want. one has to be careful.

  Look in `toolcase/base/sysfs-servo.cpp
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-servo.cpp>`__

Project
-------

* Architecture: Xbox, message queue
* Anyone for :doc:`/project/tasks/remote-control`?
* ``SysFS_Servo``: talk about usage

  * How is min/mid/max related to PWM period? Shouldn't those be
    calculated from period?
