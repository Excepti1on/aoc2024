//
// Created by olive on 09/12/2024.
//

#ifndef AOC2024_DAY9_DAY9_H_
#define AOC2024_DAY9_DAY9_H_
#include <fstream>
#include <cstdint>
#include <filesystem>
class day9 {
 public:
  day9(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day9" / "input.txt"};
};

#endif //AOC2024_DAY9_DAY9_H_
