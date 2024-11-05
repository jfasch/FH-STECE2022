.. ot-topic:: crazycar.motor_control_btn9960lv
   :dependencies: crazycar.sysfs_pwm

.. include:: <mmlalias.txt>


Motor Control: BTN9960LV
========================

.. contents::
   :local:

.. sidebar:: Meeting Minutes

   * :ref:`2024-10-08-linux-and-pwm`

Facts
-----

* Evaluation board:
  https://www.infineon.com/cms/en/product/evaluation-boards/dc-shield_btn9960lv/
* Datasheet, docs:
  https://www.infineon.com/cms/de/product/power/motor-control-ics/brushed-dc-motor-control-ics/single-half-bridge-ics/btn9960lv/

.. _fh2022-motor-control-btn9960lv-software-interface:

Software Interface
------------------

* What can we do in software, provided that we had PWM?

  Motor: RPM speed to ``pwm7.duty_cycle``

  * Convert ``double`` to ``duty_cycle``?
  * To two instances of ``class PWM``'s ``duty_cycle``?
  * Sketch this:

  .. code-block:: c++

     class SinglePWMMotor:
         def __init__(self, pwm_pin: PWMPin):
 	    self._pwm = pwm_pin
         def set_rpm(rpm: float):
 	    # hmm. consult rpm -> duty_cycle mapping?
