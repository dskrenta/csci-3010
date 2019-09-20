#include <iostream>
#include <algorithm>
#include "Maze.h"

/**
    Maze constructor.
*/
Maze::Maze() {
  turn_count_ = 0;
}

/**
    Creates a new maze game.

    @param human The human player.
    @param enemies Number of enemies to start with.
*/
void Maze::NewGame(Player *human, const int enemies) {
  int enemiesToAdd = enemies;
  
  // Add human player
  players_.push_back(human);

  Board *b = new Board(enemiesToAdd);
  board_ = b;

  // Add enemy players
  for (int i = 0; i < enemies; i++) {
    Player * enemy = new Player("enemy" + std::to_string(i), false);
    players_.push_back(enemy);
  }

  // Start the game
  Player * firstPlayer = players_[0];
  TakeTurn(firstPlayer);
}

/**
    Completes one turn given a player.

    @param p The player.
*/
void Maze::TakeTurn(Player *p) {
  std::cout << *board_ << std::endl;

  if (IsGameOver()) {
    std::cout << GenerateReport() << std::endl;
  }
  else {
    std::vector<Position> possibleMoves = board_->GetMoves(p);

    std::cout << p->get_name() << " can move: ";
    for (Position pos: possibleMoves) {
      std::cout << p->ToRelativePosition(pos) << ", ";
    }
    std::cout << std::endl;

    Position chosen_move;
    bool input_is_valid = false;
    while (!input_is_valid) {
      std::string input;
      std::cout << "Enter your desired move: ";
      std::cin >> input;

      for (Position pos: possibleMoves) {
        std::string move_string = p->ToRelativePosition(pos);
        if (StringEqual(input, move_string)) {
          chosen_move = pos;
          input_is_valid = true;
        }
      }
    }

    board_->MovePlayer(p, chosen_move);

    turn_count_++;
    Player * next_player = GetNextPlayer();
    TakeTurn(next_player);
  }
}

/**
    Returns the next player in the turn order.

    @return The next player.
*/
Player * Maze::GetNextPlayer() {
  int next_player_index = turn_count_ % players_.size();
  return players_.at(next_player_index);
}

/**
    Returns boolean based on if the game is still active.

    @return Game status.
*/
bool Maze::IsGameOver() {
  SquareType end = board_->GetExitOccupant();
  bool has_human = board_->HumanOnBoard();

  if (end == SquareType::Human) return true;
  if (!has_human) return true;
  
  return false;
}

/**
    Returns a string report of the game.

    @return String report.
*/
std::string Maze::GenerateReport() {
  std::string report = "";
  
  for (Player * p : players_) {
    report += p->Stringify() + " ";
  }

  return report;
}

/**
    Boolean probability function.

    @param percentage The desired odds.
    @return Boolean value based on if rand value is within odds.
*/
bool Maze::Chance(int percentage) {
  return (rand() % 100) < percentage;
}

/**
    Overloads << for Maze.

    @param os Standard output.
    @param m Maze.
    @return Standard output.
*/
std::ostream& operator<<(std::ostream& os, const Maze &m) {
  os << (*m.board_);
  return os;
} 

/**
    Checks the equality of two given strings ignoring case.

    @param s1 First string.
    @param s2 Second String.
    @return Boolean value based on string equality.
*/
bool Maze::StringEqual(std::string s1, std::string s2) {
   std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0) {
      return true;
   }
   return false;
}