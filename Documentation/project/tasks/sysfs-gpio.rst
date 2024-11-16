.. ot-task:: crazycar.sysfs_gpio

.. include:: <mmlalias.txt>


DONE: GPIO Abstraction On Top Of ``/sys/class/gpio/``
=====================================================

.. contents::
   :local:

* See also
  :doc:`jfasch:trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`

Plan
----

.. code-block:: c++

   class SysFSGPIO
   {
   public:
       SysFSGPIO(const std::filesystem::path& pindir);
   
       Direction direction();
       bool state();
       void set_state(bool);
   };

Notes
-----

* sysfs gpio is deprecated; use ``libgpiod`` if there's time
