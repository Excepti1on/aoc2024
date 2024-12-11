#include "day10.h"

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::vector<char> heightmap{};
  std::size_t size = 0;
  std::size_t pos = 0;
  for (char c; file.get(c);) {
    if (c >= '0' && c <= '9') {
      heightmap.push_back(c);
      pos++;
    } else {
      size = pos;
      pos = 0;
    }
  }
  return std::pair(heightmap, size);
}

static auto calculate_paths(std::size_t pos, const std::vector<char> &heightmap,
                            const std::size_t size) {
  std::size_t paths = 0;
  std::queue<std::size_t> Q{};
  std::vector<char> visited(size * size, 0);
  Q.push(pos);
  visited[pos] = 1;
  while (!Q.empty()) {
    auto v = Q.front();
    Q.pop();
    if (heightmap[v] == '9') {
      paths++;
    }
    if ((v % size != size - 1) && (heightmap[v + 1] == heightmap[v] + 1) && !visited[v + 1]) {
      Q.push(v + 1);
      visited[v + 1] = 1;
    }
    if ((v % size != 0) && (heightmap[v - 1] == heightmap[v] + 1) && !visited[v - 1]) {
      Q.push(v - 1);
      visited[v - 1] = 1;
    }
    if ((v + size < heightmap.size()) && (heightmap[v + size] == heightmap[v] + 1) && !visited[v + size]) {
      Q.push(v + size);
      visited[v + size] = 1;
    }
    if ((v >= size) && (heightmap[v - size] == heightmap[v] + 1) && !visited[v - size]) {
      Q.push(v - size);
      visited[v - size] = 1;
    }
  }
  return paths;
}
static auto calculate_ratings(std::size_t pos, const std::vector<char> &heightmap,
                              const std::size_t size) {
  std::size_t paths = 0;
  std::stack<std::size_t> Q{};
  Q.push(pos);
  while (!Q.empty()) {
    auto v = Q.top();
    Q.pop();
    if (heightmap[v] == '9') {
      paths++;
    }
    if ((v % size != size - 1) && (heightmap[v + 1] == heightmap[v] + 1)) {
      Q.push(v + 1);
    }
    if ((v % size != 0) && (heightmap[v - 1] == heightmap[v] + 1)) {
      Q.push(v - 1);
    }
    if ((v + size < heightmap.size()) && (heightmap[v + size] == heightmap[v] + 1)) {
      Q.push(v + size);
    }
    if ((v >= size) && (heightmap[v - size] == heightmap[v] + 1)) {
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
  for (auto &head : trailheads) {
    head = calculate_paths(head, heightmap, size);
  }
  return *std::ranges::fold_left_first(trailheads, std::plus{});
}

std::uint64_t day10::part2() {
  auto [heightmap, size] = read(file);
  std::vector<std::size_t> trailheads{};
  for (std::size_t i = 0; i < heightmap.size(); ++i) {
    if (heightmap[i] == '0') {
      trailheads.push_back(i);
    }
  }
  for (auto &head : trailheads) {
    head = calculate_ratings(head, heightmap, size);
  }
  return *std::ranges::fold_left_first(trailheads, std::plus{});
}
