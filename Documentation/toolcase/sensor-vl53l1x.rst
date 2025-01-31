Proximity Sensor: VL53L1X
=========================

.. contents::
   :local:

.. sidebar::

   * Task that led to current status:
     :doc:`/project/tasks/proximity-vl53l1x`

.. _vl53l1x-background:

Background
----------

### VL53L1X Overview
The VL53L1X is a Time-of-Flight (ToF) sensor developed by STMicroelectronics, capable of measuring absolute distances up to **4 meters** with high accuracy. It operates using a **940nm laser emitter**, making it resistant to ambient light interference. The sensor supports different distance measurement modes (**Short, Medium, Long**) and can be used in applications such as gesture recognition, obstacle detection, and proximity sensing.

### Reference Documentation
- **VL53L1X Datasheet**: [Link to datasheet] (https://www.st.com/resource/en/datasheet/vl53l1x.pdf)
- **STMicroelectronics VL53L1X API Reference**: [Link to official documentation] (https://www.st.com/en/embedded-software/stsw-img007.html)
- **Pololu VL53L1X Arduino Library (Reference Implementation)**: [GitHub - pololu/vl53l1x-arduino](https://github.com/pololu/vl53l1x-arduino)  

### Code Origin and Linux Porting
This library is a **Linux port** of the **Pololu VL53L1X Arduino Library**, which is based on STMicroelectronics’ official API. The porting process included:
- Removing **Arduino dependencies** and replacing them with Linux-native I2C functions.
- Adapting timing mechanisms (replacing `millis()` with Linux equivalents).
- Ensuring compatibility with Linux device drivers and standard I2C interfaces.

.. note:: **Only the functions listed in the class description were modified and tested during the porting process.** No additional features or modifications beyond the required Linux adaptation were implemented.  

### License
This library follows the **MIT License**.

.. _vl53l1x-class-descr:

Class Description
-----------------

.. todo:: **Proximity**

   * Link to this document: :ref:`vl53l1x-class-descr`
   * Write doxygen in header file

.. doxygenclass:: VL53L1X
   :members:
