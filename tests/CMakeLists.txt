# GoogleTest
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest)
include_directories(${gtest_SOURCE_DIR}/include)


# Tests
set(paths
  ${CMAKE_CURRENT_SOURCE_DIR}/test_config_file_type.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/test_value_type.cpp
)

foreach(path IN LISTS paths)
  get_filename_component(basename ${path} NAME)
  string(REGEX REPLACE "\\.[^.]*$" "" exec ${basename})

  add_executable(${exec} ${path})
  target_link_libraries(${exec} ${CONFIG_CPP_LIBS} gtest)
  
  add_test(${exec} ${exec})

  message(STATUS "build: [${path} -> ${exec}]")
endforeach()
