#include "Board.h"

Board::Board() {

}

SquareType Board::get_square_value(Position pos) const {
  return arr_[pos.row][pos.col];
} 

void Board::SetSquareValue(Position pos, SquareType value) {
  arr_[pos.row][pos.col] = value;
}

bool Board::IsValidPosition(Position pos) {
  return pos.row < 0 || 
    pos.col < 0 || 
    pos.row > Board::get_rows() - 1 || 
    pos.col > Board::get_cols() - 1 || 
    Board::get_square_value(pos) == SquareType::Wall;
}

std::vector<Position> Board::GetMoves(Player *p) {
  Position playerPos = p->get_position();
  std::vector<Position> possibleMoves {
    {row: playerPos.row + 1, col: playerPos.col},
    {row: playerPos.row - 1, col: playerPos.col},
    {row: playerPos.row, col: playerPos.col + 1},
    {row: playerPos.row, col: playerPos.col - 1}
  };

  for (int i = 0; i < possibleMoves.size(); i++) {
    if (Board::IsValidPosition(possibleMoves[i])) {
      possibleMoves.erase(possibleMoves.begin() + i);
    }
  }

  /*
  int up = playerPos.row + 1;
  int down = playerPos.row - 1;
  int right = playerPos.col + 1;
  int left = playerPos.col - 1;

  if (up >= 0 && up <= lastRow && Board::get_square_value({row: up, col: playerPos.col}) != SquareType::Wall) {
    possibleMoves.push_back({row: up, col: playerPos.col});
  }
  else if (down >= 0 && down <= lastRow) {
    possibleMoves.push_back({row: down, col: playerPos.col});
  }
  else if (right >= 0 && right <= lastCol) {
    possibleMoves.push_back({row: playerPos.row, col: right});
  }
  else if (left >= 0 && left <= lastCol) {
    possibleMoves.push_back({row: playerPos.row, col: left});
  }
  */

 /*
  int lastRow = Board::get_rows() - 1;
  int lastCol = Board::get_cols() - 1;

 possibleMoves[i].row < 0 || 
      possibleMoves[i].col < 0 || 
      possibleMoves[i].row > lastRow || 
      possibleMoves[i].col > lastCol || 
      Board::get_square_value(possibleMoves[i]) == SquareType::Wall
 */

  return possibleMoves;
}

bool Board::MovePlayer(Player *p, Position pos) {
  if (Board::IsValidPosition(pos)) {
    p->SetPosition(pos);
    return true;
  }

  return false;
}

SquareType Board::GetExitOccupant() {
  return SquareType::Exit;
}