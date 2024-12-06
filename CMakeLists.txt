cmake_minimum_required(VERSION 3.16)
project(FH-STECE2022)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
endif()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

# determine if libmosquitto is installed
find_package(Mosquitto)

# preliminary working directories for groups. use these until we are
# familiar with git workflows.
add_subdirectory(gyroscope-bno055)
add_subdirectory(servo-ppm)

# upcoming tools library where we will cram thing into once we
# approach a working state.
add_subdirectory(toolcase)

# "firmware". this is where production exeutables are.
add_subdirectory(bin)

# tests
enable_testing()
add_subdirectory(tests)

add_subdirectory(googletest)     # upstream submodule
