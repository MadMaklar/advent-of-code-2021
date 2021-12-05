#include <advent_of_code_2021/day1/sonar_sweep.hpp>
#include <advent_of_code_2021/day2/dive.hpp>
#include <advent_of_code_2021/day3/binary_diagnostic.hpp>
#include <advent_of_code_2021/day4/giant_squid.hpp>
#include <algorithm>
#include <fstream> // IWYU pragma: keep
#include <iostream>
#include <iterator>
#include <sstream> // IWYU pragma: keep
#include <string>
#include <vector>

std::string read_input(std::string path) {
  std::ifstream file(path);
  std::stringstream buffer;

  if (file) {
    buffer << file.rdbuf();
  }

  return buffer.str();
}

int main() {
  std::ifstream data_file("/home/daniel/git/advent-of-code-2020/data/day1.txt");
  std::istream_iterator<int> start(data_file), end;
  std::vector<int> data(start, end);

  std::cout << "Answer day 1, part 1: " << part1(data) << '\n';
  std::cout << "Answer day 1, part 2: " << part2(data) << '\n';

  std::ifstream day2_data_file(
      "/home/daniel/git/advent-of-code-2020/data/day2.txt");
  std::vector<std::string> day2_data;
  std::string line;
  while (std::getline(day2_data_file, line)) {
    day2_data.push_back(line);
  }

  std::cout << "Answer day 2, part 1: " << day2_part1(day2_data) << '\n';
  std::cout << "Answer day 2, part 2: " << day2_part2(day2_data) << '\n';

  std::ifstream day3_data_file(
      "/home/daniel/git/advent-of-code-2020/data/day3.txt");
  std::vector<std::string> day3_data;
  while (std::getline(day3_data_file, line)) {
    day3_data.push_back(line);
  }

  std::cout << "Answer day 3, part 1: " << day3_part1(day3_data) << '\n';
  std::cout << "Answer day 3, part 2: " << day3_part2(day3_data) << '\n';

  auto input = read_input("/home/daniel/git/advent-of-code-2020/data/day4.txt");
  std::cout << "Answer day 4, part 1: " << day4_part1(input) << '\n';
  std::cout << "Answer day 4, part 1: " << day4_part2(input) << '\n';
}