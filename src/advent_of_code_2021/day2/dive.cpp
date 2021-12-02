#include "dive.hpp"

#include <algorithm>
#include <iterator>
#include <sstream> // IWYU pragma: keep
#include <string>
#include <unordered_map>
#include <utility>

int day2_part1(std::vector<std::string> data) {
  auto commands = parse_commands(data);
  Submarine submarine{};
  for (auto &command : commands) {
    submarine.execute_command(command);
  }
  auto position = submarine.get_position();
  return position.horizontal_position * position.depth;
}

int day2_part2(std::vector<std::string> data) {
  auto commands = parse_commands(data);
  Submarine submarine{};
  for (auto &command : commands) {
    submarine.execute_command_2(command);
  }
  auto position = submarine.get_position();
  return position.horizontal_position * position.depth;
}

void Submarine::execute_command(Command command) {
  switch (command.direction) {

  case Direction::FORWARD:
    position_.horizontal_position += command.count;
    break;
  case Direction::DOWN:
    position_.depth += command.count;
    break;
  case Direction::UP:
    position_.depth -= command.count;
    break;
  }
}

void Submarine::execute_command_2(Command command) {
  switch (command.direction) {

  case Direction::FORWARD:
    position_.horizontal_position += command.count;
    position_.depth += aim_ * command.count;
    break;
  case Direction::DOWN:
    aim_ += command.count;
    break;
  case Direction::UP:
    aim_ -= command.count;
    break;
  }
}

Position Submarine::get_position() { return position_; }

std::vector<Command> parse_commands(std::vector<std::string> commands) {
  std::vector<Command> parsed_commands{};
  std::transform(commands.begin(), commands.end(),
                 std::back_inserter(parsed_commands), parse_command);
  return parsed_commands;
}

Command parse_command(std::string command) {
  std::istringstream iss(command);
  std::vector<std::string> tokens{};
  copy(std::istream_iterator<std::string>(iss),
       std::istream_iterator<std::string>(), std::back_inserter(tokens));

  static std::unordered_map<std::string, Direction> const table = {
      {"forward", Direction::FORWARD},
      {"down", Direction::DOWN},
      {"up", Direction::UP}};

  Direction direction{};
  auto it = table.find(tokens[0]);
  if (it != table.end()) {
    direction = it->second;
  }

  auto count = std::stoi(tokens[1]);

  return Command{direction, count};
}