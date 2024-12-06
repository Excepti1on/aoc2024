#include "day6.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <print>
#include <ranges>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
struct hashFunction {
    size_t operator()(const std::array<size_t, 3>& x) const {
        return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x);
    }
};
enum direction { up, right, down, left };
static auto read(std::ifstream& file) {
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

static auto patrol(std::array<std::size_t, 3> start, const std::vector<std::vector<bool>>& pos) {
    std::vector<std::vector<bool>> visited;
    for (std::size_t i = 0; i < pos.size(); ++i) {
        visited.emplace_back(pos[i].size(), false);
    }
    while (start[0] >= 0 && start[0] < pos.size() && start[1] >= 0 && start[1] < pos[0].size()) {
        visited[start[0]][start[1]] = true;
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
        } catch (const std::exception& e) {
            break;
        }
    }
    return visited;
}
static auto find_loop(std::array<std::size_t, 3> start, const std::vector<std::vector<bool>>& pos) {
    std::unordered_set<std::array<std::size_t, 3>, hashFunction> visited{};
    while (start[0] >= 0 && start[0] < pos.size() && start[1] >= 0 && start[1] < pos[0].size()) {
        if(visited.contains(start)){
            return 1;
        }
        visited.insert(start);
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
        } catch (const std::exception& e) {
            break;
        }
    }
    return 0;
}
std::uint64_t day6::part1() {
    auto [start, pos] = read(file);

    return *std::ranges::fold_left_first(patrol(start, pos) | std::views::join,
                                         std::plus{});
}

std::uint64_t day6::part2() { 
    auto [start, pos] = read(file);
    uint64_t sum = 0;
    auto position = start;
    auto visited = patrol(start, pos);
    for(int i = 0; i < pos.size(); ++i){
        for(int j = 0; j < pos[i].size(); ++j){
            if(!visited[i][j]){
                continue;
            }
            bool was_false = false;
            if(pos[i][j] != true){
                pos[i][j] = true;
                was_false = true;
            }
            sum += find_loop(start, pos);
            if(was_false){
                pos[i][j] = false;
            }
        }
    }
    return sum;
}
