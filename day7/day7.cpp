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
#include "day7.h"

static inline std::uint64_t firstDigit(int n)
{
  // Find total number of digits - 1
  int digits = (int)std::log10(n);

  // Find first digit
  n = (int)(n / std::pow(10, digits));

  // Return first digit
  return n;
}
static auto generate_ops(std::string ops, std::size_t size)
{
  std::vector<std::vector<std::string>> all_ops(size);
  std::vector<std::string> op_set;
  for (int i = 0; i < ops.length(); ++i)
  {
    op_set.push_back(ops.substr(i, 1));
  }
  all_ops[1] = std::move(op_set);
  for (int i = 2; i < size; ++i)
  {
    std::vector<std::string> op_set;
    for (int j = 0; j < ops.length(); ++j)
    {
      for (const auto &str : all_ops[i - 1])
      {
        op_set.push_back(str + ops[j]);
      }
    }
    all_ops[i] = std::move(op_set);
  }
  return all_ops;
}
static auto read(std::ifstream &file)
{
  file.clear();
  file.seekg(std::ios::beg);
  std::string line;

  // parse rules
  std::vector<std::vector<std::uint64_t>> rules{};
  while (std::getline(file, line))
  {
    std::stringstream ss{line};
    std::uint64_t key{};
    char colon{};
    rules.emplace_back();
    ss >> key >> colon;
    rules.back().push_back(key);
    for (std::uint64_t val; ss >> val;)
    {
      rules.back().push_back(val);
    }
  }
  return rules;
}
std::uint64_t day7::part1()
{
  auto eqs = read(file);
  std::uint64_t sum = 0;
  auto all_ops = generate_ops("am", 12);
#pragma omp parallel for reduction(+ : sum)
  for (const auto &eq : eqs)
  {
    auto key = eq[0];
    bool found = false;
    auto positions = eq.size() - 2;
    for (const auto &op : all_ops.at(positions))
    {
      std::uint64_t result = eq[1];
      for (std::uint64_t i = 0; i < positions; ++i)
      {
        switch (op[i])
        {
        case 'a':
          result += eq[i + 2];
          break;
        case 'm':
          result *= eq[i + 2];
          break;
        default:
          break;
        }
      }
      if (result == key)
      {
        found = true;
        break;
      }
    }
    if (found)
      sum += key;
  }

  return sum;
}
[[gnu::always_inline]]
static inline std::uint64_t concatenate(std::uint64_t i, std::uint64_t j)
{
  return std::stoull(std::format("{}{}", i, j));
}

std::uint64_t day7::part2()
{
  auto eqs = read(file);
  std::uint64_t sum = 0;
  auto all_ops = generate_ops("acm", 12);
#pragma omp parallel for reduction(+ : sum)
  for (const auto &eq : eqs)
  {
    auto key = eq[0];
    bool found = false;
    auto positions = eq.size() - 2;
    for (const auto &op : all_ops.at(positions))
    {
      std::uint64_t result = eq[1];
      for (std::uint64_t i = 0; i < positions; ++i)
      {
        switch (op[i])
        {
        case 'a':
          result += eq[i + 2];
          break;
        case 'm':
          result *= eq[i + 2];
          break;
        case 'c':
          result = concatenate(result, eq[i + 2]);
        default:
          break;
        }
      }
      if (result == key)
      {
        found = true;
        break;
      }
    }
    if (found)
      sum += key;
  }

  return sum;
}
