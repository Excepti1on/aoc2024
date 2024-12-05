cmake_minimum_required(VERSION 3.28)
project(aoc2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/build")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_link_options(-static -static-libgcc -static-libstdc++)

add_library(day1 OBJECT day1/day1.h day1/day1.cpp)

add_library(day2 OBJECT day2/day2.h day2/day2.cpp)
add_library(day3 OBJECT day3/day3.h day3/day3.cpp)
add_library(day4 OBJECT day4/day4.h day4/day4.cpp)
add_library(day5 OBJECT day5/day5.h day5/day5.cpp)
add_executable(aoc2024 main.cpp)

target_link_libraries(aoc2024 day1 day2 day3 day4 day5)