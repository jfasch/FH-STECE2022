add_library(toolcase-ipc

  crazy-car-protocol.h
  crazy-car-protocol.cpp
)

target_include_directories(
  toolcase-ipc

  INTERFACE

  ..
)
