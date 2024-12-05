cmake_minimum_required(VERSION 3.28)
project(aoc2024)

set(CMAKE_CXX_STANDARD 26)

add_executable(aoc2024 main.cpp
        day1/day1.cpp
        day1/day1.h
        day2/day2.cpp
        day2/day2.h
        day3/day3.cpp
        day3/day3.h
        day4/day4.cpp
        day4/day4.h
        day5/day5.cpp
        day5/day5.h)
