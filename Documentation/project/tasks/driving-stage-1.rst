.. ot-task:: crazycar.driving_stage_1
   :dependencies: crazycar.servo_motor,
		  crazycar.motor_control_btn9960lv,
		  crazycar.commandline_driving,
		  crazycar.crazy_car,
		  crazycar.crazy_pi,
		  crazycar.hardware_init

.. include:: <mmlalias.txt>


(ACTIVE) Integration: Driving, Stage 1
======================================

.. contents::
   :local:

Plan
----

See if hard- and software go together well.

Hardware
........

* Integrate a Pi via the :doc:`CrazyPi PCB <crazy-pi>`
* Plug :doc:`motor control <motor-control-btn9960lv>`
* Plug :doc:`servo control <servo-motor>`
* Plug battery

Software
........

* Initialize all necessary hardware after boot: :doc:`hardware-init`
* Add motor and servo software to :doc:`crazy-car`
* Drive, :doc:`commandline-driving`

.. ot-graph::
   :entries: crazycar.driving_stage_1
