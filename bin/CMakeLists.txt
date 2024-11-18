# initializes the system: create message queue, export pwms and gpios
add_executable(crazy-car-init crazy-car-init.cpp)
target_link_libraries(crazy-car-init toolcase-ipc)

# main program
add_executable(crazy-car crazy-car.cpp)
target_link_libraries(crazy-car toolcase-ipc)

# commandline client programs: post messages in crazy-car message
# queue
add_executable(crazy-car-motor-set-rpm crazy-car-motor-set-rpm.cpp)
target_link_libraries(crazy-car-motor-set-rpm toolcase-ipc)

add_executable(crazy-car-servo-set-angle crazy-car-servo-set-angle.cpp)
target_link_libraries(crazy-car-servo-set-angle toolcase-ipc)

# hardware test programs
add_executable(servo-hw-test servo-hw-test.cpp)
target_link_libraries(servo-hw-test toolcase-base)

add_executable(pwm-test pwm-test.cpp)
target_link_libraries(pwm-test toolcase-base)

add_executable(lm73 lm73.cpp)
add_executable(rt-test rt-test.cpp)

add_executable(motor-hw-test motor-hw-test.cpp)
target_link_libraries(motor-hw-test toolcase-base)
