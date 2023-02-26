cmake_minimum_required(VERSION 3.1)

find_package(OpenMP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -O2 -Wextra -Wno-missing-field-initializers")

add_executable(serial src/serial_mandelbrot.cpp)
target_include_directories(serial PRIVATE include)
target_link_libraries(serial PUBLIC OpenMP::OpenMP_CXX)

add_executable(parallel src/parallel_mandelbrot.cpp)
target_include_directories(parallel PRIVATE include)
target_link_libraries(parallel PUBLIC OpenMP::OpenMP_CXX)

