.. include:: <mmlalias.txt>


2024-11-12(6): POSIX MQ, Xbox
=============================

.. contents::
   :local:

Material
--------

* :doc:`jfasch:trainings/material/soup/linux/sysprog/ipc-mqueue/topic`

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

Homework
--------

* ``ip addr``
* Someone to implement signed/unsigned? |longrightarrow|
  `std::stoull()
  <https://en.cppreference.com/w/cpp/string/basic_string/stoul>`__

Future
------

jjj

* task: init (export pwm, gpio, and whatnot)
