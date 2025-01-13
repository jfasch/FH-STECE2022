add_executable(
  proximity-vl53l1x-prog
  proximity-vl53l1x-prog.cpp
  VL53L1X.cpp
)
target_link_libraries(proximity-vl53l1x-prog toolcase-base)

