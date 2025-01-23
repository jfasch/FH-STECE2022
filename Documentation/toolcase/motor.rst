Motor
=====

.. sidebar:: 

   * Task that led to current status: :doc:`/project/tasks/motor-control-btn9960lv`
   * Evaluation board:
     https://www.infineon.com/cms/en/product/evaluation-boards/dc-shield_btn9960lv/
   * Datasheet, docs:
     https://www.infineon.com/cms/de/product/power/motor-control-ics/brushed-dc-motor-control-ics/single-half-bridge-ics/btn9960lv/

.. _motor-concept-descr:

Conceptual Description: PWM and GPIO Usage
------------------------------------------
     
.. image:: motor-control-btn9960lv-one-pwm-two-gpio.jpg

.. todo:: **Motor**

   :ref:`motor-concept-descr`

   Explain meaning of pins ``forward``/``backward``/``speed``

.. _motor-class-descr:

Class Description
-----------------

.. todo:: **Motor**

   :ref:`motor-class-descr`

   Note that the ``SysFS_Motor`` class does not expose how the motor
   control works - *it shouldn't*. Rather, it has only one method,
   ``set_speed(percentage_of_max_speed)``.

   Depending on the parameter's value, IOs and PWM are tuned
   accordingly. Give examples (here, not in code/doxygen) so the user
   can understand how ``set_speed()`` is implemented in terms of
   ``SysFS_Motor``'s ``forward``, ``backward`` and ``speed`` ctor
   params.

.. doxygenclass:: SysFS_Motor
   :project: crazycar
   :members:

.. _motor-future:

Future
------

.. todo:: **Motor**

   :ref:`motor-future`

   * How about pulling the brake? How would that work? What's the
     difference between a hard brake and ``set_speed(0)``?
   * Overcurrent detection?
