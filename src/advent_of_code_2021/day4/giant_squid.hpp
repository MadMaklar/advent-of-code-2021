#ifndef SRC_ADVENT_OF_CODE_2021_DAY4_GIANT_SQUID_HPP
#define SRC_ADVENT_OF_CODE_2021_DAY4_GIANT_SQUID_HPP

#include <array>
#include <cstddef>
#include <string>
#include <vector>

int day4_part1(std::string &data);
int day4_part2(std::string &data);

struct BingoNumber {
  int number{0};
  bool marked{false};
};
using BingoBoard = std::array<std::array<BingoNumber, 5>, 5>;
using BingoLine = std::vector<int>;

class BingoBordScoreKeeper {
public:
  BingoBordScoreKeeper(BingoBoard bingo_board);

  int calculate_score();
  bool is_winner();
  void mark_number(int number);

private:
  void update_winner_status(int last_number);
  bool is_row_compleate(size_t row);
  bool is_column_compleate(size_t column);

  BingoBoard bingo_board_;
  int winning_number_ = -1;
  bool is_winner_ = false;
};

int calculate_first_winner_score(BingoLine line,
                                 std::vector<BingoBoard> bingo_boards);
int calculate_last_winner_score(BingoLine line,
                                std::vector<BingoBoard> bingo_boards);

BingoBoard parse_bingo_board(std::string input);
std::tuple<BingoLine, std::vector<BingoBoard>>
parse_bingo_game(std::string input);

#endif // SRC_ADVENT_OF_CODE_2021_DAY4_GIANT_SQUID_HPP
