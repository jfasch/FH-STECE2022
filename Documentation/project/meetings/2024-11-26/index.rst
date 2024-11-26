.. include:: <mmlalias.txt>


2024-11-26(3): Project
======================

.. contents::
   :local:

Org
---

* readthedocs -> dev documentation (jjj todo screenplay of steps, draw
  on whiteboard)
* Project task list restructured, jjj link and explain
* 80 20 regel

  * nun bei den restlichen 80 angekommen, plus ein paar features und
    nun lernen wir c++ :-)

Show
----

Github and Git: Project Management
..................................

* as user (you)

  * fork
  * clone
  * push pull among team
  * pull request

  * pull upstream changes

    * whats a remote
    * pulling from there (upstream)

* switch hat to me (link me@gh jjj)

  * execute pull request
  * show what gh says on pr page, explain with a shetch
  * whine a little

    * show how I can rely on tests
    * absolutely neccessary in large scale development -> linux kernel
      (gh is kindergarten)

Development, Including ``sshfs``
................................

.. toctree::

   sshfs

Project Status
--------------

Talk about current tasks

* Close :doc:`/Documentation/project/tasks/motor-control-btn9960lv`
* Close :doc:`/Documentation/project/tasks/servo-motor`
* Close :doc:`/Documentation/project/tasks/gyroscope-bno055`
* Close :doc:`/Documentation/project/tasks/crazy-pi`
* Status? :doc:`/Documentation/project/tasks/proximity-vl53l1x`

Start off (now really)

* :doc:`/Documentation/project/tasks/crazy-car`
* :doc:`/Documentation/project/tasks/commandline-driving`
* :doc:`/Documentation/project/tasks/hardware-init`
* PWM

  * internal PWM config at boot should definitely work. unless
    somebody reconfigures along the way. can we find what's wrong?
  * use pca as a workaround maybe

Future

* log/debug/error marcos
* move?
* systemd?
* config scheme, external file yaml, json. or compile hard. macros,
  first.

  question: where to define?

  * -> next to prog, in /bin provocatively
  * -> dependency injection
  * parameterization done near main(), everything alse is stable code
    -> metrics



