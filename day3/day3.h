//
// Created by olive on 03/12/2024.
//

#ifndef AOC2024_DAY3_DAY3_H_
#define AOC2024_DAY3_DAY3_H_

#include <fstream>
#include <cstdint>
#include <filesystem>
class day3 {
 public:
    day3(char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1();
    std::uint64_t part2();

   private:
    const std::filesystem::path base_dir;
    std::ifstream file{base_dir / "day3" / "input.txt"};
};

#endif //AOC2024_DAY3_DAY3_H_
