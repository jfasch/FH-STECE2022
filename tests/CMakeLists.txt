add_executable(
  fh-stece22-suite

  demo-tests.cpp

  sysfs-file-tests.cpp
  sysfs-pwm-pin-tests.cpp
  sysfs-gpio-pin-tests.cpp

  motor-tests.cpp

  fixture-tmpdir.cpp
  fixture-tmpdir.h

  sysfs-servo-tests.cpp
)

target_link_libraries(
  fh-stece22-suite

  toolcase-base
  gtest_main 
)
