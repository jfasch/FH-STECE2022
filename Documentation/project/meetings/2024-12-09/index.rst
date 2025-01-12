.. include:: <mmlalias.txt>


2024-12-09(3): Project
======================

.. contents::
   :local:

* :doc:`/project/tasks/driving-stage-1`

  * :doc:`/project/tasks/crazy-car`
  * :doc:`/project/tasks/commandline-driving`
  * :doc:`/project/tasks/hardware-init`
  * Do we have a list of hardware issues?

* FH-ECE21/toolcase/base/MQTT_publisher.h -> Kotschnig, Eingang
* centralize time: VL53L1X::millis(): beide sensor-gruppen

  * VL53L1X::checkTimeoutExpired(): overflow from uint16_t cast?

* open issues

  * :ref:`open-issues-vl53l1x-address-coordination`
  * :ref:`open-issues-vl53l1x-heavy-polling`
  * :ref:`open-issues-vl53l1x-race-condition`
  * :ref:`open-issues-crazy-pi-servo-voltage-glitch`

* todo

  * kotschnig sagen wegen race condition und time intervall abhaengig
    von genauigkeit
