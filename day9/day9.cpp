//
// Created by olive on 09/12/2024.
//

#include "day9.h"
#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <queue>

static constexpr std::array<std::size_t, 11> EXTRA{0, 0, 1, 3, 6, 10, 15, 21, 28, 36};
static auto read(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::vector<std::int64_t> filesystem;
  bool is_file = true;
  int id = 0;
  for (char c{}; file.get(c);) {
    int val = c - '0';
    if (is_file) {
      for (int i = 0; i < val; ++i) {
        filesystem.push_back(id);
      }
      is_file = false;
      id++;
    } else {
      for (int i = 0; i < val; ++i) {
        filesystem.push_back(-1);
      }
      is_file = true;
    }
  }
  return filesystem;
}
std::uint64_t day9::part1() {
  auto fs = read(file);
  std::ranges::partition(fs, [](const auto &el) { return el > -1; });
  auto count = [id = 0](const auto &el)mutable -> std::int64_t { return (el == -1) ? id = 0 : el * id++; };
  return *std::ranges::fold_left_first(fs | std::views::transform(count), std::plus{});
}
static auto read2(std::ifstream &file) {
  file.clear();
  file.seekg(std::ios::beg);
  std::vector<std::size_t> files;
  for (char c{}; file.get(c);) {
    files.push_back(c - '0');
  }
  return files;
}
std::uint64_t day9::part2() {
  std::uint64_t pos = 0;
  std::int64_t checksum = 0;
  auto disk = read2(file);
  auto free = std::vector<std::priority_queue<std::int64_t, std::vector<std::int64_t>, std::greater<>>>{10};
  //push free spaces onto the heaps
  for (int i = 0; i < disk.size(); ++i) {
    if (i % 2 == 1 && disk[i] > 0) {
      free[disk[i]].push(pos);
    }
    pos += disk[i];
  }

  for (auto [index, block_size] : disk | std::views::enumerate | std::views::reverse) {
    pos -= block_size;
    if (index % 2 == 1) {
      continue;
    }

    auto target_pos = pos;
    auto gap_size = std::numeric_limits<std::size_t>::max();

    //find the first pos that fits
    for (auto [i, heap] : free | std::views::enumerate | std::views::drop(block_size)) {
      if (!heap.empty()) {
        auto first = heap.top();
        if (first < target_pos) {
          target_pos = first;
          gap_size = i;
        }
      }
    }

    // calculate checksum for
    auto id = index / 2; // id of the file
    auto extra = target_pos * block_size + EXTRA[block_size]; // position and length of the file
    checksum += id * extra;

    if (gap_size != std::numeric_limits<std::size_t>::max()) {
      free[gap_size].pop();
      if (block_size < gap_size) {
        free[gap_size - block_size].push(target_pos + block_size);
      }
    }
  }
  return checksum;
}