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
  auto second =
      std::views::istream<int>(input) | std::views::drop(1) | std::views::stride(2) | std::ranges::to<std::vector>();
  input.clear();
  input.seekg(0, std::ios::beg);
  auto first = std::views::istream<int>(input) | std::views::stride(2) | std::ranges::to<std::vector>();
  std::ranges::sort(first);
  std::ranges::sort(second);
  return *std::ranges::fold_left_first(std::views::zip_transform([](auto a, auto b) { return std::abs(a - b); },
                                                                 first,
                                                                 second), std::plus{});
}

std::uint64_t day1::part2() noexcept {
  input.clear();
  input.seekg(0, std::ios::beg);
  auto second =
      std::views::istream<int>(input) | std::views::drop(1) | std::views::stride(2) | std::ranges::to<std::vector>();
  input.clear();
  input.seekg(0, std::ios::beg);
  auto first = std::views::istream<int>(input) | std::views::stride(2);
  return *std::ranges::fold_left_first(std::views::transform(first,
                                                             [&second](const auto &el) {
                                                               return std::ranges::count(second, el);
                                                             }), std::plus{});
}