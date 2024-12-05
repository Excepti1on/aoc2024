//
// Created by olive on 01/12/2024.
//

#ifndef AOC2024_DAY1_DAY1_H_
#define AOC2024_DAY1_DAY1_H_

#include <cstdint>
#include <filesystem>
#include <fstream>
class day1 {
   public:
    day1(char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1() noexcept;
    std::uint64_t part2() noexcept;

   private:
    const std::filesystem::path base_dir;
    std::ifstream input{base_dir / "day1" / "input.txt"};
};

#endif  // AOC2024_DAY1_DAY1_H_
