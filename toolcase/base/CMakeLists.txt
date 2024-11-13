add_library(toolcase-base

  sysfs-file.h
  sysfs-file.cpp

  sysfs-gpio-pin.h
  sysfs-gpio-pin.cpp

  sysfs-pwm-pin.h

  sysfs-servo.h
  sysfs-servo.cpp
)

target_include_directories(
  toolcase-base

  INTERFACE

  ..
)
