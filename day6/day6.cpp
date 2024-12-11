#include "day6.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <print>
#include <ranges>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <std::size_t N>
struct hashFunction {
    size_t operator()(const std::array<size_t, N> &x) const {
        if constexpr (N == 2) {
            const auto a = x[0];
            const auto b = x[1];
            return (a + b) * (a + b + 1) / 2 + a;
        } else {
            return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x);
        }
    }
};

enum direction : std::size_t { up, right, down, left };

static auto read(std::ifstream &file) {
    file.clear();
    file.seekg(std::ios::beg);
    std::string line;
    std::vector<std::vector<bool>> positions;
    std::array<std::size_t, 3> start;
    for (std::size_t i = 0; std::getline(file, line); ++i) {
        positions.emplace_back();
        for (std::size_t j = 0; j < line.length(); ++j) {
            switch (line[j]) {
                case '#':
                    positions[i].push_back(true);
                    break;
                case '.':
                    positions[i].push_back(false);
                    break;
                case '^':
                    positions[i].push_back(false);
                    start = {i, j, direction::up};
                default:
                    break;
            }
        }
    }
    return std::pair{start, positions};
}

static auto patrol(std::array<std::size_t, 3> start, const std::vector<std::vector<bool>> &pos) {
    std::unordered_set<std::array<std::size_t, 2>, hashFunction<2>> visited{};
    while (start[0] < pos.size() && start[1] < pos[0].size()) {
        visited.insert({start[0], start[1]});
        try {
            switch (start[2]) {
                case direction::up:
                    if (pos.at(start[0] - 1).at(start[1])) {
                        start[2] = direction::right;
                    } else {
                        start[0]--;
                    }
                    break;
                case direction::right:
                    if (pos.at(start[0]).at(start[1] + 1)) {
                        start[2] = direction::down;
                    } else {
                        start[1]++;
                    }
                    break;
                case direction::down:
                    if (pos.at(start[0] + 1).at(start[1])) {
                        start[2] = direction::left;
                    } else {
                        start[0]++;
                    }
                    break;
                case direction::left:
                    if (pos.at(start[0]).at(start[1] - 1)) {
                        start[2] = direction::up;
                    } else {
                        start[1]--;
                    }
                    break;
                default:
                    break;
            }
        } catch (const std::out_of_range &e) {
            break;
        }
    }
    return std::vector(visited.begin(), visited.end());
}
static auto find_loop(std::array<std::size_t, 3> start, const std::vector<std::vector<bool>> &pos) {
    std::unordered_set<std::array<std::size_t, 3>, hashFunction<3>> visited{};
    while (start[0] < pos.size() && start[1] < pos[0].size()) {
        if (visited.contains(start)) {
            return 1;
        }
        visited.insert(start);
        try {
            switch (start[2]) {
                case direction::up:
                    if (pos.at(start[0] - 1)[start[1]]) {
                        start[2] = direction::right;
                    } else {
                        while (!pos.at(start[0] - 1)[start[1]]) {
                            start[0]--;
                        }
                    }
                    break;
                case direction::right:
                    if (pos[start[0]].at(start[1] + 1)) {
                        start[2] = direction::down;
                    } else {
                        while (!pos[start[0]].at(start[1] + 1)) {
                            start[1]++;
                        }
                    }
                    break;
                case direction::down:
                    if (pos.at(start[0] + 1)[start[1]]) {
                        start[2] = direction::left;
                    } else {
                        while (!pos.at(start[0] + 1)[start[1]]) {
                            start[0]++;
                        }
                    }
                    break;
                case direction::left:
                    if (pos[start[0]].at(start[1] - 1)) {
                        start[2] = direction::up;
                    } else {
                        while (!pos[start[0]].at(start[1] - 1)) {
                            start[1]--;
                        }
                    }
                    break;
                default:
                    break;
            }
        } catch (const std::out_of_range &e) {
            break;
        }
    }
    return 0;
}

std::uint64_t day6::part1() {
    auto [start, pos] = read(file);
    return patrol(start, pos).size();
}

std::uint64_t day6::part2() {
    auto [start, pos] = read(file);
    uint64_t sum = 0;
    auto visited = patrol(start, pos);
#pragma omp parallel for reduction(+ : sum) firstprivate(pos)
    for (auto &vis : visited) {
        pos[vis[0]][vis[1]] = true;
        sum += find_loop(start, pos);
        pos[vis[0]][vis[1]] = false;
    }
    return sum;
}
