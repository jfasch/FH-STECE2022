cmake_minimum_required(VERSION 3.16)
project(FH-STECE2022)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
endif()

enable_testing()

add_subdirectory(proximity-vl53l1x)
add_subdirectory(gyroscope-bno055)
add_subdirectory(motor-control-btn9960lv)
add_subdirectory(servo-ppm)


add_subdirectory(bin)

add_subdirectory(livecoding)
add_subdirectory(exercises)
add_subdirectory(googletest)
