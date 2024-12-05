//
// Created by olive on 05/12/2024.
//

#ifndef AOC2024_DAY4_DAY4_H_
#define AOC2024_DAY4_DAY4_H_

#include <fstream>
#include <cstdint>
#include <filesystem>
class day4 {
  public:
    day4(const char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1();
    std::uint64_t part2();

   private:
    const std::filesystem::path base_dir;
    std::ifstream file{base_dir / "day4" / "input.txt"};
};

#endif //AOC2024_DAY4_DAY4_H_
