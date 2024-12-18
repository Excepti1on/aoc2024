//
// Created by oliver on 18.12.2024.
//

#include "day15.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
enum type : char {
	wall = '#',
	box = 'O',
	empty = '.',
	robot = '@',
	lbox = '[',
	rbox = ']'
};
enum direction : char {
	up = '^',
	down = 'v',
	right = '>',
	left = '<'
};
struct grid {
	std::size_t width{}, height{};
	std::vector<type> nodes{};
	std::pair<std::size_t, std::size_t> position{};
	type operator[](const std::vector<type>::size_type y, const std::vector<type>::size_type x) const {
		return nodes[x + y * width];
	}
	template<typename T>
		requires std::is_same_v<T, std::vector<type>::value_type>
	auto emplace_back(T &&type) {
		return nodes.emplace_back(std::forward<T>(type));
	}
	template<bool do_move>
	bool move(direction dir, type type, const std::pair<std::size_t, std::size_t> &pos);
	auto inflate();
};
template<bool do_move>
auto grid::move(direction dir, type type, const std::pair<std::size_t, std::size_t> &pos) -> bool {
	switch (type) {
		case type::wall:
			return false;
		case type::empty:
			return true;
		case type::box:
		case type::robot:
		case type::lbox:
		case type::rbox: {
			switch (dir) {
				case direction::up: {
					if (type == type::lbox) {
						if (move<do_move>(dir, (*this)[pos.first - 1, pos.second], {pos.first - 1, pos.second}) &&
							move<do_move>(dir,
							              (*this)[pos.first - 1, pos.second + 1],
							              {pos.first - 1, pos.second + 1})) {
							if constexpr (do_move) {
								std::swap(nodes[pos.second + pos.first * width],
								          nodes[(pos.first - 1) * width + pos.second]);
								std::swap(nodes[pos.second + 1 + pos.first * width],
								          nodes[(pos.first - 1) * width + pos.second + 1]);
							}

							return true;
						}
						return false;
					}
					if (type == type::rbox) {
						if (move<do_move>(dir, (*this)[pos.first - 1, pos.second], {pos.first - 1, pos.second}) &&
							move<do_move>(dir,
							              (*this)[pos.first - 1, pos.second - 1],
							              {pos.first - 1, pos.second - 1})) {
							if constexpr (do_move) {
								std::swap(nodes[pos.second + pos.first * width],
								          nodes[(pos.first - 1) * width + pos.second]);
								std::swap(nodes[pos.second - 1 + pos.first * width],
								          nodes[(pos.first - 1) * width + pos.second - 1]);
							}

							return true;
						}
						return false;
					}
					if (move<do_move>(dir, (*this)[pos.first - 1, pos.second], {pos.first - 1, pos.second})) {
						if constexpr (do_move) {
							nodes[pos.second + pos.first * width] = type::empty;
							nodes[(pos.first - 1) * width + pos.second] = type;
							if (type == type::robot) {
								position.first--;
							}
						}

						return true;
					}
					return false;
				}
				case direction::down: {
					if (type == type::lbox) {
						if (move<do_move>(dir, (*this)[pos.first + 1, pos.second], {pos.first + 1, pos.second}) &&
							move<do_move>(dir,
							              (*this)[pos.first + 1, pos.second + 1],
							              {pos.first + 1, pos.second + 1})) {
							if constexpr (do_move) {
								std::swap(nodes[pos.second + pos.first * width],
								          nodes[(pos.first + 1) * width + pos.second]);
								std::swap(nodes[pos.second + 1 + pos.first * width],
								          nodes[(pos.first + 1) * width + pos.second + 1]);
							}
							return true;
						}
						return false;
					}
					if (type == type::rbox) {
						if (move<do_move>(dir, (*this)[pos.first + 1, pos.second], {pos.first + 1, pos.second}) &&
							move<do_move>(dir,
							              (*this)[pos.first + 1, pos.second - 1],
							              {pos.first + 1, pos.second - 1})) {
							if constexpr (do_move) {
								std::swap(nodes[pos.second + pos.first * width],
								          nodes[(pos.first + 1) * width + pos.second]);
								std::swap(nodes[pos.second - 1 + pos.first * width],
								          nodes[(pos.first + 1) * width + pos.second - 1]);
							}
							return true;
						}
						return false;
					}
					if (move<do_move>(dir, (*this)[pos.first + 1, pos.second], {pos.first + 1, pos.second})) {
						if constexpr (do_move) {
							nodes[pos.second + pos.first * width] = type::empty;
							nodes[(pos.first + 1) * width + pos.second] = type;
							if (type == type::robot) {
								position.first++;
							}
						}
						return true;
					}
					return false;
				}
				case direction::right:
					if (move<do_move>(dir, (*this)[pos.first, pos.second + 1], {pos.first, pos.second + 1})) {
						if constexpr (do_move) {
							nodes[pos.second + pos.first * width] = type::empty;
							nodes[pos.first * width + (pos.second + 1)] = type;
							if (type == type::robot) {
								position.second++;
							}
						}

						return true;
					}
					return false;
				case direction::left:
					if (move<do_move>(dir, (*this)[pos.first, pos.second - 1], {pos.first, pos.second - 1})) {
						if constexpr (do_move) {
							nodes[pos.second + pos.first * width] = type::empty;
							nodes[pos.first * width + (pos.second - 1)] = type;
							if (type == type::robot) {
								position.second--;
							}
						}
						return true;
					}
					return false;
			}
		}
	}
	return false;
}
auto grid::inflate() {
	std::vector<type> inflated{};
	for (auto &node : nodes) {
		if (node == type::robot) {
			inflated.emplace_back(type::robot);
			inflated.emplace_back(type::empty);
			continue;
		} else if (node == type::box) {
			inflated.emplace_back(type::lbox);
			inflated.emplace_back(type::rbox);
			continue;
		}
		inflated.emplace_back(node);
		inflated.emplace_back(node);
	}
	width *= 2;
	position.second *= 2;
	nodes.swap(inflated);
}
static auto read(std::ifstream &file) {
	file.clear();
	file.seekg(std::ios::beg);
	std::vector<direction> directions;
	grid grid_nodes{0, 0, {}};
	std::size_t height{0};
	while (file.peek() != '\n') {
		std::string line;
		std::getline(file, line);
		std::size_t width{0};
		for (const auto ch : line) {
			if (ch == '\n')break;
			switch (ch) {
				case '#':
					grid_nodes.emplace_back(type::wall);
					break;
				case '.':
					grid_nodes.emplace_back(type::empty);
					break;
				case 'O':
					grid_nodes.emplace_back(type::box);
					break;
				case '@':
					grid_nodes.emplace_back(type::robot);
					grid_nodes.position = std::make_pair(height, width);
				default:
					break;
			}
			width++;
		}
		height++;
		if (grid_nodes.width == 0) {
			grid_nodes.width = width;
		}
	}
	grid_nodes.height = height;
	for (std::string line; std::getline(file, line);) {
		for (const auto ch : line) {
			switch (ch) {
				case '^':
					directions.emplace_back(direction::up);
					break;
				case 'v':
					directions.emplace_back(direction::down);
					break;
				case '>':
					directions.emplace_back(direction::right);
					break;
				case '<':
					directions.emplace_back(direction::left);
					break;
				default:
					break;
			}
		}
	}
	return std::make_pair(grid_nodes, directions);
}
std::uint64_t day15::part1() {
	auto [grid, directions] = read(file);
	for (const auto &dir : directions) {
		grid.move<true>(dir, robot, grid.position);
	}
	auto sum{0ull};
	for (int i = 0; i < grid.height; ++i) {
		for (int j = 0; j < grid.width; ++j) {
			if (grid[i,j] == type::box) {
				sum += i * 100 + j;
			}
		}
	}
	return sum;
}
std::uint64_t day15::part2() {
	auto [grid, directions] = read(file);
	grid.inflate();
	for (const auto &dir : directions) {
		if (bool res = grid.move<false>(dir, robot, grid.position)) {
			grid.move<true>(dir, robot, grid.position);
		}
	}
	auto sum{0ull};
	for (std::size_t i = 0; i < grid.height; ++i) {
		for (std::size_t j = 0; j < grid.width; ++j) {
			if (grid[i,j] == type::lbox) {
				sum += (i) * 100 + j;
			}
		}
	}
	return sum;
}
