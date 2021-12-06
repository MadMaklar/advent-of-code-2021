#ifndef SRC_ADVENT_OF_CODE_2021_DAY5_HYDROTHERMAL_VENTURE_HPP
#define SRC_ADVENT_OF_CODE_2021_DAY5_HYDROTHERMAL_VENTURE_HPP

#include <map>
#include <string>
#include <vector>

int day5_part1(std::string &data);
int day5_part2(std::string &data);

struct Point {
  int x = 0;
  int y = 0;

  bool operator==(const Point &o) const { return x == o.x && y == o.y; }

  bool operator<(const Point &o) const {
    return x < o.x || (x == o.x && y < o.y);
  }
};

struct Line {
  Point p1;
  Point p2;
};

int calculate_number_of_two_times_overlapping_points(std::vector<Line> lines);
bool is_line_axial(Line line);
std::vector<Point> calculate_line_points(Line line);
std::vector<Point> calculate_overlapping_points(Line l1, Line l2);

std::map<Point, int>
calculate_overlapping_points_count(std::vector<Line> lines);

std::vector<Line> parse_lines(std::string input);

#endif // SRC_ADVENT_OF_CODE_2021_DAY5_HYDROTHERMAL_VENTURE_HPP
