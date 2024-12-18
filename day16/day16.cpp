//
// Created by olive on 18/12/2024.
//

#include "day16.h"
#include <algorithm>
#include <ranges>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <set>
enum Direction : char {
  up = 0,
  right = 1,
  down = 2,
  left = 3
};
enum class Type {
  Wall,
  Path,
  Start,
  Goal
};

struct Lab {
  std::vector<Type> data;
  std::size_t width;
  std::size_t height;
};

struct Path {
  std::size_t pos;
  Direction incoming;
  std::unordered_map<Direction, std::size_t> neighbours{};
  std::size_t cost{std::numeric_limits<std::size_t>::max()};
  std::vector<std::size_t> prev{};
};

struct Compare {
  auto operator()(const Path &a, const Path &b) {
    return a.cost > b.cost;
  }
};
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::vector<Type> maze{};
  std::size_t height{0}, width{0};
  for (std::string line; std::getline(file, line);) {
    width = line.length();
    for (const char c : line) {
      switch (c) {
        case '#':maze.emplace_back(Type::Wall);
          break;
        case '.':maze.emplace_back(Type::Path);
          break;
        case 'S':maze.emplace_back(Type::Start);
          break;
        case 'E':maze.emplace_back(Type::Goal);
          break;
        default:break;
      }
    }
    height++;
  }
  return Lab{.data=std::move(maze), .width=width, .height=height};
}

static auto generate_neighbours(const Lab &lab) {
  auto width = lab.width;
  auto height = lab.height;
  std::map<std::size_t, Path> paths{};
  for (std::size_t y = 0; y < lab.height; ++y) {
    for (std::size_t x = 0; x < lab.width; ++x) {
      if (lab.data[x + y * lab.width] == Type::Wall) {
        continue;
      }
      Path path{};
      if (lab.data[x + y * width] == Type::Start) {
        path.incoming = Direction::right;
      }
      path.pos = x + y * lab.width;
      if (x > 0 && lab.data[x - 1 + y * width] != Type::Wall) {
        path.neighbours.emplace(left, x - 1 + y * width);
      }
      if (x < width - 1 && lab.data[x + 1 + y * width] != Type::Wall) {
        path.neighbours.emplace(right, x + 1 + y * width);
      }
      if (y > 0 && lab.data[x + (y - 1) * width] != Type::Wall) {
        path.neighbours.emplace(up, x + (y - 1) * width);
      }
      if (y < height - 1 && lab.data[x + (y + 1) * width] != Type::Wall) {
        path.neighbours.emplace(down, x + (y + 1) * width);
      }
      paths.emplace(x + y * width, std::move(path));
    }
  }
  return paths;
}
static auto calculate_cost(Direction from, Direction to) -> std::uint64_t {
  switch (std::abs(from - to)) {
    case 0:return 1;
    case 1:return 1001;
    case 2:return 2001;
    case 3:return 1001;
    default:return 0;
  }
}
static auto dijkstra(std::size_t start, std::map<std::size_t, Path> &&paths) {
  //std::priority_queue<Path, std::vector<Path>, Compare> queue{};
  std::vector<Path> queue{};
  paths[start].cost = 0;
  queue.push_back(paths[start]);
  std::ranges::push_heap(queue, Compare{});
  for (auto &[pos, path] : paths) {
    if (pos == start)continue;
    paths[pos].cost = 10000;
    queue.push_back(paths[pos]);
    std::ranges::push_heap(queue, Compare{});
  }
  while (!queue.empty()) {
    std::ranges::pop_heap(queue, Compare{});
    auto min = queue.back();
    queue.pop_back();
    for (auto [dir, pos] : min.neighbours) {
      auto alt = min.cost + calculate_cost(min.incoming, dir);
      if (alt < paths[pos].cost) {
        paths[pos].prev.push_back(min.pos);
        paths[pos].cost = alt;
        paths[pos].incoming = dir;
        queue.push_back(paths[pos]);
        std::ranges::push_heap(queue, Compare{});
      }
    }
  }
  return std::move(paths);
}
static auto calculate_paths(const std::map<std::size_t, Path> &paths,
                            std::size_t pos,
                            std::set<std::size_t> &&positions) -> std::set<std::size_t> {
  positions.insert(pos);
  for (const auto &cur_pos : paths.at(pos).prev) {
    positions = calculate_paths(paths, cur_pos, std::move(positions));
  }
  return std::move(positions);
}
std::uint64_t day16::part1() {
  auto lab = read(file);
  auto paths = generate_neighbours(lab);
  auto start_pos = std::ranges::distance(lab.data.begin(), std::ranges::find(lab.data, Type::Start));
  auto end_pos = std::ranges::distance(lab.data.begin(), std::ranges::find(lab.data, Type::Goal));
  auto dists = dijkstra(start_pos, std::move(paths));
  return dists[end_pos].cost;
}
std::uint64_t day16::part2() {
  auto lab = read(file);
  auto paths = generate_neighbours(lab);
  auto start_pos = std::ranges::distance(lab.data.begin(), std::ranges::find(lab.data, Type::Start));
  auto end_pos = std::ranges::distance(lab.data.begin(), std::ranges::find(lab.data, Type::Goal));
  auto dists = dijkstra(start_pos, std::move(paths));
  //auto positions = calculate_paths(dists, end_pos, std::set<std::size_t>{});
  for (int i = 0; i < lab.height; ++i) {
    for (int j = 0; j < lab.width; ++j) {
      if (!dists.contains(j + i * lab.width)) std::cout << "##### ";
      else {
        std::cout << std::setw(5) << std::setfill('0') << dists[j + i * lab.width].cost << ' ';
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
