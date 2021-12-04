#include "binary_diagnostic.hpp"

#include <algorithm>
#include <memory>
#include <sstream> // IWYU pragma: keep
#include <string>
#include <tuple>

int day3_part1(std::vector<std::string> &data) {
  auto transposed_data = transpose(data);
  return calculate_power_consumption(transposed_data);
}

int day3_part2(std::vector<std::string> &data) {
  auto transposed_data = transpose(data);
  return calculate_life_support_rating(transposed_data);
}

int calculate_power_consumption(std::vector<std::string> &data) {
  auto gamma_rate = calcualte_gamma_rate(data);
  auto epsilon_rate = calcualte_epsilon_rate(data);
  return gamma_rate * epsilon_rate;
}

int calculate_life_support_rating(std::vector<std::string> &data) {
  auto oxygen_generator_rating = calculate_oxygen_generator_rating(data);
  auto co2_scrubber_rating = calculate_co2_scrubber_rating(data);
  return oxygen_generator_rating * co2_scrubber_rating;
}

int calcualte_gamma_rate(std::vector<std::string> &data) {
  int gamma_rate{0};
  for (std::string::size_type i = 0; i < data.size(); i++) {
    auto [count_ones, count_zeros] = count_bits(data[i]);
    if (count_ones > count_zeros) {
      gamma_rate += 1 << (data.size() - i - 1);
    }
  }
  return gamma_rate;
}

int calcualte_epsilon_rate(std::vector<std::string> &data) {
  int epsilon_rate{0};
  for (std::string::size_type i = 0; i < data.size(); i++) {
    auto [count_ones, count_zeros] = count_bits(data[i]);
    if (count_ones < count_zeros) {
      epsilon_rate += 1 << (data.size() - i - 1);
    }
  }
  return epsilon_rate;
}

int calculate_oxygen_generator_rating(std::vector<std::string> &data) {
  std::vector<std::string> sub_data = data;
  for (std::string::size_type i = 0; i < sub_data.size(); i++) {
    if (sub_data[i].size() == 1) {
      break;
    }
    auto [count_ones, count_zeros] = count_bits(sub_data[i]);
    auto [position_ones, position_zeros] = bit_positions(sub_data[i]);
    if (count_ones >= count_zeros) {
      sub_data = transpose(get_subset(transpose(sub_data), position_ones));
    } else {
      sub_data = transpose(get_subset(transpose(sub_data), position_zeros));
    }
  }
  return std::stoi(transpose(sub_data)[0], 0, 2);
}

int calculate_co2_scrubber_rating(std::vector<std::string> &data) {
  std::vector<std::string> sub_data = data;
  for (std::string::size_type i = 0; i < sub_data.size(); i++) {
    if (sub_data[i].size() == 1) {
      break;
    }
    auto [count_ones, count_zeros] = count_bits(sub_data[i]);
    auto [position_ones, position_zeros] = bit_positions(sub_data[i]);
    if (count_ones < count_zeros) {
      sub_data = transpose(get_subset(transpose(sub_data), position_ones));
    } else {
      sub_data = transpose(get_subset(transpose(sub_data), position_zeros));
    }
  }
  return std::stoi(transpose(sub_data)[0], 0, 2);
}

std::vector<std::string> transpose(std::vector<std::string> data) {
  std::vector<std::string> transposed_data(data[0].length());
  for (auto line : data) {
    for (std::string::size_type i = 0; i < line.size(); i++) {
      transposed_data[i].insert(transposed_data[i].end(), line.at(i));
    }
  }
  return transposed_data;
}

std::tuple<int, int> count_bits(const std::string data) {
  int count_ones{0};
  int count_zeros{0};

  for (char const &c : data) {
    if (c == '1') {
      count_ones++;
    } else {
      count_zeros++;
    }
  }

  return {count_ones, count_zeros};
}

std::tuple<std::vector<size_t>, std::vector<size_t>>
bit_positions(const std::string &data) {
  size_t bit_position{0};
  std::vector<size_t> ones_position{};
  std::vector<size_t> zeros_position{};
  for (char const &c : data) {
    if (c == '1') {
      ones_position.push_back(bit_position);
    } else {
      zeros_position.push_back(bit_position);
    }
    bit_position++;
  }

  return {ones_position, zeros_position};
}

std::vector<std::string> get_subset(std::vector<std::string> data,
                                    std::vector<size_t> subset_indices) {
  std::vector<std::string> subset{};
  for (auto index : subset_indices) {
    subset.push_back(data[index]);
  }
  return subset;
}