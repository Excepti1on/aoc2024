#include <print>
#include <iostream>
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"
#include "day7/day7.h"
#include "day8/day8.h"
#include "day9/day9.h"
#include "day10/day10.h"
int main(int argc, char **argv) {
  if (argc == 1) {
    std::cerr << "please provide the base dir as an argument." << std::endl;
    std::cerr << "e.g. $pwd on windows or linux." << std::endl;
  }
  {
    day1 day_1{argv[1]};
    std::cout << day_1.part1() << std::endl;
    std::cout << day_1.part2() << std::endl;
  }
  {
    day2 day_2{argv[1]};
    std::cout << day_2.part1() << std::endl;
    std::cout << day_2.part2() << std::endl;
  }
  {
    day3 day_3{argv[1]};
    std::cout << day_3.part1() << std::endl;
    std::cout << day_3.part2() << std::endl;
  }
  {
    day4 day_4{argv[1]};
    std::cout << day_4.part1() << std::endl;
    std::cout << day_4.part2() << std::endl;
  }
  {
    day5 day_5{argv[1]};
    std::cout << day_5.part1() << std::endl;
    std::cout << day_5.part2() << std::endl;
  }
  {
    day6 day_6{argv[1]};
    //std::cout << day_6.part1() << std::endl;
    //std::cout << day_6.part2() << std::endl;
  }
  {
    day7 day_6{argv[1]};
    std::cout << day_6.part1() << std::endl;
    std::cout << day_6.part2() << std::endl;
  }
  {
    day8 day_6{argv[1]};
    std::cout << day_6.part1() << std::endl;
    std::cout << day_6.part2() << std::endl;
  }
  {
    day9 day_6{argv[1]};
    std::cout << day_6.part1() << std::endl;
    std::cout << day_6.part2() << std::endl;
  }
  {
    day10 day_6{argv[1]};
    std::cout << day_6.part1() << std::endl;
    std::cout << day_6.part2() << std::endl;
  }
}

