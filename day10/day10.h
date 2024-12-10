#ifndef DAY10_DAY10
#define DAY10_DAY10
#include <filesystem>
#include <fstream>
#include <cstdint>
class day10
{
 public:
  day10(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day10" / "input.txt"};
};


#endif /* DAY10_DAY10 */
