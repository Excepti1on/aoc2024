//
// Created by olive on 07/12/2024.
//

#ifndef AOC2024_DAY7_DAY7_H_
#define AOC2024_DAY7_DAY7_H_
#include <fstream>
#include <cstdint>
#include <filesystem>
class day7 {
 public:
  day7(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day7" / "input.txt"};
};

#endif //AOC2024_DAY7_DAY7_H_
