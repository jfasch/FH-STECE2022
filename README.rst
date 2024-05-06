Development Workflow
====================

.. contents::
   :local:

Checkout and Initialization
---------------------------

.. code-block:: console

   $ cd ~                            # <--- or wherever you like
   $ git clone https://github.com/jfasch/FH-STECE22.git
   $ cd ~/FH-STECE22
   $ git submodule init
   $ git submodule update

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/FH-STECE22-x86_64         # <--- or wherever you like
   $ cd ~/FH-STECE22-x86_64
   $ cmake ~/FH-STECE22
   $ make

Test
----

.. code-block:: console

   $ pwd
   /home/jfasch/FH-STECE22-x86_64      # <--- or whatever you have chosen

.. code-block:: console

   $ ./exercises/02-sensor/tests/02-sensor-tests 
   Running main() from /home/jfasch/My-Projects/FH-STECE2022/googletest/googletest/src/gtest_main.cc
   [==========] Running 4 tests from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 4 tests from sensor_fixture
   [ RUN      ] sensor_fixture.sunny
   /home/jfasch/My-Projects/FH-STECE2022/exercises/02-sensor/tests/suite-sensor.cpp:15: Failure
   Expected equality of these values:
     error
       Which is: -42
     0
   
   [  FAILED  ] sensor_fixture.sunny (0 ms)
   [ RUN      ] sensor_fixture.sensor_file_not_exist
   /home/jfasch/My-Projects/FH-STECE2022/exercises/02-sensor/tests/suite-sensor.cpp:24: Failure
   Expected equality of these values:
     error
       Which is: -42
     -1
   
   [  FAILED  ] sensor_fixture.sensor_file_not_exist (0 ms)
   [ RUN      ] sensor_fixture.sensor_file_no_permission
   /home/jfasch/My-Projects/FH-STECE2022/exercises/02-sensor/tests/suite-sensor.cpp:36: Failure
   Expected equality of these values:
     error
       Which is: -42
     -2
   
   [  FAILED  ] sensor_fixture.sensor_file_no_permission (0 ms)
   [ RUN      ] sensor_fixture.sensor_file_bad_content
   /home/jfasch/My-Projects/FH-STECE2022/exercises/02-sensor/tests/suite-sensor.cpp:51: Failure
   Expected equality of these values:
     error
       Which is: -42
     -3
   
   [  FAILED  ] sensor_fixture.sensor_file_bad_content (0 ms)
   [----------] 4 tests from sensor_fixture (1 ms total)
   
   [----------] Global test environment tear-down
   [==========] 4 tests from 1 test suite ran. (1 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 4 tests, listed below:
   [  FAILED  ] sensor_fixture.sunny
   [  FAILED  ] sensor_fixture.sensor_file_not_exist
   [  FAILED  ] sensor_fixture.sensor_file_no_permission
   [  FAILED  ] sensor_fixture.sensor_file_bad_content
   
    4 FAILED TESTS
   

.. code-block:: console

   $ echo 42666 > /tmp/temperature
   $ ./exercises/02-sensor/bin/read-sensor /tmp/temperature
   Hier noch brav sein!
