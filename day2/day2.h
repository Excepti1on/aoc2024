//
// Created by olive on 02/12/2024.
//

#ifndef AOC2024_DAY2_DAY2_H_
#define AOC2024_DAY2_DAY2_H_

#include <cstdint>
#include <fstream>
#include <filesystem>
class day2 {
 public:
    day2(char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1();
    std::uint64_t part2();

   private:
    const std::filesystem::path base_dir;
    std::ifstream file{base_dir / "day2" / "input.txt"};
};

#endif //AOC2024_DAY2_DAY2_H_
