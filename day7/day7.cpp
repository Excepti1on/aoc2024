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
#include <omp.h>
#include <cmath>
#include <span>
#include "day7.h"

static inline std::uint64_t firstDigit(int n) {
  // Find total number of digits - 1
  int digits = (int)std::log10(n);

  // Find first digit
  n = (int)(n / std::pow(10, digits));

  // Return first digit
  return n;
}
static auto generate_ops(std::string ops, std::size_t size) {
  std::vector<std::vector<std::string>> all_ops(size);
  std::vector<std::string> op_set;
  for (int i = 0; i < ops.length(); ++i) {
    op_set.push_back(ops.substr(i, 1));
  }
  all_ops[1] = std::move(op_set);
  for (int i = 2; i < size; ++i) {
    std::vector<std::string> op_set;
    for (int j = 0; j < ops.length(); ++j) {
      for (const auto &str : all_ops[i - 1]) {
        op_set.push_back(str + ops[j]);
      }
    }
    all_ops[i] = std::move(op_set);
  }
  return all_ops;
}
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;

  // parse rules
  std::vector<std::vector<std::uint64_t>> rules{};
  while (std::getline(file, line)) {
    std::stringstream ss{line};
    std::uint64_t key{};
    char colon{};
    rules.emplace_back();
    ss >> key >> colon;
    rules.back().push_back(key);
    for (std::uint64_t val; ss >> val;) {
      rules.back().push_back(val);
    }
  }
  return rules;
}
static auto can_make(std::uint64_t result, std::span<std::uint64_t> rest, bool concat) {
  if (rest.size() == 1) {
    return result == rest[0];
  }
  bool possible_mul, possible_concat, possible_add;
  auto last = rest.back();
  if (result % last == 0) {
    possible_mul = can_make(result / last, rest.subspan(0, rest.size() - 1), concat);
  } else {
    possible_mul = false;
  }
  if (concat) {
    auto next_power_of_ten = 1;
    while (next_power_of_ten <= last) {
      next_power_of_ten *= 10;
    }
    if ((result - last) % next_power_of_ten == 0) {
      possible_concat = can_make((result - last) / next_power_of_ten, rest.subspan(0, rest.size() - 1), concat);
    } else {
      possible_concat = false;
    }
  } else {
    possible_concat = false;
  }

  possible_add = can_make(result - last, rest.subspan(0, rest.size() - 1), concat);
  return possible_mul || possible_concat || possible_add;
}
std::uint64_t day7::part1() {
  auto eqs = read(file);
  std::uint64_t sum = 0;
  for (auto &eq : eqs) {
    auto result = eq[0];
    const auto rest = std::span(eq).subspan(1);
    if (can_make(result, rest, false)) {
      sum += result;
    }
  }
  return sum;
}

std::uint64_t day7::part2() {
  auto eqs = read(file);
  std::uint64_t sum = 0;
  for (auto &&eq : eqs) {
    auto result = eq[0];
    const auto rest = std::span(eq).subspan(1);
    if (can_make(result, rest, true)) {
      sum += result;
    }
  }
  return sum;
}
