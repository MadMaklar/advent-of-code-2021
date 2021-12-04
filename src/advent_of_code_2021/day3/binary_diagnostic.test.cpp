#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <vector>

#include "binary_diagnostic.hpp"

TEST_CASE("Calculated gamma and epsilon rate is correct") {

  std::vector<std::string> data{"00100", "11110", "10110", "10111",
                                "10101", "01111", "00111", "11100",
                                "10000", "11001", "00010", "01010"};

  auto transposed_data = transpose(data);
  SECTION("Power consumption is correct") {
    auto power_consumption = calculate_power_consumption(transposed_data);

    REQUIRE(power_consumption == 198);
  }

  SECTION("Gamma rate is correct") {
    auto calculated_gamma_rate = calcualte_gamma_rate(transposed_data);

    REQUIRE(calculated_gamma_rate == 22);
  }

  SECTION("Epsilon rate is correct") {
    auto calculated_gamma_rate = calcualte_epsilon_rate(transposed_data);

    REQUIRE(calculated_gamma_rate == 9);
  }

  SECTION("Life support rating is correct") {
    auto life_support_rating = calculate_life_support_rating(transposed_data);

    REQUIRE(life_support_rating == 230);
  }

  SECTION("Oxygen generator rating is correct") {
    auto calculated_oxygen_generator_rating =
        calculate_oxygen_generator_rating(transposed_data);

    REQUIRE(calculated_oxygen_generator_rating == 23);
  }

  SECTION("CO2 scrubber rating is correct") {
    auto calculated_co2_scrubber_rating =
        calculate_co2_scrubber_rating(transposed_data);

    REQUIRE(calculated_co2_scrubber_rating == 10);
  }
}

TEST_CASE("Transposed data is correct") {
  std::vector<std::string> data{"1000110101011", "1001110101010"};
  std::vector<std::string> expected{"11", "00", "00", "01", "11", "11", "00",
                                    "11", "00", "11", "00", "11", "10"};
  REQUIRE(transpose(data) == expected);
}

TEST_CASE("Counted number of bits is correct") {
  std::string data = "1001110101010000";
  auto [count_ones, count_zeros] = count_bits(data);
  REQUIRE(count_ones == 7);
  REQUIRE(count_zeros == 9);
}

TEST_CASE("Bit positions are correct") {
  std::string data = "100111010";
  auto [positions_ones, positions_zeros] = bit_positions(data);
  REQUIRE(positions_ones == std::vector<size_t>{0, 3, 4, 5, 7});
  REQUIRE(positions_zeros == std::vector<size_t>{1, 2, 6, 8});
}