//
// Created by olive on 05/12/2024.
//

#include "day5.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;

  // parse rules
  std::unordered_map<int, std::unordered_set<int>> rules{};
  while (file.peek() != '\n' && std::getline(file, line)) {
    std::stringstream ss{line};
    int key = 0;
    int value = 0;
    char bar = 0;
    ss >> key >> bar >> value;
    rules[key].insert(value);
  }

  // parse books
  file.get();
  std::vector<std::vector<int>> books;
  char comma = 0;
  while (std::getline(file, line)) {
    std::stringstream ss{line};
    books.emplace_back();
    for (int i = 0; ss >> i;) {
      books.back().push_back(i);
      ss >> comma;
    }
  }
  return std::pair{rules, books};
}

std::uint64_t day5::part1() {
  auto [rules, books] = read(file);
  return *std::ranges::fold_left_first(
      books | std::views::filter([&](auto &book) {
        return std::ranges::all_of(
            book | std::views::adjacent_transform<2>(
                [&](auto first, auto second) { return rules[first].contains(second); }),
            std::identity{});
      }) | std::views::transform([](const auto &book) { return book[book.size() / 2]; }),
      std::plus{});
}
std::uint64_t day5::part2() {
  auto [rules, books] = read(file);
  return *std::ranges::fold_left_first(
      books | std::views::filter([&](auto &book) {
        return !std::ranges::all_of(
            book | std::views::adjacent_transform<2>(
                [&](auto first, auto second) { return rules[first].contains(second); }),
            std::identity{});
      }) | std::views::transform([&](auto &el) {
        std::ranges::sort(
            el, [&](auto first, auto second) { return rules[first].contains(second); });
        return el[el.size() / 2];
      }),
      std::plus{});
}
