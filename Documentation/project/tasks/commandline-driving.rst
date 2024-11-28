.. ot-task:: crazycar.commandline_driving

.. include:: <mmlalias.txt>


(ACTIVE) Commandline Driving
============================

.. contents::
   :local:


Use Case
--------

For low level testing: log in over SSH, and use a commandline program
as described below.

Plan
----

Write one program that reads commands from ``stdin`` (``std::cin``) in
a loop. For example like this,

.. code-block:: console

   $ ./bin/crazy-car-drive
   d 30
   s -10
   s 10
   d 0
   d -5
   ... more commands ...

This would

* Drive (``d``) the motor to 30 units (?) forward
* Steer (``s``) the servo -10 units (?) (10 left)
* Steer 10 right
* ``d 0``: stop softly letting the car roll to an end, as opposed to
  pulling the brake
* Move 5 backwards

Implementation
--------------

See `bin/crazy-car-motor-set-rpm.cpp
<https://github.com/jfasch/FH-STECE2022/blob/main/bin/crazy-car-motor-set-rpm.cpp>`__. That
program reads values from ``stdin``, and writes motor commands
(forward and backward speeds) into the ``/crazy-car`` message queue. 

Rename the commands from 
