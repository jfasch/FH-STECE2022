add_executable(crazy-car-init crazy-car-init.cpp)
target_link_libraries(crazy-car-init toolcase-ipc)

add_executable(vehicle vehicle.cpp)
target_link_libraries(vehicle toolcase-ipc)

add_executable(vehicle-motor-set-rpm vehicle-motor-set-rpm.cpp)
target_link_libraries(vehicle-motor-set-rpm toolcase-ipc)

add_executable(vehicle-servo-set-angle vehicle-servo-set-angle.cpp)
target_link_libraries(vehicle-servo-set-angle toolcase-ipc)



add_executable(gpio-test gpio-test.cpp)
target_link_libraries(gpio-test toolcase-base)

add_executable(pwm-test pwm-test.cpp)
target_link_libraries(pwm-test toolcase-base)

add_executable(lm73 lm73.cpp)
add_executable(rt-test rt-test.cpp)
