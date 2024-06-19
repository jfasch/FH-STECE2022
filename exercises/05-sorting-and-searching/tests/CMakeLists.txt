ADD_EXECUTABLE(
  05-sorting-searching-tests

  suite.cpp
)

TARGET_LINK_LIBRARIES(
  05-sorting-searching-tests

  05-sorting-searching
  gtest_main 
  )

