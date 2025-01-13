.. include:: <mmlalias.txt>


2025-01-13(6): Project
======================

.. contents::
   :local:

* :doc:`/project/tasks/hardware-init`

  * You say something's not exported. What's that? Have you checked
    with ``strace``? (I can see filenames with (trailing) spaces in
    them - looks like that is the reason.)
  * Only the config structures should be part of the ``config.h`` - no
    functionality. Lets move Motor and PIN objects out to where they
    belong.

    Move ``initialize_pwm()`` and ``initialize_gpio()`` into the main
    prog, so that only it uses the classes.

* :doc:`/Documentation/development/issues`

  Look over it, and check
