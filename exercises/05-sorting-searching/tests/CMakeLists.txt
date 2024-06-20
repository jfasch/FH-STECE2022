add_executable(
  05-sorting-searching-tests

  suite.cpp
)

target_link_libraries(
  05-sorting-searching-tests

  05-sorting-searching
  gtest_main 
  )

add_test(NAME 05-sorting-searching-tests COMMAND 05-sorting-searching-tests)
