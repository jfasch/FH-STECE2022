Raspberry Pi Adapter PCB ("Crazy Pi")
=====================================

The pinout of the base PCB is made for Arduinos. The "Crazy Pi" PCB is an adapter PCB which maps that to the Raspberry
Pi.

See the :doc:`task description </project/tasks/crazy-pi>` for
additional info.

.. image:: /project/tasks/crazy-pi-top.png

.. image:: /project/tasks/crazy-pi-bottom.png

.. _open-issues-crazy-pi:

Crazy Pi: Open Issues
---------------------

.. _open-issues-crazy-pi-servo-voltage-glitch:

Crazy Pi: Servo Voltage Glitch
..............................

Servo is fed from the 5V rail that feeds the Raspberry Pi. Voltage
glitches make the Pi die immediately. **Fix capacitors**
