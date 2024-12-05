//
// Created by olive on 05/12/2024.
//

#include <vector>

#include "day4.h"

static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;
  std::vector<std::string> text;
  while (std::getline(file, line))
    text.push_back(line);
  return text;
}

bool check_xmas(char x, char m, char a, char s) { return std::string{x, m, a, s} == "XMAS"; }
bool check_mas(char m, char s) { return std::string{m, s} == "MS" || std::string{s, m} == "MS"; }
std::uint64_t day4::part1() {
  auto text = read(file);
  auto sum{0};
  for (int i{}; i < text.size(); ++i) {
    for (int j = 0; j < text[i].length(); ++j) {
      if (text[i][j] != 'X') continue;
      try {
        sum += check_xmas(text.at(i).at(j), text.at(i).at(j + 1), text.at(i).at(j + 2), text.at(i).at(j + 3));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum += check_xmas(text.at(i).at(j), text.at(i).at(j - 1), text.at(i).at(j - 2), text.at(i).at(j - 3));
      } catch (const std::out_of_range &e) {
      }
      try {
        sum += check_xmas(text.at(i).at(j), text.at(i + 1).at(j), text.at(i + 2).at(j), text.at(i + 3).at(j));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum += check_xmas(text.at(i).at(j), text.at(i - 1).at(j), text.at(i - 2).at(j), text.at(i - 3).at(j));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum +=
            check_xmas(text.at(i).at(j), text.at(i + 1).at(j + 1), text.at(i + 2).at(j + 2), text.at(i + 3).at(j + 3));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum +=
            check_xmas(text.at(i).at(j), text.at(i - 1).at(j + 1), text.at(i - 2).at(j + 2), text.at(i - 3).at(j + 3));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum +=
            check_xmas(text.at(i).at(j), text.at(i + 1).at(j - 1), text.at(i + 2).at(j - 2), text.at(i + 3).at(j - 3));
      } catch (const std::out_of_range &e) {
      }

      try {
        sum +=
            check_xmas(text.at(i).at(j), text.at(i - 1).at(j - 1), text.at(i - 2).at(j - 2), text.at(i - 3).at(j - 3));
      } catch (const std::out_of_range &e) {
      }
    }
  }
  return sum;
}
std::uint64_t day4::part2() {
  auto text = read(file);
  auto sum{0};
  for (int i = 0; i < text.size(); ++i) {
    for (int j = 0; j < text[i].length(); ++j) {
      if (text[i][j] != 'A')continue;
      try {
        sum += check_mas(text.at(i + 1).at(j + 1), text.at(i - 1).at(j - 1)) &&
            check_mas(text.at(i - 1).at(j + 1), text.at(i + 1).at(j - 1));
      } catch (const std::out_of_range &e) {
      }
    }
  }
  return sum;
}
