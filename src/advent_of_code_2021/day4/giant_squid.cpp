#include "giant_squid.hpp"

#include <algorithm>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/regex.hpp>
#include <iterator>
#include <memory>
#include <sstream> // IWYU pragma: keep
#include <string>
#include <tuple>

int day4_part1(std::string &data) {
  auto [line, boards] = parse_bingo_game(data);
  auto winner_score = calculate_first_winner_score(line, boards);
  return winner_score;
}

int day4_part2(std::string &data) {
  auto [line, boards] = parse_bingo_game(data);
  auto winner_score = calculate_last_winner_score(line, boards);
  return winner_score;
}

int calculate_first_winner_score(BingoLine line,
                                 std::vector<BingoBoard> bingo_boards) {
  std::vector<BingoBordScoreKeeper> bingo_score_kepers;
  for (auto &bingo_board : bingo_boards) {
    bingo_score_kepers.push_back(BingoBordScoreKeeper(bingo_board));
  }

  int winner_score;
  for (auto number : line) {
    for (auto &bingo_score_keper : bingo_score_kepers) {
      bingo_score_keper.mark_number(number);
      if (bingo_score_keper.is_winner()) {
        winner_score = bingo_score_keper.calculate_score();
        return winner_score;
      }
    }
  }
  return 0;
}

int calculate_last_winner_score(BingoLine line,
                                std::vector<BingoBoard> bingo_boards) {
  std::vector<BingoBordScoreKeeper> bingo_score_kepers;
  for (auto &bingo_board : bingo_boards) {
    bingo_score_kepers.push_back(BingoBordScoreKeeper(bingo_board));
  }

  for (auto number : line) {
    for (auto &bingo_score_keper : bingo_score_kepers) {
      bingo_score_keper.mark_number(number);
    }

    if (bingo_score_kepers.size() > 1) {
      bingo_score_kepers.erase(
          std::remove_if(bingo_score_kepers.begin(), bingo_score_kepers.end(),
                         [](BingoBordScoreKeeper bingo_score_keper) -> bool {
                           return bingo_score_keper.is_winner();
                         }),
          bingo_score_kepers.end());
    } else {
      if (bingo_score_kepers[0].is_winner()) {
        return bingo_score_kepers[0].calculate_score();
      }
    }
  }

  return 0;
}

BingoBordScoreKeeper::BingoBordScoreKeeper(BingoBoard bingo_board)
    : bingo_board_(bingo_board) {}

bool BingoBordScoreKeeper::is_winner() { return is_winner_; }

int BingoBordScoreKeeper::calculate_score() {
  if (!is_winner_) {
    return 0;
  }

  int unmarked_sum = 0;
  for (auto &row : bingo_board_) {
    for (auto &bingo_number : row)
      if (!bingo_number.marked) {
        unmarked_sum += bingo_number.number;
      }
  }

  return unmarked_sum * winning_number_;
}

void BingoBordScoreKeeper::update_winner_status(int last_number) {
  if (is_winner_ == true) {
    return;
  } else {
    for (size_t row = 0; row < bingo_board_.size(); row++) {
      if (is_row_compleate(row)) {
        is_winner_ = true;
        winning_number_ = last_number;
        return;
      }
    }
    for (size_t column = 0; column < bingo_board_[0].size(); column++) {
      if (is_column_compleate(column)) {
        is_winner_ = true;
        winning_number_ = last_number;
        return;
      }
    }
  }
}

bool BingoBordScoreKeeper::is_row_compleate(size_t row) {
  for (auto bingo_number : bingo_board_[row]) {
    if (!bingo_number.marked) {
      return false;
    }
  }
  return true;
}

bool BingoBordScoreKeeper::is_column_compleate(size_t column) {
  for (auto row : bingo_board_) {
    if (!row[column].marked) {
      return false;
    }
  }
  return true;
}

void BingoBordScoreKeeper::mark_number(int number) {
  if (is_winner_) {
    return;
  }

  for (auto &row : bingo_board_) {
    for (auto &bingo_number : row)
      if (bingo_number.number == number) {
        bingo_number.marked = true;
        update_winner_status(number);
        return;
      }
  }

  return;
}

BingoBoard parse_bingo_board(std::string input) {
  BingoBoard bingo_board;

  std::string line;
  int number;
  size_t i = 0;
  size_t j = 0;
  std::stringstream ss_input(input);
  while (getline(ss_input, line)) {
    std::stringstream ss_line(line);
    while (ss_line >> number) {
      bingo_board[i][j].number = number;
      j++;
    }
    j = 0;
    i++;
  }
  return bingo_board;
}

std::tuple<BingoLine, std::vector<BingoBoard>>
parse_bingo_game(std::string input) {
  std::stringstream ss_input(input);

  std::string line(std::istreambuf_iterator<char>(ss_input), {});
  std::vector<std::string> tokens;

  auto re = boost::regex("\n\n");
  boost::split_regex(tokens, line, re);

  BingoLine bingo_numbers{};
  std::stringstream ss_bingo_numbers(tokens[0]);
  while (ss_bingo_numbers.good()) {
    std::string substr;
    getline(ss_bingo_numbers, substr, ',');
    bingo_numbers.push_back(std::stoi(substr));
  }
  tokens.erase(tokens.begin());

  std::vector<BingoBoard> bingo_boards{};
  for (auto token : tokens) {
    bingo_boards.push_back(parse_bingo_board(token));
  }

  return {bingo_numbers, bingo_boards};
}
