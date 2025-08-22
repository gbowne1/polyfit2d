cmake_minimum_required(VERSION 3.10)

project(polyfit2d VERSION 0.0.1
                  DESCRIPTION "2D Polynomial Fitting Library"
                  LANGUAGES CXX)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler settings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    # Settings for GNU and Clang
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wshadow -Wfloat-equal -Wconversion)
elseif()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wshadow -Wfloat-equal -Wconversion)
endif()

# Source files
set(SOURCES
    src/polyfit2d.cpp
)

# Create the library
add_library(polyfit2d ${SOURCES})

# Include directories for the library
target_include_directories(polyfit2d
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>  # For installation
)

# Find and link Eigen
find_package(Eigen3 REQUIRED)
target_link_libraries(polyfit2d PUBLIC Eigen3::Eigen)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_COMMANDS_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.vscode")

# Tests
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    enable_testing()
    add_executable(polyfit2d_test tests/main.cpp)
    target_link_libraries(polyfit2d_test PRIVATE polyfit2d)
    add_test(NAME Polyfit2DTest COMMAND polyfit2d_test)
endif()

install(TARGETS polyfit2d)
install()
