#ifndef SRC_ADVENT_OF_CODE_2021_DAY1_SONAR_SWEEP_HPP
#define SRC_ADVENT_OF_CODE_2021_DAY1_SONAR_SWEEP_HPP

#include <vector>

int part1(const std::vector<int> &sonar_report);

int part2(const std::vector<int> &sonar_report);

int count_positive(const std::vector<int> &data);

std::vector<int> forward_difference(const std::vector<int> &data);

std::vector<int> sliding_window(const std::vector<int> &data);


#endif // SRC_ADVENT_OF_CODE_2021_DAY1_SONAR_SWEEP_HPP
