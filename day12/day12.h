#ifndef DAY12_DAY12
#define DAY12_DAY12
#include <filesystem>
#include <fstream>
#include <cstdint>
class day12
{
 public:
  day12(const char* base_dir) : base_dir{base_dir} {}
  std::uint64_t part1();
  std::uint64_t part2();

 private:
  const std::filesystem::path base_dir;
  std::ifstream file{base_dir / "day12" / "input.txt"};
};


#endif /* DAY12_DAY12 */
