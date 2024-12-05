//
// Created by olive on 05/12/2024.
//

#ifndef AOC2024_DAY5_DAY5_H_
#define AOC2024_DAY5_DAY5_H_

#include <fstream>
#include <cstdint>
#include <filesystem>
class day5 {
  public:
    day5(const char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1();
    std::uint64_t part2();

   private:
    const std::filesystem::path base_dir;
    std::ifstream file{base_dir / "day5" / "input.txt"};
};

#endif //AOC2024_DAY5_DAY5_H_
