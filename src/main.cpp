#include <advent_of_code_2021/day1/sonar_sweep.hpp>

#include <algorithm>
#include <filesystem>
#include <fstream> // IWYU pragma: keep
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::filesystem::path data_path =
      "/home/daniel/git/advent-of-code-2020/data/day1.txt";
  std::ifstream data_file(data_path);
  std::istream_iterator<int> start(data_file), end;
  std::vector<int> data(start, end);

  std::cout << "Answer day 1, part 1: " << part1(data) << '\n';
  std::cout << "Answer day 1, part 2: " << part2(data) << '\n';
}