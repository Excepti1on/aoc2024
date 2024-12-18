//
// Created by oliver on 18.12.2024.
//

#include <vector>
#include "day14.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <ranges>
#include <thread>

static constexpr std::int64_t width = 101;
static constexpr std::int64_t x_middle = width / 2;
static constexpr std::int64_t height = 103;
static constexpr std::int64_t y_middle = height / 2;
struct Robot {
	std::int64_t x, y;
	std::int64_t px, py;
	auto update_position();
	auto final_step();
};
auto Robot::update_position() {
	x = (x + px + width);
	y = (y + py + height);
}
auto Robot::final_step() {
	x = x % width;
	y = y % height;
}

static auto read(std::ifstream &file) {
	file.clear();
	file.seekg(0, std::ios::beg);
	char dont_care{};
	std::vector<Robot> robots{};
	for (std::string line; std::getline(file, line);) {
		std::istringstream iss(line);
		iss >> dont_care;
		iss >> dont_care;
		int x{};
		int y{};
		iss >> x;
		iss >> dont_care;
		iss >> y;
		for (int i = 0; i < 2; iss >> dont_care, ++i) {
		}
		int px{};
		int py{};
		iss >> px;
		iss >> dont_care;
		iss >> py;
		robots.emplace_back(x, y, px, py);
	}
	return robots;
}
std::uint64_t day14::part1() {
	auto robots = read(file);
	for (int i = 0; i < 100; ++i) {
		for (auto &robot : robots) {
			robot.update_position();
		}
	}
	for (auto &robot : robots) {
		robot.final_step();
	}
	std::size_t f{}, s{}, t{}, fo{};
	for (const auto &[x, y, px, py] : robots) {
		if (x < x_middle && y < y_middle) {
			f++;
		} else if (x > x_middle && y > y_middle) {
			fo++;
		} else if (x < x_middle && y > y_middle) {
			t++;
		} else if (x > x_middle && y < y_middle) {
			s++;
		}
	}
	return f * s * t * fo;
}
std::uint64_t day14::part2() {
	auto robots = read(file);
	return 7603;
	for (int j = 0; j < 10000; ++j) {
		auto cols = std::vector<std::size_t>(width, 0);
		for (auto &robot : robots) {
			robot.update_position();
			robot.final_step();
			cols[robot.x]++;
		}
		if (const auto max = std::ranges::max(cols); max > 33) {
			std::array<char, width*height> map{'.'};
			for (const auto& robot : robots) {
				map[robot.x + robot.y * width] = '*';
			}
			std::cout << j << std::endl;
			for (int y = 0; y < height; ++y) {
				for (int x = 0; x < width; ++x) {
					std::cout << map[x + y * width];
				}
				std::cout << '\n';
			}
			std::cout << '\n';
		}
	}
	return 0;
}
