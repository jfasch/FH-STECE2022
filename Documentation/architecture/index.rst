Reference Architecture
======================

The architecture divides the system into several loosely coupled
*components*, each with its own set of responsibilities.

.. contents::
   :local:

Realtime
--------

On a :doc:`real time system
<jfasch:trainings/material/soup/linux/sysprog/scheduling/realtime>`,
*responsibilites* have *priorities*. Linux lets you give priorities to
either a process as a whole, or to specific threads that are contained
within one process (spoiler: *whole process* is more manageable).

Some responsibilites our firmware has ...

* *Motor/servo control* is probably most important. It only reacts on
  behalf of somebody commanding, and is not running otherwise.
* *Emergency off* is next. Posts "emergency off" into motor control,
  which overtakes any commands that are already enqueued.
* *MQTT* and/or *CSV* logging are relatively unimportant; running them
  with realtime priority is not immediately obvious. Provided there is
  enough buffer to hold queued data that arrive in realtime, everthing
  should be ok :-)
* Steering apps (:doc:`/project/tasks/remote-control`, or
  :doc:`/project/tasks/commandline-driving`), or automatic driving,
  should be somewhere in between.
* Is sensor reading done synchronously by the steering app? (In the
  same process?)  Technically this would be much easier than to
  externalize that responsibilty. It would be more logical too,
  because self-driving control are easier implemented in this way.

.. image:: architecture.svg

Modularity
----------

* Components can be individually combined to provide different
  setups. One might :doc:`remote-control a car using an Xbox
  controller </project/tasks/remote-control>`, for example, and not
  use one of the available self-driving algorithms.
* Mix of languages. For example, use Python for non-realtime
  responsibilities like cloud communication (MQTT)

Testability
-----------

In addition to unit tests (which are at the basis of the project),
imagine we can record sensor measurements during real drive, and
replay them later to reproduce and fix erroneous driving behavior.


