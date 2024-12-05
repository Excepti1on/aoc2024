//
// Created by olive on 03/12/2024.
//

#include <sstream>
#include <regex>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string_view>
#include <spanstream>
#include "day3.h"

auto eval_mul(const std::string& val) {
  int first{};
  int second{};
  std::stringstream ss{val.substr(4)};
  char dont_care;
  ss >> first >> dont_care >> second >> dont_care;
  return first * second;
}

auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string temp{};
  std::string text{};
  while (file >> temp)
    text += temp;
  return text;
}

auto parse(std::string_view text, const std::regex &match_mul) {
  std::vector<std::string> found{};
  auto beg = std::regex_token_iterator(text.cbegin(), text.cend(), match_mul);
  std::copy(std::regex_token_iterator(text.cbegin(), text.cend(), match_mul),
            std::regex_token_iterator<std::string_view::const_iterator>(),
            *std::back_inserter(found));
  return found;
}
std::uint64_t day3::part1() {
  return *std::ranges::fold_left_first(
      parse(read(file), std::regex{R"(mul\([0-9]{1,3},[0-9]{1,3}\))"})
          | std::views::transform(eval_mul), std::plus{});
}
std::uint64_t day3::part2() {
  return *std::ranges::fold_left_first(
      parse(read(file), std::regex{R"((mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\)))"})
          | std::views::filter([do_ = true](std::string_view val) mutable {
            if (val == "do()") {
              do_ = true;
              return false;
            } else if (val == "don't()") {
              do_ = false;
              return false;
            } else if (!do_) {
              return false;
            }
            return true;
          })
          | std::views::transform(eval_mul), std::plus{});
}
