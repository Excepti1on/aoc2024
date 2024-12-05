//
// Created by olive on 02/12/2024.
//

#ifndef AOC2024_DAY2_DAY2_H_
#define AOC2024_DAY2_DAY2_H_

#include <cstdint>
#include <string_view>
#include <fstream>
class day2 {
 public:
  std::uint64_t part1();
  std::uint64_t part2();
 private:
  const std::string_view input{"../day2/input.txt"};
  std::ifstream file{input.data()};
};

#endif //AOC2024_DAY2_DAY2_H_
