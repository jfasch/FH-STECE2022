ADD_EXECUTABLE(read-sensor read-sensor.c)
TARGET_LINK_LIBRARIES(read-sensor 02-sensor)

ADD_EXECUTABLE(valgrind-demo valgrind-demo.c)
