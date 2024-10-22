add_library(toolcase-base

  sysfs-file.h
  sysfs-file.cpp
)

target_include_directories(
  toolcase-base

  INTERFACE

  ..
)
