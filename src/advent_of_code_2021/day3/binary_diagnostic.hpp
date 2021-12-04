#ifndef SRC_ADVENT_OF_CODE_2021_DAY3_BINARY_DIAGNOSTIC_HPP
#define SRC_ADVENT_OF_CODE_2021_DAY3_BINARY_DIAGNOSTIC_HPP

#include <cstddef>
#include <string>
#include <tuple>
#include <vector>

int day3_part1(std::vector<std::string> &data);
int day3_part2(std::vector<std::string> &data);

int calculate_power_consumption(std::vector<std::string> &data);
int calculate_life_support_rating(std::vector<std::string> &data);
int calcualte_gamma_rate(std::vector<std::string> &data);
int calcualte_epsilon_rate(std::vector<std::string> &data);
int calculate_oxygen_generator_rating(std::vector<std::string> &data);
int calculate_co2_scrubber_rating(std::vector<std::string> &data);

std::vector<std::string> transpose(std::vector<std::string> data);
std::tuple<int, int> count_bits(const std::string data);
std::tuple<std::vector<size_t>, std::vector<size_t>>
bit_positions(const std::string &data);
std::vector<std::string> get_subset(std::vector<std::string> data,
                                    std::vector<size_t> subset_indices);

#endif // SRC_ADVENT_OF_CODE_2021_DAY3_BINARY_DIAGNOSTIC_HPP
