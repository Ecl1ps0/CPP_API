cmake_minimum_required(VERSION 3.10)

Project(API)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows")

find_package(oatpp REQUIRED)

add_executable(API src/main.cpp)

target_link_libraries(API PUBLIC oatpp::oatpp)

target_include_directories(API PUBLIC 
  $<BUILD_INTERFACE:${OATPP_INCLUDE_DIRS}>)
