//
// Created by oliver on 17.12.2024.
//

#ifndef DAY13_H
#define DAY13_H



#include <filesystem>
#include <fstream>
#include <cstdint>
class day13
{
	public:
	day13(const char* base_dir) : base_dir{base_dir} {}
	std::uint64_t part1();
	std::uint64_t part2();

	private:
	const std::filesystem::path base_dir;
	std::ifstream file{base_dir / "day13" / "input.txt"};
};



#endif //DAY13_H
