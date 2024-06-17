ADD_EXECUTABLE(
  04-vector-into-map-tests

  suite.cpp
)

TARGET_LINK_LIBRARIES(
  04-vector-into-map-tests

  04-vector-into-map  
  gtest_main 
  )

