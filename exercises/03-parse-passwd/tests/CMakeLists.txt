ADD_EXECUTABLE(
  03-parse-passwd-tests

  suite-passwd-line.cpp
  suite-passwd-error.cpp
  suite-passwd-user.cpp
)

TARGET_LINK_LIBRARIES(
  03-parse-passwd-tests

  03-parse-passwd
  gtest_main 
  )

