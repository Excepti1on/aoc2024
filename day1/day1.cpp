//
// Created by olive on 01/12/2024.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>

#include "day1.h"

std::uint64_t day1::part1() noexcept {
  input.clear();
  input.seekg(0, std::ios::beg);
  auto vec = std::views::istream<int>(input) | std::ranges::to<std::vector>();
  auto second = vec | std::views::drop(1) | std::views::stride(2);
  auto first = vec | std::views::stride(2);
  std::ranges::sort(first);
  std::ranges::sort(second);
  return *std::ranges::fold_left_first(std::views::zip_transform([](auto a, auto b) { return std::abs(a - b); },
                                                                 first,
                                                                 second), std::plus{});
}

std::uint64_t day1::part2() noexcept {
  input.clear();
  input.seekg(0, std::ios::beg);
  auto vec = std::views::istream<int>(input) | std::ranges::to<std::vector>();
  return *std::ranges::fold_left_first(std::views::transform(vec | std::views::stride(2),
                                                             [second = vec
                                                                 | std::views::drop(1)
                                                                 | std::views::stride(2)](const auto &el) {
                                                               return std::ranges::count(second, el) * el;
                                                             }), std::plus{});
}