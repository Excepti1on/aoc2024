#ifndef DAY6_DAY6
#define DAY6_DAY6
#include <fstream>
#include <cstdint>
#include <filesystem>
class day6 {
  public:
    day6(const char* base_dir) : base_dir{base_dir} {}
    std::uint64_t part1();
    std::uint64_t part2();

   private:
    const std::filesystem::path base_dir;
    std::ifstream file{base_dir / "day6" / "input.txt"};
};


#endif /* DAY6_DAY6 */
