cmake_minimum_required(VERSION 3.28)
project(aoc2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/build")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenMP REQUIRED)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_SUPPRESS_REGENERATION true)
	add_compile_options("-openmp:llvm")
endif()
add_library(day1 OBJECT day1/day1.h day1/day1.cpp)

add_library(day2 OBJECT day2/day2.h day2/day2.cpp)
add_library(day3 OBJECT day3/day3.h day3/day3.cpp)
add_library(day4 OBJECT day4/day4.h day4/day4.cpp)
add_library(day5 OBJECT day5/day5.h day5/day5.cpp)
add_library(day6 OBJECT day6/day6.h day6/day6.cpp)
add_library(day7 OBJECT day7/day7.cpp day7/day7.h)
add_library(day8 OBJECT day8/day8.cpp day8/day8.h)
add_library(day9 OBJECT day9/day9.cpp day9/day9.h)
add_library(day10 OBJECT day10/day10.cpp day10/day10.h)
add_library(day11 OBJECT day11/day11.cpp day11/day11.h)
add_executable(aoc2024 main.cpp)
target_link_libraries(day6 OpenMP::OpenMP_CXX)
target_link_libraries(aoc2024 PUBLIC day1 day2 day3 day4 day5 day6 day7 day8 day9 day10 day11 OpenMP::OpenMP_CXX)

enable_testing()
add_executable(testAll tests/test.cpp)
target_link_libraries(testAll day1 day2 day3 day4 day5 day6 day7 day8 day9 day10 day11 OpenMP::OpenMP_CXX)

add_test(NAME testAll COMMAND testAll "${PROJECT_SOURCE_DIR}" )



