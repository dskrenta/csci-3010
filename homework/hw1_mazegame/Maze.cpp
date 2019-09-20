#include <iostream>
#include "Maze.h"

Maze::Maze() {
  
}

void Maze::NewGame(Player *human, const int enemies) {
  int enemiesToAdd = enemies;
  
  players_.push_back(human);

  // push new enemy players
  for (int i = 0; i < enemies; i++) {
    Player enemy("enemy" + std::to_string(i), false);
    players_.push_back(&enemy);
  }

  for (int row = 0; row < board_->get_rows(); row++) {
    for (int col = 0; col < board_->get_cols(); col++) {
      if (row == 0 && col == 0) {
        board_->SetSquareValue({row, col}, SquareType::Human);
      }
      else if (row == 3 && col == 3) {
        board_->SetSquareValue({row, col}, SquareType::Exit);
      }
      else if (Maze::Chance(20)) {
        board_->SetSquareValue({row, col}, SquareType::Wall);
      }
      else if (Maze::Chance(10)) {
        board_->SetSquareValue({row, col}, SquareType::Treasure);
      }
      else if (enemiesToAdd > 0) {
        board_->SetSquareValue({row, col}, SquareType::Enemy);
        enemiesToAdd--;
      }
    }
  }
}

void Maze::TakeTurn(Player *p) {

}

Player * Maze::GetNextPlayer() {
  return players_[0];
}

bool Maze::IsGameOver() {
  return 0;
}

std::string Maze::GenerateReport() {
  return "Some stuff";
}

bool Maze::Chance(int percentage) {
  return (rand() % 100) < percentage;
}