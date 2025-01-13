add_library(toolcase-base

  sysfs-file.h
  sysfs-file.cpp

  sysfs-gpio-pin.h
  sysfs-gpio-pin.cpp

  sysfs-pwm-pin.h
  sysfs-pwm-pin.cpp

  sysfs-servo.h
  sysfs-servo.cpp

  sysfs-motor.h
  sysfs-motor.cpp

<<<<<<< HEAD
  millis.h
  millis.cpp
=======
  vl53l1x.h
  vl53l1x.cpp
>>>>>>> upstream/main
)

target_include_directories(
  toolcase-base

  INTERFACE

  ..
)
