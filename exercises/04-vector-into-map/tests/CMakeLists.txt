add_executable(
  04-vector-into-map-tests

  suite.cpp
  suite-2.cpp
)

target_link_libraries(
  04-vector-into-map-tests

  04-vector-into-map  
  gtest_main 
  )

add_test(NAME 04-vector-into-map-tests COMMAND 04-vector-into-map-tests)
