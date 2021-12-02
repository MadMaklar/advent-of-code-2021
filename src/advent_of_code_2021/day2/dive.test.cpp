#include <catch2/catch.hpp>
#include <string>
#include <vector>

#include "dive.hpp"

// forward 5 down 5 forward 8 up 3 down 8 forward 2
//
//     horisontal,
//     x 15
//
//     vertical,
//     y 10
//
//     product,
//     150

TEST_CASE("The submarine final position is correct, part 1") {
  std::vector<Command> commands{
      {Direction::FORWARD, 5}, {Direction::DOWN, 5}, {Direction::FORWARD, 8},
      {Direction::UP, 3},      {Direction::DOWN, 8}, {Direction::FORWARD, 2}};

  Submarine submarine{};
  for (auto &command : commands) {
    submarine.execute_command(command);
  }

  REQUIRE(submarine.get_position().horizontal_position == 15);
  REQUIRE(submarine.get_position().depth == 10);
}

TEST_CASE("The submarine final position is correct, part 2") {
  std::vector<Command> commands{
      {Direction::FORWARD, 5}, {Direction::DOWN, 5}, {Direction::FORWARD, 8},
      {Direction::UP, 3},      {Direction::DOWN, 8}, {Direction::FORWARD, 2}};

  Submarine submarine{};
  for (auto &command : commands) {
    submarine.execute_command_2(command);
  }

  REQUIRE(submarine.get_position().horizontal_position == 15);
  REQUIRE(submarine.get_position().depth == 60);
}

TEST_CASE("Parse command is correct") {
  SECTION("Forward command is parsed correct") {
    std::string command{"forward 5"};

    auto parsed_command = parse_command(command);

    REQUIRE(parsed_command.direction == Direction::FORWARD);
    REQUIRE(parsed_command.count == 5);
  }

  SECTION("Down command is parsed correct") {
    std::string command{"down 2"};

    auto parsed_command = parse_command(command);

    REQUIRE(parsed_command.direction == Direction::DOWN);
    REQUIRE(parsed_command.count == 2);
  }

  SECTION("Up command is parsed correct") {
    std::string command{"up 1"};

    auto parsed_command = parse_command(command);

    REQUIRE(parsed_command.direction == Direction::UP);
    REQUIRE(parsed_command.count == 1);
  }
}