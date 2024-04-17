CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(FancyGreeting LANGUAGES C)

ADD_LIBRARY(hello hello.c hello-flexible.c)

ADD_EXECUTABLE(hello-first hello-first.c)
TARGET_LINK_LIBRARIES(hello-first hello)

ADD_EXECUTABLE(hello-second hello-second.c)
TARGET_LINK_LIBRARIES(hello-second hello)
