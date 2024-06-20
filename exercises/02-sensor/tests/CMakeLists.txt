add_executable(
  02-sensor-tests

  suite-sensor.cpp

  fixture-tmpdir.cpp
  fixture-tmpdir.h
  )

target_link_libraries(
  02-sensor-tests

  02-sensor
  gtest_main 
  )

add_test(NAME 02-sensor-tests COMMAND 02-sensor-tests)
