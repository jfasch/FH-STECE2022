CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(FH-STECE2022)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
endif()

ADD_EXECUTABLE(datalogger datalogger.cpp)
