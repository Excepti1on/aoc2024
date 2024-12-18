//
// Created by oliver on 18.12.2024.
//

#ifndef DAY15_H
#define DAY15_H
#include <filesystem>
#include <fstream>
#include <cstdint>
class day15 {
	public:
	day15(const char* base_dir) : base_dir{base_dir} {}
	std::uint64_t part1();
	std::uint64_t part2();

	private:
	const std::filesystem::path base_dir;
	std::ifstream file{base_dir / "day15" / "input.txt"};
};



#endif //DAY15_H
