cmake_minimum_required(VERSION 3.16)
project(FH-STECE2022)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
endif()

# preliminary working directories for groups. use these until we are
# familiar with git workflows.
add_subdirectory(gyroscope-bno055)
add_subdirectory(motor-control-btn9960lv)
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

# stuff from summer; instructional purposes only. to be removed, or at
# least pushed down into some "attic".

# jfasch: removed from build because it uses std::filesystem

# add_subdirectory(livecoding)
# add_subdirectory(exercises)
