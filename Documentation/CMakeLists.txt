# doxygen
set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR}/toolcase)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
file(
  GLOB_RECURSE
  DOXYGEN_HEADER_FILES

  ${DOXYGEN_INPUT_DIR}/*.h
  ${DOXYGEN_INPUT_DIR}/*/*.h
  ${DOXYGEN_INPUT_DIR}/*/*/*.h
  ${DOXYGEN_INPUT_DIR}/*/*/*/*.h
  ${DOXYGEN_INPUT_DIR}/*/*/*/*/*.h
)

add_custom_command(
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
  OUTPUT ${DOXYGEN_OUTPUT_DIR}/html/index.html
  DEPENDS ${DOXYGEN_HEADER_FILES} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
  COMMENT "Running doxygen"
)
add_custom_target(
  doxygen 
  ALL
  DEPENDS ${DOXYGEN_OUTPUT_DIR}/html/index.html
)


# sphinx
set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx/html)

file(
  GLOB_RECURSE
  RST_FILES

  ${SPHINX_SOURCE}/*.rst
  ${SPHINX_SOURCE}/*/*.rst
  ${SPHINX_SOURCE}/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*/*/*/*/*.rst
  ${SPHINX_SOURCE}/*/*/*/*/*/*/*/*/*/*.rst
)

add_custom_command(
  COMMAND ${SPHINX_EXECUTABLE} -b html -Dbreathe_projects.crazycar=${DOXYGEN_OUTPUT_DIR}/xml ${SPHINX_SOURCE} ${SPHINX_BUILD}
  OUTPUT ${SPHINX_BUILD}/index.html
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/conf.py  ${DOXYGEN_OUTPUT_DIR}/html/index.html ${DOXYGEN_HEADER_FILES} ${RST_FILES}
  COMMENT "Generating documentation with Sphinx"
)
add_custom_target(
  docs
  ALL
  DEPENDS ${SPHINX_BUILD}/index.html
)
