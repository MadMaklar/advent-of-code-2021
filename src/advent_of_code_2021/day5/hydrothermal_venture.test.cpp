#include <catch2/catch.hpp>
#include <string>

#include <iostream>

#include "hydrothermal_venture.hpp"

TEST_CASE("The number of points where at least two lines overlap is correct") {
  std::string input = {
      R"(0,9 -> 5,9
8,0 -> 0,8
9,4 -> 3,4
2,2 -> 2,1
7,0 -> 7,4
6,4 -> 2,0
0,9 -> 2,9
3,4 -> 1,4
0,0 -> 8,8
5,5 -> 8,2)"};

  auto lines = parse_lines(input);

  SECTION("Only axial lines") {
    std::vector<Line> axial_lines;
    for (auto line : lines) {
      if (is_line_axial(line)) {
        axial_lines.push_back(line);
      }
    }

    auto count = calculate_number_of_two_times_overlapping_points(axial_lines);

    REQUIRE(count == 5);
  }

  SECTION("All lines") {
    auto count = calculate_number_of_two_times_overlapping_points(lines);

    REQUIRE(count == 12);
  }
}
