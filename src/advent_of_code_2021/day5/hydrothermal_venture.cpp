#include "hydrothermal_venture.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/regex.hpp>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int day5_part1(std::string &data) {
  auto lines = parse_lines(data);

  std::vector<Line> axial_lines;
  for (auto line : lines) {
    if (is_line_axial(line)) {
      axial_lines.push_back(line);
    }
  }

  auto count = calculate_number_of_two_times_overlapping_points(axial_lines);
  return count;
}

int day5_part2(std::string &data) {
  auto lines = parse_lines(data);

  auto count = calculate_number_of_two_times_overlapping_points(lines);
  return count;
}

int calculate_number_of_two_times_overlapping_points(std::vector<Line> lines) {
  auto overlapping_points_count = calculate_overlapping_points_count(lines);

  int number_of_two_times_overlapping_points = 0;

  for (auto overlap_count : overlapping_points_count) {
    if (overlap_count.second >= 2) {
      number_of_two_times_overlapping_points++;
    }
  }

  return number_of_two_times_overlapping_points;
}

std::map<Point, int>
calculate_overlapping_points_count(std::vector<Line> lines) {
  std::map<Point, int> overlapping_points_count;

  for (auto it = lines.begin(); it != lines.end(); ++it) {
    for (auto it2 = it; it2 != lines.end(); ++it2) {
      auto overlapping_points = calculate_overlapping_points(*it, *it2);

      // std::vector<Point> overlapping_points_sorted{overlapping_points};
      // sort(begin(overlapping_points_sorted), end(overlapping_points_sorted));

      // auto beg = begin(overlapping_points_sorted) + 1;
      // for (; beg != end(overlapping_points_sorted); ++beg) {
      //   if (*beg == *(beg - 1)) {
      //     overlapping_points_count[*beg]++;
      //   }
      // }

      for (auto point : overlapping_points) {

        if (overlapping_points_count.find(point) ==
            overlapping_points_count.end()) {
          overlapping_points_count.insert(overlapping_points_count.end(),
                                          {point, 1});
        } else {
          overlapping_points_count[point]++;
        }
      }
    }
  }

  return overlapping_points_count;
}

std::vector<Point> calculate_overlapping_points(Line l1, Line l2) {
  auto l1_points = calculate_line_points(l1);
  auto l2_points = calculate_line_points(l2);

  std::vector<Point> overlapping_points;

  for (auto l1_point : l1_points) {
    for (auto l2_point : l2_points) {
      if (l1_point == l2_point) {
        overlapping_points.push_back(l1_point);
      }
    }
  }

  return overlapping_points;
}

std::vector<Point> calculate_line_points(Line line) {
  std::vector<Point> line_points;

  if (line.p1.x == line.p2.x) {
    for (auto y = std::min(line.p1.y, line.p2.y);
         y <= std::max(line.p1.y, line.p2.y); y++) {
      line_points.push_back({line.p1.x, y});
    }
  } else if (line.p1.y == line.p2.y) {
    for (auto x = std::min(line.p1.x, line.p2.x);
         x <= std::max(line.p1.x, line.p2.x); x++) {
      line_points.push_back({x, line.p1.y});
    }
  } else if (line.p1.x < line.p2.x && line.p1.y < line.p2.y) {
    int x = line.p1.x;
    for (auto y = line.p1.y; y <= line.p2.y; y++) {
      line_points.push_back({x, y});
      x++;
    }
  } else if (line.p1.x < line.p2.x && line.p1.y > line.p2.y) {
    int x = line.p1.x;
    for (auto y = line.p1.y; y >= line.p2.y; y--) {
      line_points.push_back({x, y});
      x++;
    }
  } else if (line.p1.x > line.p2.x && line.p1.y < line.p2.y) {
    int x = line.p1.x;
    for (auto y = line.p1.y; y <= line.p2.y; y++) {
      line_points.push_back({x, y});
      x--;
    }
  } else {
    int x = line.p1.x;
    for (auto y = line.p1.y; y >= line.p2.y; y--) {
      line_points.push_back({x, y});
      x--;
    }
  }

  return line_points;
}

bool is_line_axial(Line line) {
  return line.p1.x == line.p2.x || line.p1.y == line.p2.y;
}

std::vector<Line> parse_lines(std::string input) {
  std::stringstream ss_input(input);
  std::string s_line;
  std::vector<Line> lines;

  while (std::getline(ss_input, s_line)) {
    std::vector<std::string> s_points;
    auto re = boost::regex(" -> ");
    boost::split_regex(s_points, s_line, re);
    std::vector<int> coordinates;

    for (auto s_point : s_points) {
      std::vector<std::string> s_coordinates;
      boost::split(s_coordinates, s_point, boost::is_any_of(","));

      for (auto s_coordinate : s_coordinates) {
        coordinates.push_back(std::stoi(s_coordinate));
      }
    }

    lines.push_back(
        {{coordinates[0], coordinates[1]}, {coordinates[2], coordinates[3]}});
  }

  return lines;
}
