cmake_minimum_required(VERSION 3.22...3.28)

project(
  SoftwareRenderer
  VERSION 1.0
  DESCRIPTION "A software renderer built from scratch"
  LANGUAGES CXX
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) 
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_FLAGS "-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

  option(PACKAGE_TESTS "Set ON to build tests" ON)
endif()

if (PACKAGE_TESTS)
  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
  FetchContent_MakeAvailable(googletest)
  include(GoogleTest)
endif()

add_subdirectory(common)
add_subdirectory(extern/stb_image)
add_subdirectory(color)
add_subdirectory(graphics)
add_subdirectory(geometry)
add_subdirectory(apps)

