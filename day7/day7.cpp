//
// Created by olive on 07/12/2024.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include "day7.h"
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;

  // parse rules
  std::unordered_map<std::uint64_t, std::vector<std::uint64_t>> rules{};
  while (file.peek() != '\n' && std::getline(file, line)) {
    std::stringstream ss{line};
    std::uint64_t key{};
    char colon{};
    ss >> key >> colon;
    for (std::uint64_t val; ss >> val;) {
      rules[key].push_back(val);
    }
  }
  return rules;
}
std::uint64_t day7::part1() {
  auto eqs = read(file);
  std::uint64_t sum = 0;
  for (const auto &[key, value] : eqs) {
    auto positions = value.size() - 1;
    std::string ops(positions, 'a');
    ops += std::string(positions, 'm');
    std::unordered_set<std::string> op_set;
    do {
      op_set.insert(ops.substr(0, positions));
    } while (std::ranges::next_permutation(ops).found);
    for (const auto &op : op_set) {
      std::uint64_t result = value[0];
      for (std::uint64_t i = 0; i < positions; ++i) {
        switch (op[i]) {
          case 'a':result += value[i + 1];
            break;
          case 'm':result *= value[i + 1];
            break;
          default:break;
        }
      }
      if (result == key) {
        sum += key;
        break;
      }
    }
  }

  return sum;
}
[[gnu::always_inline]]
static inline std::uint64_t concatenate(std::uint64_t i, std::uint64_t j) {
  return std::stoull(std::format("{}{}", i, j));
}
std::uint64_t day7::part2() {
  auto eqs = read(file);
  std::uint64_t sum = 0;
#pragma omp parallel for reduction(+ : sum)
  for (const auto &[key, value] : eqs) {
    bool found = false;
    auto positions = value.size() - 1;
    std::string ops(positions, 'a');
    ops += std::string(positions, 'm');
    ops += std::string(positions, 'c');
    std::unordered_set<std::string> op_set;
    do {
      op_set.insert(ops.substr(0, positions));
    } while (std::ranges::next_permutation(ops).found);
    for (const auto &op : op_set) {
      std::uint64_t result = value[0];
      for (std::uint64_t i = 0; i < positions; ++i) {
        switch (op[i]) {
          case 'a':result += value[i + 1];
            break;
          case 'm':result *= value[i + 1];
            break;
          case 'c':result = concatenate(result, value[i + 1]);
            break;
          default:break;
        }
      }
      if (result == key) {
        found = true;
        break;
      }
    }
    if (found)
      sum += key;
  }

  return sum;
}
