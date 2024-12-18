#include <iostream>
#include <print>

#include <chrono>

#include "day1/day1.h"
#include "day10/day10.h"
#include "day11/day11.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"
#include "day7/day7.h"
#include "day8/day8.h"
#include "day9/day9.h"
#include "day12/day12.h"
#include "day13/day13.h"
#include "day14/day14.h"
#include  "day15/day15.h"
#include "day16/day16.h"
int main(int argc, char **argv) {
  if (argc == 1) {
    std::cerr << "please provide the base dir as an argument." << std::endl;
    std::cerr << "e.g. $pwd on windows or linux." << std::endl;
    return -1;
  }
  if (argc == 2) {
    {
      day1 day_1{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_1.part1() << std::endl;
      std::cout << day_1.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day2 day_2{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_2.part1() << std::endl;
      std::cout << day_2.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day3 day_3{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_3.part1() << std::endl;
      std::cout << day_3.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day4 day_4{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_4.part1() << std::endl;
      std::cout << day_4.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day5 day_5{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_5.part1() << std::endl;
      std::cout << day_5.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day6 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day7 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day8 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day9 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day10 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day11 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day12 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day13 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day14 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day15 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    {
      day16 day_6{argv[1]};
      auto val = std::chrono::high_resolution_clock::now();
      std::cout << day_6.part1() << std::endl;
      std::cout << day_6.part2() << std::endl;
      std::cout << std::chrono::high_resolution_clock::now() - val << std::endl;
    }
    return 0;
  }

  for (int i = 2; i < argc; ++i) {
    switch (std::strtol(argv[i], NULL, 0)) {
      case 1: {
        day1 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 2: {
        day2 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 3: {
        day3 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 4: {
        day4 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 5: {
        day5 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 6: {
        day6 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 7: {
        day7 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 8: {
        day8 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 9: {
        day9 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 10: {
        day10 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 11: {
        day11 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
        break;
      }
      case 12: {
        day12 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
      }
      case 13: {
        day13 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
      }
      case 14: {
        day14 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
      }
      case 15: {
        day15 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
      }
      case 16: {
        day16 day_6{argv[1]};
        std::cout << day_6.part1() << std::endl;
        std::cout << day_6.part2() << std::endl;
      }
    }
  }
}
