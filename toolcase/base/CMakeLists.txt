add_library(toolcase-base

  sysfs-file.h
  sysfs-file.cpp

  sysfs-gpio.h
  sysfs-gpio.cpp

  sysfs-pwm-pin.h
)

target_include_directories(
  toolcase-base

  INTERFACE

  ..
)
