Development Docs
================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2022
   * Github workflow (forks, and pull requests):
     :doc:`jfasch:about/site/work-in-progress/fh-joanneum/2021/git/git`

Documentation
-------------

See `the docs CI on readthedocs
<https://fh-stece2022.readthedocs.io/>`__ for the latest documentation
build.

Checkout and Initialization
---------------------------

.. code-block:: console

   $ cd ~                            # <--- or wherever you like
   $ git clone https://github.com/jfasch/FH-STECE2022.git
   $ cd ~/FH-STECE2022
   $ git submodule init
   $ git submodule update

.. _firmware-build:

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/FH-STECE2022-x86_64         # <--- or wherever you like
   $ cd ~/FH-STECE2022-x86_64
   $ cmake ~/FH-STECE2022
   $ make

Test
----

.. code-block:: console

   $ pwd
   /home/jfasch/FH-STECE2022-x86_64      # <--- or whatever you have chosen

.. code-block:: console

   $ ./tests/fh-stece22-suite 
   Running main() from /home/jfasch/My-Projects/FH-STECE2022/googletest/googletest/src/gtest_main.cc
   [==========] Running 23 tests from 7 test suites.
   [----------] Global test environment set-up.
   [----------] 2 tests from demo_suite
   [ RUN      ] demo_suite.first_example_that_fails
   [       OK ] demo_suite.first_example_that_fails (0 ms)
   [ RUN      ] demo_suite.second_example_that_might_fail
   [       OK ] demo_suite.second_example_that_might_fail (0 ms)
   [----------] 2 tests from demo_suite (0 ms total)
   
   [----------] 3 tests from vector_suite
   [ RUN      ] vector_suite.modify_sut
   [       OK ] vector_suite.modify_sut (0 ms)
   [ RUN      ] vector_suite.vector_first_test
   [       OK ] vector_suite.vector_first_test (0 ms)
   [ RUN      ] vector_suite.vector_second_test
   [       OK ] vector_suite.vector_second_test (0 ms)
   [----------] 3 tests from vector_suite (0 ms total)
   
   [----------] 10 tests from sysfs_file_suite
   [ RUN      ] sysfs_file_suite.read_int64_with_linefeed
   [       OK ] sysfs_file_suite.read_int64_with_linefeed (0 ms)
   [ RUN      ] sysfs_file_suite.read_int64_without_linefeed
   [       OK ] sysfs_file_suite.read_int64_without_linefeed (0 ms)
   [ RUN      ] sysfs_file_suite.write_int64
   [       OK ] sysfs_file_suite.write_int64 (0 ms)
   [ RUN      ] sysfs_file_suite.write_int64_truncate
   [       OK ] sysfs_file_suite.write_int64_truncate (0 ms)
   [ RUN      ] sysfs_file_suite.read_uint64_t
   [       OK ] sysfs_file_suite.read_uint64_t (0 ms)
   [ RUN      ] sysfs_file_suite.write_uint64_t
   [       OK ] sysfs_file_suite.write_uint64_t (0 ms)
   [ RUN      ] sysfs_file_suite.read_max_uint64_t
   [       OK ] sysfs_file_suite.read_max_uint64_t (0 ms)
   [ RUN      ] sysfs_file_suite.write_max_uint64_t
   [       OK ] sysfs_file_suite.write_max_uint64_t (0 ms)
   [ RUN      ] sysfs_file_suite.read_string
   [       OK ] sysfs_file_suite.read_string (0 ms)
   [ RUN      ] sysfs_file_suite.write_string
   [       OK ] sysfs_file_suite.write_string (0 ms)
   [----------] 10 tests from sysfs_file_suite (1 ms total)
   
   [----------] 3 tests from sysfs_pwm_pin_suite
   [ RUN      ] sysfs_pwm_pin_suite.get_period
   [       OK ] sysfs_pwm_pin_suite.get_period (0 ms)
   [ RUN      ] sysfs_pwm_pin_suite.duty_cycle_bigger_period
   [       OK ] sysfs_pwm_pin_suite.duty_cycle_bigger_period (0 ms)
   [ RUN      ] sysfs_pwm_pin_suite.unsigned_vs_signed_clarification
   [       OK ] sysfs_pwm_pin_suite.unsigned_vs_signed_clarification (0 ms)
   [----------] 3 tests from sysfs_pwm_pin_suite (0 ms total)
   
   [----------] 1 test from sysfs_gpio_suite
   [ RUN      ] sysfs_gpio_suite.basic
   [       OK ] sysfs_gpio_suite.basic (0 ms)
   [----------] 1 test from sysfs_gpio_suite (0 ms total)
   
   [----------] 2 tests from motor_suite
   [ RUN      ] motor_suite.forward_slightly
   /home/jfasch/My-Projects/FH-STECE2022/tests/motor-tests.cpp:53: Failure
   Expected equality of these values:
     speed.duty_cycle()
       Which is: 0
     speed.period()/10
       Which is: 1000000
   
   [  FAILED  ] motor_suite.forward_slightly (0 ms)
   [ RUN      ] motor_suite.zero
   /home/jfasch/My-Projects/FH-STECE2022/tests/motor-tests.cpp:60: Failure
   Expected: (forward.state()) != (backward.state()), actual: false vs false
   
   [  FAILED  ] motor_suite.zero (0 ms)
   [----------] 2 tests from motor_suite (0 ms total)
   
   [----------] 2 tests from sweet_servo_suite
   [ RUN      ] sweet_servo_suite.sunny
   [       OK ] sweet_servo_suite.sunny (0 ms)
   [ RUN      ] sweet_servo_suite.out_of_range
   [       OK ] sweet_servo_suite.out_of_range (0 ms)
   [----------] 2 tests from sweet_servo_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 23 tests from 7 test suites ran. (2 ms total)
   [  PASSED  ] 21 tests.
   [  FAILED  ] 2 tests, listed below:
   [  FAILED  ] motor_suite.forward_slightly
   [  FAILED  ] motor_suite.zero
   
    2 FAILED TESTS
   
