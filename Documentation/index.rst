.. include:: <mmlalias.txt>


Crazy Car NG, Running Linux
===========================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2022

The Mission
-----------

The `FH Joanneum <https://www.fh-joanneum.at/>`__ bachelor studies
`Electronics and Computer Engineering
<https://www.fh-joanneum.at/elektronik-und-computer-engineering/bachelor/en/>`__
has a class `Embedded Computing (1 and 2)
<https://www.fh-joanneum.at/elektronik-und-computer-engineering/bachelor/en/my-studies/curriculum/>`__,
in semester 4 and 5. During this class we want to learn

* C++
* Linux hardware interfaces
* Linux realtime
* Some Python
* ... and more

Also on FH Joanneum, there is a fun contest, `Crazy Car
<https://www.fh-joanneum.at/veranstaltung/crazy-car/>`__ - RC cars
racing against each other, autonomously. FH Joanneum is one of the
competitors, and as such has hardware (a car). Traditionally, that car
has been equipped with bare metal software (class `Embedded Systems
<https://www.fh-joanneum.at/elektronik-und-computer-engineering/bachelor/en/my-studies/curriculum/>`__,
semester 3).

In search for something to play with in Embedded Computing 2, we chose
to have fun with the car's next generation hardware
(:download:`schematics and print <Schematic_and_print_CrazyCar.pdf>`)
and a `Raspberry Pi <https://www.raspberrypi.org/>`__.

Goal: Create Toolcase
.....................

.. toctree::
   :hidden:

   toolcase/index

.. sidebar:: More information

   * :doc:`toolcase/index`

Create Linux implementations for the hardware devices that are found
on a car. These implementations should be usable from many possible
architectures, including the reference architecture below, but also
from more static architectures.

Goal: Create Reference Architecture
...................................

.. toctree::
   :hidden:

   architecture/index

.. sidebar:: More information

   * :doc:`architecture/index`

Given a working toolcase that we can use code out of, a
:doc:`reference architecture <architecture/index>` is implemented.

Project Tracking
----------------

.. toctree::
   :hidden:

   project/index

.. sidebar::

   More about project management :doc:`here ... <project/index>`

* :doc:`project/tasks/group`
* :doc:`project/meetings/index`


Further Information
-------------------

.. toctree::
   :hidden:

   development

* Crazy Car NG Schematics:
  :download:`Schematic_and_print_CrazyCar.pdf`

Documentation
-------------

How to write and build documentation

.. toctree::
   
   howto

Todo List
.........

.. todolist::
