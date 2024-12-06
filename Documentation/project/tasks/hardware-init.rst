.. ot-task:: crazycar.hardware_init

.. include:: <mmlalias.txt>


(ACTIVE) Hardware Initialization
================================

.. contents::
   :local:

Plan
----

Centralize hardware initialization in one single place, see
`bin/crazy-car-init.cpp
<https://github.com/jfasch/FH-STECE2022/blob/main/bin/crazy-car-init.cpp>`__

The driving software `bin/crazy-car.cpp
<https://github.com/jfasch/FH-STECE2022/blob/main/bin/crazy-car.cpp>`__
will then pick up the properly initialized hardware, and work with it.

**List of hardware pieces** (to be extended)

* Create message queue
* Export necessary PWM pins, and configure accordingly

  * set ``period`` to a value that the hardware supports
  * set ``duty_cycle`` to 0
  * set ``enable`` to 1 (is that necessary? cannot hurt at least)

* Export necessary GPIO pins, and configure them accordingly

  * Set ``direction`` to ``out``
  * Set ``value`` to 0

Notes
-----

This task is the software counterpart of
:doc:`crazy-pi`. Communication absolutely necessary.
