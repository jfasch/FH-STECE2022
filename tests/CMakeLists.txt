add_executable(
  fh-stece22-suite

  sysfs-file-tests.cpp
  sysfs-pwm-pin-tests.cpp

  fixture-tmpdir.cpp
  fixture-tmpdir.h

  sysfs-servo-tests.cpp
)

target_link_libraries(
  fh-stece22-suite

  toolcase-base
  gtest_main 
)
