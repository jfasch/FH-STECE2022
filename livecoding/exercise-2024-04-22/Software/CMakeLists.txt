CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(The-Fancy-Greeter LANGUAGES C)

ADD_EXECUTABLE(greet-parameterized greet-parameterized.c)
TARGET_LINK_LIBRARIES(greet-parameterized greet)
INSTALL(TARGETS greet-parameterized DESTINATION bin)

ADD_EXECUTABLE(greet-simple greet-simple.c)
TARGET_LINK_LIBRARIES(greet-simple greet)
INSTALL(TARGETS greet-simple DESTINATION bin)

ADD_LIBRARY(greet greet.c)
