GPIO
====

.. note::

   We use ``sysfs`` GPIO because it is easy to understand and
   instructive.  It is deprecated and unmaintained in the kernel
   though. See `this post
   <https://forums.raspberrypi.com/viewtopic.php?t=343514>`__ for much
   information about this.

   The replacement for ``sysfs`` GPIO is ``libgpiod`` (`source
   <https://github.com/brgl/libgpiod>`__ and `docs
   <https://libgpiod.readthedocs.io/>`__).

.. doxygenclass:: SysFS_GPIO_Pin
   :project: crazycar
   :members:
