//
// Created by olive on 06/12/2024.
//
#include <cassert>
#include <iostream>

#include "../day1/day1.h"
#include "../day10/day10.h"
#include "../day11/day11.h"
#include "../day12/day12.h"
#include "../day13/day13.h"
#include "../day2/day2.h"
#include "../day3/day3.h"
#include "../day4/day4.h"
#include "../day5/day5.h"
#include "../day6/day6.h"
#include "../day7/day7.h"
#include "../day8/day8.h"
#include "../day9/day9.h"
int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "missing argument" << std::endl;
		return -1;
	} {
		day1 day_1{argv[1]};
		assert(day_1.part1() == 3246517);
		assert(day_1.part2() == 29379307);
		std::cout << "day1 succeded" << std::endl;
	} {
		day2 day_2{argv[1]};
		assert(day_2.part1() == 332);
		assert(day_2.part2() == 398);
		std::cout << "day2 succeded" << std::endl;
	} {
		day3 day_3{argv[1]};
		assert(day_3.part1() == 184511516);
		assert(day_3.part2() == 90044227);
		std::cout << "day3 succeded" << std::endl;
	} {
		day4 day_4{argv[1]};
		assert(day_4.part1() == 2507);
		assert(day_4.part2() == 1969);
		std::cout << "day4 succeded" << std::endl;
	} {
		day5 day_5{argv[1]};
		assert(day_5.part1() == 7307);
		assert(day_5.part2() == 4713);
		std::cout << "day5 succeded" << std::endl;
	} {
		day6 day_5{argv[1]};
		assert(day_5.part1() == 5199);
		assert(day_5.part2() == 1915);
		std::cout << "day6 succeded" << std::endl;
	} {
		day7 day_5{argv[1]};
		assert(day_5.part1() == 4998764814652);
		assert(day_5.part2() == 37598910447546);
		std::cout << "day7 succeded" << std::endl;
	} {
		day8 day_5{argv[1]};
		assert(day_5.part1() == 426);
		assert(day_5.part2() == 1359);
		std::cout << "day8 succeded" << std::endl;
	} {
		day9 day_5{argv[1]};
		assert(day_5.part1() == 1928);
		assert(day_5.part2() == 2858);
		std::cout << "day9 succeded" << std::endl;
	} {
		day10 day_5{argv[1]};
		assert(day_5.part1() == 566);
		assert(day_5.part2() == 1324);
		std::cout << "day10 succeded" << std::endl;
	} {
		day11 day_5{argv[1]};
		assert(day_5.part1() == 199986);
		assert(day_5.part2() == 236804088748754);
		std::cout << "day11 succeded" << std::endl;
	}{
		day12 day_5{argv[1]};
		assert(day_5.part1() == 1464678);
		assert(day_5.part2() == 877492);
		std::cout << "day11 succeded" << std::endl;
	}{
		day13 day_5{argv[1]};
		assert(day_5.part1() == 37680);
		assert(day_5.part2() == 87550094242995);
		std::cout << "day11 succeded" << std::endl;
	}
}
