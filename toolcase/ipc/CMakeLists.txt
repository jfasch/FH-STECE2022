add_library(toolcase-ipc

  vehicle-protocol.h
  vehicle-protocol.cpp
)

target_include_directories(
  toolcase-ipc

  INTERFACE

  ..
)
