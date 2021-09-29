cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(config-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Release)
endif()

aux_source_directory(${CMAKE_SOURCE_DIR}/config-cpp CONFIG_CPP_SRCS)
set(SRCS
  ${CONFIG_CPP_SRCS}
)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_STATIC_LIBS "Build static libraries" OFF)

if(BUILD_SHARED_LIBS)
  add_library(config_cpp_shared SHARED ${SRCS})
  set_target_properties(config_cpp_shared PROPERTIES
    OUTPUT_NAME config_cpp
    POSITION_INDEPENDENT_CODE ON
  )
endif()

if(BUILD_STATIC_LIBS)
  add_library(config_cpp_static STATIC ${SRCS})
  set_target_properties(config_cpp_static PROPERTIES
    OUTPUT_NAME config_cpp
    POSITION_INDEPENDENT_CODE ON
  )
endif()

if(BUILD_SHARED_LIBS)
  set(CONFIG_CPP_LIBS config_cpp_shared)
elseif(BUILD_STATIC_LIBS)
  set(CONFIG_CPP_LIBS config_cpp_static)
endif()
