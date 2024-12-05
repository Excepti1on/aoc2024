#include <print>
#include <iostream>
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
int main() {
  {
    day1 day_1{};
    std::cout << day_1.part1() << std::endl;
    std::cout << day_1.part2() << std::endl;
  }
  {
    day2 day_2{};
    std::cout << day_2.part1() << std::endl;
    std::cout << day_2.part2() << std::endl;
  }
  {
    day3 day_3{};
    std::cout << day_3.part1() << std::endl;
    std::cout << day_3.part2() << std::endl;
  }
  {
    day4 day_4{};
    std::cout << day_4.part1() << std::endl;
    std::cout << day_4.part2() << std::endl;
  }
  {
    day5 day_5{};
    std::cout << day_5.part1() << std::endl;
    std::cout << day_5.part2() << std::endl;
  }
}
