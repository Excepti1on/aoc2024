//
// Created by olive on 05/12/2024.
//

#ifndef AOC2024_DAY5_DAY5_H_
#define AOC2024_DAY5_DAY5_H_

#include <fstream>
#include <string_view>
class day5 {
  const std::string_view input{R"(C:\Users\olive\CLionProjects\aoc2024\day5\input.txt)"};
  std::ifstream file{input.begin()};
 public:
  std::uint64_t part1();
  std::uint64_t part2();
};

#endif //AOC2024_DAY5_DAY5_H_
