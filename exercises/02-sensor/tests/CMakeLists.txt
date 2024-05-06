ADD_EXECUTABLE(
  02-sensor-tests

  suite-sensor.cpp

  fixture-tmpdir.cpp
  fixture-tmpdir.h
  )

TARGET_LINK_LIBRARIES(
  02-sensor-tests

  02-sensor
  gtest_main 
  )
