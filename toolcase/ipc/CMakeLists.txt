add_library(toolcase-ipc

  crazy-car-protocol.h
  crazy-car-protocol.cpp
)

target_include_directories(
  toolcase-ipc

  INTERFACE

  ..
)

target_link_libraries(
  toolcase-ipc

  rt
)
