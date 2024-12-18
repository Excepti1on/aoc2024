//
// Created by oliver on 18.12.2024.
//

#ifndef DAY14_H
#define DAY14_H
#include <filesystem>
#include <fstream>
#include <cstdint>
class day14 {
	public:
	day14(const char* base_dir) : base_dir{base_dir} {}
	std::uint64_t part1();
	std::uint64_t part2();

	private:
	const std::filesystem::path base_dir;
	std::ifstream file{base_dir / "day14" / "input.txt"};
};



#endif //DAY14_H
