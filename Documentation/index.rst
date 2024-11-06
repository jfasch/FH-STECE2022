.. include:: <mmlalias.txt>


Crazy Car NG, Running Linux
===========================

.. contents::
   :local:

.. sidebar::

   * Github Project: https://github.com/jfasch/FH-STECE2022

Project Goal: Create Toolcase And Reference Architecture
--------------------------------------------------------

Hardware Toolcase
.................

Create Linux implementations for the hardware devices that are found
on a car. These implementations should be usable from many possible
architectures, including the reference architecture below, but also
from more static architectures.

* :doc:`project/proximity-vl53l1x`
* :doc:`project/gyroscope-bno055`
* :doc:`project/motor-control-btn9960lv`
* :doc:`project/servo-motor`
* :doc:`project/sysfs-pwm`

**What's to come?**

* Device calibration
* Acceleration ramps on top of motor control
* More such assets on top of the bare hardware

Reference Architecture
----------------------

Given a working toolcase that we can use code out of, a reference
architecture can be implemented. This architecture should be comprised
of components that are loosely coupled for several reasons:

#. Mix languages. For example, use Python for non-realtime
   responsibilities like cloud communication (MQTT)
#. Provide different setups. For example, optionally replay recorded
   sensor inputs into an unmodified steering component - without
   having the hardware sensors available
#. Testability

.. image:: architecture.svg

Project Plan
------------

.. toctree::
   :maxdepth: 1

   project/group

Further Information
-------------------

* Crazy Car NG Schematics:
  :download:`Schematic_and_print_CrazyCar.pdf`

Meetings, Hacking Sessions
--------------------------

.. toctree::
   :maxdepth: 1

   2024-10-08/index
   2024-10-23/index
   2024-10-29/index
   2024-11-05/index

What Else?
----------

.. toctree::
   :maxdepth: 1

   queue
