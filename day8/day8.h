//
// Created by olive on 08/12/2024.
//

#ifndef AOC2024_DAY8_DAY8_H_
#define AOC2024_DAY8_DAY8_H_
#include <fstream>
#include <cstdint>
#include <filesystem>
class day8 {
 public:
  day8(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day8" / "input.txt"};
};

#endif //AOC2024_DAY8_DAY8_H_
