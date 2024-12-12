#include "day12.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <stack>
#include <utility>
#include <vector>

struct Region {
    char Plant{};
    std::set<std::pair<std::size_t, std::size_t>> plants{};
    std::uint64_t perimeter{};
    std::uint64_t sides{};
    void update_perimeter();
    void update_sides();
};
static auto read(std::ifstream& file) {
    file.clear();
    file.seekg(std::ios::beg);
    std::vector<std::vector<char>> plants{};
    for (std::string line{}; std::getline(file, line);) {
        plants.emplace_back();
        for (const auto& c : line) {
            plants.back().push_back(c);
        }
    }
    return plants;
}
std::set<std::pair<std::size_t, std::size_t>> bfs(
    std::pair<std::size_t, std::size_t> pos, const std::vector<std::vector<char>>& plants,
    std::set<std::pair<std::size_t, std::size_t>>& visited) {
    std::stack<std::pair<std::size_t, std::size_t>> queue{};
    queue.push(pos);
    visited.insert(pos);
    std::set<std::pair<std::size_t, std::size_t>> region{};
    region.insert(pos);
    auto plant = plants[pos.first][pos.second];
    while (!queue.empty()) {
        auto [x, y] = queue.top();
        queue.pop();
        if (x < plants.size() - 1 && plant == plants[x + 1][y]) {
            if (!visited.contains({x + 1, y})) {
                queue.push({x + 1, y});
                visited.insert({x + 1, y});
                region.insert({x + 1, y});
            }
        }
        if (y < plants[x].size() - 1 && plant == plants[x][y + 1]) {
            if (!visited.contains({x, y + 1})) {
                queue.push({x, y + 1});
                visited.insert({x, y + 1});
                region.insert({x, y + 1});
            }
        }
        if (x > 0 && plant == plants[x - 1][y]) {
            if (!visited.contains({x - 1, y})) {
                queue.push({x - 1, y});
                visited.insert({x - 1, y});
                region.insert({x - 1, y});
            }
        }

        if (y > 0 && plant == plants[x][y - 1]) {
            if (!visited.contains({x, y - 1})) {
                queue.push({x, y - 1});
                visited.insert({x, y - 1});
                region.insert({x, y - 1});
            }
        }
    }
    return region;
}
std::uint64_t day12::part1() {
    auto plants = read(file);
    std::set<std::pair<std::size_t, std::size_t>> visited{};
    std::vector<Region> regions{};
    for (std::size_t i = 0; i < plants.size(); ++i) {
        for (std::size_t j = 0; j < plants[i].size(); ++j) {
            if (!visited.contains({i, j})) {
                regions.emplace_back(plants[i][j], bfs({i, j}, plants, visited), 0, 0);
            }
        }
    }
    return std::transform_reduce(regions.begin(), regions.end(), 0ull, std::plus{},
                                 [](auto& region) {
                                     region.update_perimeter();
                                     return region.perimeter * region.plants.size();
                                 });
}

std::uint64_t day12::part2() {
    auto plants = read(file);
    std::set<std::pair<std::size_t, std::size_t>> visited{};
    std::vector<Region> regions{};
    for (std::size_t i = 0; i < plants.size(); ++i) {
        for (std::size_t j = 0; j < plants[i].size(); ++j) {
            if (!visited.contains({i, j})) {
                regions.emplace_back(plants[i][j], bfs({i, j}, plants, visited), 0, 0);
            }
        }
    }
    return std::transform_reduce(regions.begin(), regions.end(), 0ull, std::plus{},
                                 [](auto& region) {
                                     region.update_sides();
                                     return region.sides * region.plants.size();
                                 });
}

void Region::update_perimeter() {
    for (const auto& pos : plants) {
        perimeter += 4;
        if (plants.contains({pos.first - 1, pos.second})) {
            perimeter--;
        }
        if (plants.contains({pos.first + 1, pos.second})) {
            perimeter--;
        }
        if (plants.contains({pos.first, pos.second + 1})) {
            perimeter--;
        }
        if (plants.contains({pos.first, pos.second - 1})) {
            perimeter--;
        }
    }
}

void Region::update_sides() {
    for (const auto& pos : plants) {

        // o
        // x o
        if (!plants.contains({pos.first - 1, pos.second}) &&
            !plants.contains({pos.first, pos.second + 1})) {
            sides++;
        }
        //   o
        // o x
        if (!plants.contains({pos.first - 1, pos.second}) &&
            !plants.contains({pos.first, pos.second - 1})) {
            sides++;
        }
        // x o
        // o
        if (!plants.contains({pos.first + 1, pos.second}) &&
            !plants.contains({pos.first, pos.second + 1})) {
            sides++;
        }
        // o x
        //   o
        if (!plants.contains({pos.first + 1, pos.second}) &&
            !plants.contains({pos.first, pos.second - 1})) {
            sides++;
        }
        // x o
        // x x
        if (plants.contains({pos.first + 1, pos.second}) &&
            plants.contains({pos.first, pos.second - 1}) &&
            !plants.contains({pos.first + 1, pos.second - 1})) {
            sides++;
        }
        // x x
        // o x
        if (plants.contains({pos.first - 1, pos.second}) &&
            plants.contains({pos.first, pos.second - 1}) &&
            !plants.contains({pos.first - 1, pos.second - 1})) {
            sides++;
        }
        // o x
        // x x
        if (plants.contains({pos.first + 1, pos.second}) &&
            plants.contains({pos.first, pos.second + 1}) &&
            !plants.contains({pos.first + 1, pos.second + 1})) {
            sides++;
        }
        // x x
        // o x
        if (plants.contains({pos.first - 1, pos.second}) &&
            plants.contains({pos.first, pos.second + 1}) &&
            !plants.contains({pos.first - 1, pos.second + 1})) {
            sides++;
        }
    }
}
