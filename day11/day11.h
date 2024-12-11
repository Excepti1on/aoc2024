//
// Created by olive on 11/12/2024.
//

#ifndef AOC2024_DAY11_DAY11_H_
#define AOC2024_DAY11_DAY11_H_
#include <filesystem>
#include <fstream>
#include <cstdint>
class day11 {
 public:
  day11(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day11" / "input.txt"};
};

#endif //AOC2024_DAY11_DAY11_H_
