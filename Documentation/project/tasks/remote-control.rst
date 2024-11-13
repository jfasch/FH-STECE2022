.. ot-task:: crazycar.remote_control
   :dependencies: crazycar.servo_motor,
                  crazycar.motor_control_btn9960lv

.. include:: <mmlalias.txt>


Xbox Remote Control (Manual Driving)
====================================

.. contents::
   :local:

Plan
----

Once :doc:`motor-control-btn9960lv` and :doc:`servo-motor` are usable,
we can use a remote control (XBox? Playstation? see below) to drive
the car.

We can then record sensor values as we drive, for example; see
:doc:`sensor-mqtt` and :doc:`sensor-csv`.

**XBox Controller**

There are three XBox controller clones (`GXT 590 Bosi
<https://www.trust.com/de/product/22258-gxt-590-bosi-bluetooth-wireless-gamepad>`__)
available.

This should be doable, provided that the `GXT 590 Bosi
<https://www.trust.com/de/product/22258-gxt-590-bosi-bluetooth-wireless-gamepad>`__
works with the `"xbox360controller" Python library
<https://github.com/linusg/xbox360controller>`__. That package is
available on `PyPI <https://pypi.org/project/xbox360controller/>`__
(see :doc:`here <jfasch:trainings/material/soup/python/swdev/group>`
for what PyPI is). Under the MIT license, which is compatible to use
with ours (GPLv3). **Implementation language: Python**

**Fallback: Playstation**

One `DualShock <https://en.wikipedia.org/wiki/DualShock>`__
("DualShock 3 Sixaxis", for that matter) controller is available. We'd
have to share it with another project though.

Status
------

Not yet started

Notes
-----

Open source remote control implementations:

* https://pypi.org/project/xbox360controller/
* http://xwiimote.github.io/xwiimote/
* https://www.baeldung.com/linux/android-remote-control
* https://wiki.archlinux.org/title/Gamepad
