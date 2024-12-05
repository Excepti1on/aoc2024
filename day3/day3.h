//
// Created by olive on 03/12/2024.
//

#ifndef AOC2024_DAY3_DAY3_H_
#define AOC2024_DAY3_DAY3_H_

#include <string_view>
#include <fstream>
#include <cstdint>
class day3 {
 private:
  const std::string_view input{R"(C:\Users\olive\CLionProjects\aoc2024\day3\input.txt)"};
  std::ifstream file{input.begin()};
 public:
  std::uint64_t part1();
  std::uint64_t part2();
};

#endif //AOC2024_DAY3_DAY3_H_
