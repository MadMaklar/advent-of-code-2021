#include <catch2/catch.hpp>
#include <vector>

#include "sonar_sweep.hpp"

TEST_CASE(
    "The calculated number of increasiong mesurments are correct, part 1") {

  SECTION("Several increasing mesurements") {
    const auto sonar_report =
        std::vector<int>{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

    REQUIRE(part1(sonar_report) == 7);
  }

  SECTION("No increasing mesurements") {
    const auto sonar_report = std::vector<int>{199, 198};

    REQUIRE(part1(sonar_report) == 0);
  }
}

TEST_CASE("Sliding window is correct") {
  const auto data =
      std::vector<int>{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

  auto smoothed = sliding_window(data);

  REQUIRE_THAT(smoothed, Catch::Matchers::Equals(std::vector<int>{
                             607, 618, 618, 617, 647, 716, 769, 792}));
}

TEST_CASE(
    "The calculated number of increasiong mesurments are correct, part 2") {

  SECTION("Several increasing mesurements") {
    const auto sonar_report =
        std::vector<int>{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

    REQUIRE(part2(sonar_report) == 5);
  }
}

