.. include:: <mmlalias.txt>


2024-11-05(6): Project, Sysprog Recap
=====================================

.. contents::
   :local:

Org
---

* Clarify licensing status

  * used training material (faschingbauer.me) is GPL3
  * also on faschingbauer.me: project management, design docs, thereby
    *that* material is also under GPL3
  * No specific license: https://github.com/jfasch/FH-STECE2022 (this
    year's EC2 project) and https://github.com/jfasch/FH-ENDLESS (my
    contributions to it)

    Which license to pick? -> https://choosealicense.com/

* Define hardware (task group) owner

Material
--------

* Recap ``class point``. Emphasize on ``const``, and initialization
* signed vs. unsigned: ``SysFSPWMPin`` has a mixture of ``uint64_t``
  and ``int64_t``. Should take care, mostly about semantics:
  ``period`` and ``duty_cycle`` cannot become negative, so these
  should possibly be unsigned. But how about conversion to
  ``SysFSFile``'s methods, which currently only take
  ``int64_t``. Solution: check for overflow/conversion, or add
  ``uint64_t`` methods to ``SysFSFile``.

Project
-------

* :ref:`fh-2022--2024-10-29-homework`
* Software implications: aggregating objects into instances of higher
  level types

    * Show :doc:`../project/sysfs-pwm`
    * :doc:`../project/servo-motor`, which aggregates a :doc:`../project/sysfs-pwm`
    * :doc:`../project/motor-control-btn9960lv`, which aggregates one
      or two :doc:`../project/sysfs-pwm`

* :doc:`../project/motor-control-btn9960lv`

  * How's it with hardware? Do we need 2 PWMs, or just one?

    * Ask for permission of car layout docs -> put it in repo

  * How's it with software? Write test together.

* :doc:`../project/servo-motor`

  * How's it with software? Write test together.

* :doc:`../project/proximity-vl53l1x`: talk about usage sketch of
  ``class VL53L1X``
* :doc:`../project/gyroscope-bno055`: talk about usage sketch of
  ``class BNO055``

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
