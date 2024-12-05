//
// Created by olive on 01/12/2024.
//

#ifndef AOC2024_DAY1_DAY1_H_
#define AOC2024_DAY1_DAY1_H_

#include <string_view>
#include <cstdint>
#include <fstream>
class day1 {
 public:
  std::uint64_t part1() noexcept;
  std::uint64_t part2() noexcept;
 private:
  const std::string_view file{R"(C:\Users\olive\CLionProjects\aoc2024\day1\input.txt)"};
  std::ifstream input{file.begin()};
};

#endif //AOC2024_DAY1_DAY1_H_
