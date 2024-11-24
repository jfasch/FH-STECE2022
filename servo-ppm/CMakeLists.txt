add_executable(
  servo-ppm-prog
  servo-ppm-prog.cpp
)

add_executable(
  servo-Test
  servo-Test.cpp
  ../toolcase/base/sysfs-servo.cpp
  ../toolcase/base/sysfs-pwm-pin.cpp
  ../toolcase/base/sysfs-file.cpp
)