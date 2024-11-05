To Be Done
==========

.. contents::
   :local:

Userspace SPI, And The BCM SPI Implementation
---------------------------------------------

In case PWM does not work for the servos, then chances are that it is
PPM (`Wikipedia
<https://en.wikipedia.org/wiki/Pulse-position_modulation>`__)

* `ws2812-spi on Github
  <https://github.com/jfasch/ws2812-spi>`__. Look into `ws2812/spi.cpp
  <https://github.com/jfasch/ws2812-spi/blob/main/ws2812/spi.cpp>`__:

  .. code-block:: c++

     struct spi_ioc_transfer tr = {
         .tx_buf = (unsigned long)xfer_bytes,
         .len = (uint32_t)xfer_size,
         .speed_hz = s.profile().frequency_hz,
     };

     int ret = ioctl(_fd, SPI_IOC_MESSAGE(1), &tr);

* https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf

  Things to take into accout when you use SPI to clock out multi-byte
  waveforms. Take care of "2.3.1. SPI implementation details", where
  they say that there is a garanteed gap between two bytes. During
  that time the MOSI signal is also low (alas it's SPI).

C++ Object Copy
---------------

* Problem: I2C (vl53l1x, bto055) *own* a I2C bus fd -> object *copy*
* :doc:`jfasch:trainings/material/soup/cxx03/020-data-encapsulation/object-copy`
* Show crash/valgrind/strace once we close I2C fd in dtor
