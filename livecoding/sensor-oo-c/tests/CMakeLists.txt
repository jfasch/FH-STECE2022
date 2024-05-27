ADD_EXECUTABLE(
  02-sensor-tests-oo-c

  suite-sensor.cpp

  fixture-tmpdir.cpp
  fixture-tmpdir.h
  )

TARGET_LINK_LIBRARIES(
  02-sensor-tests-oo-c

  02-sensor-oo-c
  gtest_main 
  )
