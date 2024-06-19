ADD_LIBRARY(
  05-sorting-searching

  sort-util.h
  sort-util.cpp
  search-util.h
  search-util.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  05-sorting-searching
  INTERFACE
  .
)
