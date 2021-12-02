#ifndef SRC_ADVENT_OF_CODE_2021_DAY2_DIVE_HPP
#define SRC_ADVENT_OF_CODE_2021_DAY2_DIVE_HPP

#include <string>
#include <vector>

int day2_part1(std::vector<std::string> data);
int day2_part2(std::vector<std::string> data);

enum class Direction {
  FORWARD,
  DOWN,
  UP,
};

struct Command {
  Direction direction;
  int count;
};

struct Position {
  int depth;
  int horizontal_position;
};

class Submarine {
public:
  void execute_command(Command command);
  void execute_command_2(Command command);

  Position get_position();

private:
  Position position_{0, 0};
  int aim_;
};

std::vector<Command> parse_commands(std::vector<std::string> commands);
Command parse_command(std::string command);

#endif // SRC_ADVENT_OF_CODE_2021_DAY2_DIVE_HPP
