CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
project(polyfit2d)

set(CMAKE_CXX_STANDARD 11)

# Library
add_library(polyfit2d src/polyfit2d.cpp)
target_include_directories(polyfit2d PUBLIC include)
find_package(Eigen3 REQUIRED)
target_link_libraries(polyfit2d Eigen3::Eigen)

# Tests
add_executable(polyfit2d_test tests/main.cpp)
target_link_libraries(polyfit2d_test polyfit2d)
