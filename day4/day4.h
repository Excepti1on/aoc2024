//
// Created by olive on 05/12/2024.
//

#ifndef AOC2024_DAY4_DAY4_H_
#define AOC2024_DAY4_DAY4_H_

#include <string_view>
#include <fstream>
#include <cstdint>
class day4 {
 private:
  const std::string_view input{R"(C:\Users\olive\CLionProjects\aoc2024\day4\input.txt)"};
  std::ifstream file{input.begin()};
 public:
  std::uint64_t part1();
  std::uint64_t part2();
};

#endif //AOC2024_DAY4_DAY4_H_
