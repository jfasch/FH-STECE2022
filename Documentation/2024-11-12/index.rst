.. include:: <mmlalias.txt>


2024-11-12(6): Project, Future
==============================

.. contents::
   :local:

Org
---

* **Licensing**

  * We are under the `GPLv3
    <https://www.gnu.org/licenses/gpl-3.0.en.html>`__
  * BNO055 source was under MIT right? Please check, should be added
    as a note to :doc:`../project/gyroscope-bno055`.

* **MAC Adresses**

  * Do we have a list?

Material
--------

* signed vs. unsigned: ``SysFSPWMPin`` has a mixture of ``uint64_t``
  and ``int64_t``. Should take care, mostly about semantics:
  ``period`` and ``duty_cycle`` cannot become negative, so these
  should possibly be unsigned. But how about conversion to
  ``SysFSFile``'s methods, which currently only take
  ``int64_t``. Solution: check for overflow/conversion, or add
  ``uint64_t`` methods to ``SysFSFile``.

Project
-------

* :doc:`../project/sysfs-pwm`: clarify we do not want
  ``gpiochipN/export`` in a PWM pin object. A PWM pin object does not
  allocate resources, the resources are there, and it manages
  them. Setup code, for before the user code, must be executed by
  something that is closer to machine boot.
* :doc:`../project/servo-motor`

  * What does the class look like?

* :doc:`../project/motor-control-btn9960lv`

  * What does the class look like?

* :doc:`../project/proximity-vl53l1x`

  * What does the class look like?

* :doc:`../project/gyroscope-bno055`

  * What does the class look like?

Homework
--------

* ``ip addr``
* Someone to implement signed/unsigned? |longrightarrow|
  `std::stoull()
  <https://en.cppreference.com/w/cpp/string/basic_string/stoul>`__

Myself

* create git page, and link it to course main page
* ``./fh-stece22-suite: /usr/lib/arm-linux-gnueabihf/libstdc++.so.6:
  version `GLIBCXX_3.4.26' not found (required by
  ./fh-stece22-suite)``
* uint64/int64 woes (pwm vs. sysfsfile) -> see existing commented-out
  test
