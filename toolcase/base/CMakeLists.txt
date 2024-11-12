add_library(toolcase-base

  sysfs-file.h
  sysfs-file.cpp

  sysfs-pwm-pin.h

  servo.h
)

target_include_directories(
  toolcase-base

  INTERFACE

  ..
)
