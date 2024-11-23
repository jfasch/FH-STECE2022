.. ot-task:: crazycar.driving_stage_1
   :dependencies: crazycar.servo_motor,
		  crazycar.motor_control_btn9960lv,
		  crazycar.commandline_driving,
		  crazycar.crazy_car,
		  crazycar.crazy_pi,
		  crazycar.hardware_init

.. include:: <mmlalias.txt>


Integration: Driving, Stage 1
=============================

.. contents::
   :local:

Plan
----

Hardware
........

* Integrate a Pi via the :doc:`CrazyPi PCB <crazy-pi>`

  * Plug :doc:`motor control <motor-control-btn9960lv>`
  * Plug :doc:`servo control <servo-motor>`

Software
........

* Initialize all necessary hardware after boot; :doc:`driving-stage-1`
* Drive, :doc:`commandline-driving`
