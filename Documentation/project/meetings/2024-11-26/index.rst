.. include:: <mmlalias.txt>


2024-11-26(3): Project
======================

.. contents::
   :local:

Org
---

* readthedocs -> dev documentation (jjj todo screenplay of steps, draw
  on whiteboard)
* Project task list restructured, jjj link and explain
* 80 20 regel

  * nun bei den restlichen 80 angekommen, plus ein paar features und
    nun lernen wir c++ :-)

Show
----

Github and Git: Project Management
..................................

* as user (you)

  * fork
  * clone
  * push pull among team
  * pull request

  * pull upstream changes

    * whats a remote
    * pulling from there (upstream)

* switch hat to me (link me@gh jjj)

  * execute pull request
  * show what gh says on pr page, explain with a shetch
  * whine a little

    * show how I can rely on tests
    * absolutely neccessary in large scale development -> linux kernel
      (gh is kindergarten)

Development, Including ``sshfs``
................................

.. toctree::

   sshfs

Project Status
--------------

Car Itself
..........

* Will close tasks soon

  * :doc:`/project/tasks/motor-control-btn9960lv`
  * :doc:`/project/tasks/servo-motor`
  * :doc:`/project/tasks/crazy-pi`

* In favor of steering application

  * :doc:`/project/tasks/commandline-driving`
  * :doc:`/project/tasks/crazy-car`

  |longrightarrow|
  :doc:`jfasch:trainings/material/soup/linux/sysprog/ipc-mqueue/topic`
  
* We will need a defined human/human interface between hardware and
  software

  * :doc:`/project/tasks/hardware-init`

Sensors
.......

* :doc:`/project/tasks/gyroscope-bno055`

  * Address conflict with the proximity sensor
  * Close task in favor of ...
  * :doc:`/project/tasks/sensor-csv`

* :doc:`/project/tasks/proximity-vl53l1x`

  * Still a problem with 32bit I2C writes

    * The status register shows the value of 0 when default I2C bus
      speed is used
    * Shows 1 when I2C bus speed matches that of Arduino (jjj what is
      that?). Funny because this is a higher speed.

  * Use a scope to compare both patterns

Miscellaneous
.............

* PWM, as configured per ``config.txt``

  * ... must be quiesced by a systemd unit that exports it. This
    sounds wrong.
  * ... goes mad again 10 seconds later when boot is near
    complete. The boot takes so long because it's a desktop boot.
  * |longrightarrow| What if we don't boot into desktop?

  Alternative: use PCA chip on :doc:`Crazy-Pi
  </project/tasks/crazy-pi>`.

* Switch all to native Pi build (build on Pi locally) because
  toolchain is crap.
