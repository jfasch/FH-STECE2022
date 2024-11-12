ADD_EXECUTABLE(bug bug.c)
ADD_EXECUTABLE(datalogger datalogger.cpp)
ADD_EXECUTABLE(rm-on-steroids rm-on-steroids.cpp)

ADD_SUBDIRECTORY(sensor-oo-c)

ADD_EXECUTABLE(string-demo string-demo.cpp)
ADD_EXECUTABLE(ptr-arith-stl ptr-arith-stl.cpp)
ADD_EXECUTABLE(vector-demo vector-demo.cpp)
ADD_EXECUTABLE(vector-demo2 vector-demo2.cpp)
ADD_EXECUTABLE(map-demo map-demo.cpp)
ADD_EXECUTABLE(find-demo find-demo.cpp)
ADD_EXECUTABLE(find-if-demo find-if-demo.cpp)
ADD_EXECUTABLE(find-if-demo-lambda find-if-demo-lambda.cpp)
ADD_EXECUTABLE(sort-demo sort-demo.cpp)

ADD_EXECUTABLE(address-space address-space.cpp)

ADD_EXECUTABLE(point point.cpp)

ADD_EXECUTABLE(file-create file-create.cpp)

ADD_EXECUTABLE(namemangling-main namemangling-main.cpp namemangling-lib.cpp)
ADD_EXECUTABLE(namemangling-main-simulink namemangling-main-c.cpp namemangling-lib-c.cpp namemangling-lib.cpp)
