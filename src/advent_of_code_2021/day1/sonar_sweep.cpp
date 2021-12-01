#include "sonar_sweep.hpp"

#include <algorithm>
#include <numeric>

int part1(const std::vector<int> &sonar_report) {
  auto difference = forward_difference(sonar_report);
  return count_positive(difference);
}

int part2(const std::vector<int> &sonar_report) {
  auto smoothed = sliding_window(sonar_report);
  auto difference = forward_difference(smoothed);
  return count_positive(difference);
}

int count_positive(const std::vector<int> &data) {
  return static_cast<int>(
      std::count_if(data.begin(), data.end(), [](int i) { return i > 0; }));
}

std::vector<int> forward_difference(const std::vector<int> &data) {
  auto difference = data;
  std::adjacent_difference(difference.begin(), difference.end(),
                           difference.begin());
  difference.erase(difference.begin());
  return difference;
}

std::vector<int> sliding_window(const std::vector<int> &data) {
  int window_size{3};
  auto result = std::vector<int>{};

  for (auto it = data.begin(); it != data.end() - window_size + 1; ++it) {
    result.push_back(accumulate(it, it + window_size, 0));
  }

  return result;
}
