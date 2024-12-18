//
// Created by olive on 02/12/2024.
//

#include <vector>
#include <sstream>
#include <algorithm>
#include <ranges>
#include <iostream>
#include "day2.h"

static auto parse(auto &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;
  std::vector<std::vector<int>> nums{};
  int index{0};
  while (std::getline(file, line)) {
    std::stringstream ss{line};
    nums.emplace_back();
    for (int i = 0; ss >> i;) {
      nums[index].push_back(i);
    }
    ++index;
  }
  return nums;
}

bool safe(const std::vector<int> &num) {
  auto view = num | std::views::adjacent_transform<2>([](auto first, auto second) { return first - second; });
  return std::ranges::all_of(view, [](const auto &el) { return el > 0 && el <= 3; })
      || std::ranges::all_of(view, [](const auto &el) { return el < 0 && el >= -3; });
}
std::uint64_t day2::part1() {
  return std::ranges::count_if(parse(file), safe);
}
std::uint64_t day2::part2() {
  return std::ranges::count_if(parse(file), [](std::vector<int> &num) {
    return std::ranges::any_of(std::views::repeat(num)|std::views::take(num.size()) | std::views::enumerate | std::views::transform([](std::tuple<int, std::vector<int>> el) {
                                     auto [key, value] = el;
                                     value.erase(value.begin() + key);
                                     return value;
                                   }), safe);
  });
}
