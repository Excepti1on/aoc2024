//
// Created by olive on 08/12/2024.
//

#include "day8.h"
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
#include <cmath>
#include <numeric>

static std::size_t x_max{};
static std::size_t y_max{};

struct position {
  std::int64_t x;
  std::int64_t y;
  position &operator+=(const position &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  friend position operator+(position lhs, const position &rhs) {
    lhs += rhs;
    return lhs;
  }
  position &operator-=(const position &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  friend position operator-(position lhs, const position &rhs) {
    lhs -= rhs;
    return lhs;
  }
  position &operator/=(const std::int64_t &rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
  }

  friend position operator-(position lhs, const std::int64_t &rhs) {
    lhs /= rhs;
    return lhs;
  }

  auto operator<=>(const position &) const = default;
};

static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::unordered_map<char, std::vector<position>> antennas;
  std::string line;
  for (int y = 0; std::getline(file, line); ++y) {
    x_max = line.length();
    y_max = y;
    for (int x = 0; x < line.length(); ++x) {
      if (line[x] != '.' && line[x] != '\n') {
        antennas[line[x]].emplace_back(x, y);
      }
    }
  }
  return antennas;
}
static auto contains(const position &pos) {
  return pos.x >= 0 && pos.x < x_max && pos.y >= 0 && pos.y <= y_max;
}
static std::pair<position, position> calculate_antinode(const position &first, const position &second) {
  auto x = first + (first - second);
  auto y = second + (second - first);
  return std::pair{x, y};
}
static std::vector<position> calculate_antinodes(const position &first, const position &second) {
  auto diff = (first - second);
  diff /= std::gcd(diff.x, diff.y);
  std::vector<position> result{};
  for (auto pos = first; contains(pos); pos += diff) {
    result.push_back(pos);
  }
  for (auto pos = first; contains(pos); pos -= diff) {
    result.push_back(pos);
  }
  return result;
}
std::uint64_t day8::part1() {
  auto antennas = read(file);
  std::set<position> antinodes;
  for (const auto &[freq, positions] : antennas) {
    for (int i = 0; i < positions.size(); ++i) {
      for (int j = i + 1; j < positions.size(); ++j) {
        auto [x, y] = calculate_antinode(positions[i], positions[j]);
        if (contains(x)) {
          antinodes.insert(x);
        }
        if (contains(y)) {
          antinodes.insert(y);
        }
      }
    }
  }
  return antinodes.size();
}
std::uint64_t day8::part2() {
  auto antennas = read(file);
  std::set<position> antinodes{};
  for (const auto &[freq, positions] : antennas) {
    for (int i = 0; i < positions.size(); ++i) {
      for (int j = i + 1; j < positions.size(); ++j) {
        auto pos = calculate_antinodes(positions[i], positions[j]);
        for (const auto &el : pos) {
          antinodes.insert(el);
        }
      }
    }
  }
  return antinodes.size();
}
