ADD_EXECUTABLE(
  06-lab-exercise-tests

  suite.cpp
)

TARGET_LINK_LIBRARIES(
  06-lab-exercise-tests

  06-lab-exercise
  gtest_main 
  )

