#include <iostream>
#include "Maze.h"

Maze::Maze() {
  
}

void Maze::NewGame(Player *human, const int enemies) {
  int enemiesToAdd = enemies;
  
  players_.push_back(human);

  Board *b = new Board(enemiesToAdd);
  board_ = b;

  // push new enemy players
  for (int i = 0; i < enemies; i++) {
    Player enemy("enemy" + std::to_string(i), false);
    players_.push_back(&enemy);
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

std::ostream& operator<<(std::ostream& os, const Maze &m) {
  os << (*m.board_);
  return os;
} 