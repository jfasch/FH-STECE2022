Gyroscope Sensor: BNO055
========================

.. contents::
   :local:

.. sidebar::

   * Task that led to current status:
     :doc:`/project/tasks/gyroscope-bno055`

.. _gyro-background:

Background
----------

On the CrazyCar a Gyroscope/Accelometer (BNO055) is included.
It can be used to log data e.g. if you drive into a curve and want to know how much force was put onto the car and in which orientation it is.
Our goal was to get this sensor to work.
The first thing was to find an exisiting library and to adapt it, so that it fits for our purpose.
As we researched we stumbled upon this library:
https://github.com/fm4dd/pi-bno055
This is a project that was already made for the raspberry pi which was perfect.
Problems:

* it used global variables a lot which makes it hard to re-use in
  larger projects
* it was not object-oriented
* it was not written in c++
* we did not need all of the functions, so we made it a bit more
  lightweight

The license that this project has, is the MIT license, that means that
we can modify the code and publish it, but the developer gives no
warranty if everything works properly.

Link to the datasheet of the sensor.
https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bno055-ds000.pdf

.. _gyro-class-descr:


Class Description
-----------------

.. todo:: **Gyroscope**

   * Link to this document: :ref:`gyro-class-descr`
   * Write doxygen in header file

.. doxygenclass:: Bno055
   :members:
