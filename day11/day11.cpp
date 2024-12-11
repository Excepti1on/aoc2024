//
// Created by olive on 11/12/2024.
//

#include "day11.h"
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <functional>
static std::unordered_multimap<std::int64_t, std::pair<std::int64_t, std::int64_t>> stones{};
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::vector<std::int64_t> nums{};
  for (std::int64_t i; file >> i;) {
    nums.push_back(i);
  }
  return nums;
}

static std::int64_t count_stones(std::int64_t stone, std::int64_t n) {
  if (stones.contains(stone)) {
    auto [beg, end] = stones.equal_range(stone);
    for (auto it = beg; it != end; ++it) {
      if (it->second.first == n) {
        return it->second.second;
      }
    }
  }
  if (n == 0) {
    stones.emplace(stone, std::pair{n,1});
    return 1;
  } else if (stone == 0) {
    auto val = count_stones(1, n-1);
    stones.emplace(stone, std::pair{n,val});
    return val;
  } else {
    std::int64_t num_digits = std::floor(std::log10(stone)) + 1;
    if (num_digits % 2 == 0) {
      std::int64_t d = std::pow(10, num_digits / 2);
      auto val = count_stones(stone / d, n - 1) + count_stones(stone % d, n - 1);
      stones.emplace(stone, std::pair{n,val});
      return val;
    } else {
      auto val = count_stones(stone * 2024, n - 1);
      stones.emplace(stone, std::pair{n,val});
      return val;
    }
  }
}
std::uint64_t day11::part1() {
  auto nums = read(file);
  auto count = [](const auto& el){
    return count_stones(el, 25);
  };
  return *std::ranges::fold_left_first(nums | std::views::transform(count), std::plus{});
}
std::uint64_t day11::part2() {
  auto nums = read(file);
    auto count = [](const auto& el){
    return count_stones(el, 75);
  };
  return *std::ranges::fold_left_first(nums | std::views::transform(count), std::plus{});
}
