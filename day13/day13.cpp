//
// Created by oliver on 17.12.2024.
//

#include "day13.h"
#include <vector>
#include <array>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <optional>
#include <ranges>
struct LE {
	std::int64_t ax, ay, bx, by, cx, cy;
};

static auto read(std::ifstream &file) {
	file.clear();
	file.seekg(std::ios::beg);
	std::vector<LE> eqs;
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		if (line.empty()) continue;
		auto xpos = line.find('X') + 1;
		auto ypos = line.find('Y') + 1;
		std::int64_t ax = std::stoll(line.substr(xpos));
		std::int64_t ay = std::stoll(line.substr(ypos));
		std::getline(file, line);
		xpos = line.find('X') + 1;
		ypos = line.find('Y') + 1;
		std::int64_t bx = std::stoll(line.substr(xpos));
		std::int64_t by = std::stoll(line.substr(ypos));
		std::getline(file, line);
		xpos = line.find('X') + 2;
		ypos = line.find('Y') + 2;
		std::int64_t cx = std::stoll(line.substr(xpos));
		std::int64_t cy = std::stoll(line.substr(ypos));
		eqs.emplace_back(ax, ay, bx, by, cx, cy);
	}
	return eqs;
}
static auto solve(const LE &le) -> std::int64_t{
	const auto delta = le.ax * le.by - le.bx * le.ay;
	const auto delta1 = le.cx * le.by - le.bx * le.cy;
	const auto delta2 = le.ax * le.cy - le.cx * le.ay;
	if (delta1 % delta != 0 || delta2 % delta != 0) {
		return 0ll;
	}
	return delta1 / delta * 3 + delta2 / delta;
}
std::uint64_t day13::part1() {
	return *std::ranges::fold_left_first(
		read(file) | std::views::transform(solve) | std::views::filter([](const auto &el) { return el != 0; }),
		std::plus{});
}
std::uint64_t day13::part2() {
	return *std::ranges::fold_left_first(
		read(file) | std::views::transform([](auto &el) {
			auto res = el;
			res.cx += 10000000000000;
			res.cy += 10000000000000;
			return res;
		}) | std::views::transform(solve) | std::views::filter([](const auto &el) { return el != 0; }),
		std::plus{});
}
