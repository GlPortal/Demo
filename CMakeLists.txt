cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set(EXE_NAME demo)

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()

project(${EXE_NAME} CXX)
set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(DEMO_LIBRARIES "")

find_package(RadixWindow REQUIRED)
include_directories(${RADIX_WINDOW_INCLUDE_DIRS})
list(APPEND DEMO_LIBRARIES ${RADIX_WINDOW_LIBRARIES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  add_definitions("-Wall")
endif ()

add_subdirectory(source)
