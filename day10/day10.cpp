#include "day10.h"

#include <iostream>
#include <queue>
#include <vector>
static auto read(std::ifstream& file) {
    file.clear();
    file.seekg(std::ios::beg);
    std::vector<char> heightmap{};
    std::size_t size = 0;
    for (char c; file.get(c);) {
        if (c >= '0' && c <= '9') {
            heightmap.push_back(c);
            size++;
        } else {
            size = 0;
        }
    }
    return std::pair(heightmap, size);
}

static auto calculate_paths(std::size_t pos, const std::vector<char>& heightmap,
                            const std::size_t size) {
    std::size_t paths = 0;
    std::queue<std::size_t> Q{};
    Q.push(pos);
    while (!Q.empty()) {
        auto v = Q.front();
        Q.pop();
        if (v == '9') {
            paths++;
        }
        if (v + 1 < heightmap.size() - 1 && heightmap[v + 1] == heightmap[v] + 1) {
            Q.push(v + 1);
        }
        if (v - 1 >= 0 && heightmap[v - 1] == heightmap[v] + 1) {
            Q.push(v - 1);
        }
        if (v + size < heightmap.size() - 1 && heightmap[v + size] == heightmap[v] + 1) {
            Q.push(v + size);
        }
        if (v >= size && heightmap[v - size] == heightmap[v] + 1) {
            Q.push(v - size);
        }
    }
    return paths;
}
std::uint64_t day10::part1() {
    auto [heightmap, size] = read(file);
    std::vector<std::size_t> trailheads{};
    for (std::size_t i = 0; i < heightmap.size(); ++i) {
        if (heightmap[i] == '0') {
            trailheads.push_back(i);
        }
    }
    for (auto& head : trailheads) {
        head = calculate_paths(head, heightmap, size);
    }
    for (const auto& head : trailheads) {
        std::cout << head << std::endl;
    }
    return 0;
}

std::uint64_t day10::part2() { return 0; }
