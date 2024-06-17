ADD_EXECUTABLE(
  04-vector-into-map-tests

  suite.cpp
  suite-2.cpp
)

TARGET_LINK_LIBRARIES(
  04-vector-into-map-tests

  04-vector-into-map  
  gtest_main 
  )

