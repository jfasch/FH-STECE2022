add_executable(
  06-lab-exercise-tests

  suite.cpp
)

target_link_libraries(
  06-lab-exercise-tests

  06-lab-exercise
  gtest_main 
  )

add_test(NAME 06-lab-exercise-tests COMMAND 06-lab-exercise-tests)
