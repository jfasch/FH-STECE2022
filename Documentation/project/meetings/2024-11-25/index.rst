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

  Look in `toolcase/base/servo.cpp
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/servo.cpp>`__

Project
-------

* Architecture: Xbox, message queue
* Anyone for :doc:`/project/tasks/remote-control`?
* :doc:`/project/tasks/sysfs-pwm`: clarify we do not want
  ``gpiochipN/export`` in a PWM pin object. A PWM pin object does not
  allocate resources, the resources are there, and it manages
  them. Setup code, for before the user code, must be executed by
  something that is closer to machine boot.
* :doc:`/project/tasks/servo-motor`

  * What does the class look like?

* :doc:`/project/tasks/motor-control-btn9960lv`

  * What does the class look like?

* :doc:`/project/tasks/proximity-vl53l1x`

  * What does the class look like?

* :doc:`/project/tasks/gyroscope-bno055`

  * What does the class look like?
