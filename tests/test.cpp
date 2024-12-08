//
// Created by olive on 06/12/2024.
//
#include <iostream>
#include <cassert>
#include "../day1/day1.h"
#include "../day2/day2.h"
#include "../day3/day3.h"
#include "../day4/day4.h"
#include "../day5/day5.h"
#include "../day6/day6.h"
#include "../day7/day7.h"
#include "../day8/day8.h"
int main(int argc, char** argv) {
  if(argc == 1){
    std::cerr << "missing argument" << std::endl;
    return -1;
  }
  {
    day1 day_1{argv[1]};
    assert(day_1.part1() == 3246517);
    assert(day_1.part2() == 493);
  }
  {
    day2 day_2{argv[1]};
    assert(day_2.part1() == 332);
    assert(day_2.part2() == 398);
  }
  {
    day3 day_3{argv[1]};
    assert(day_3.part1() == 184511516);
    assert(day_3.part2() == 90044227);
  }
  {
    day4 day_4{argv[1]};
    assert(day_4.part1() == 2507);
    assert(day_4.part2() == 1969);
  }
  {
    day5 day_5{argv[1]};
    assert(day_5.part1() == 7307);
    assert(day_5.part2() == 4713);
  }
  {
    day6 day_5{argv[1]};
    assert(day_5.part1() == 5199);
    assert(day_5.part2() == 1915);
  }
  {
    day7 day_5{argv[1]};
    assert(day_5.part1() == 4998764814652);
    assert(day_5.part2() == 37598910447546);
  }
  {
    day8 day_5{argv[1]};
    assert(day_5.part1() == 426);
    assert(day_5.part2() == 1359);
  }
}