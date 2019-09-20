#include "Maze.h"
#include "Board.h"

Board::Board(int numEnemies) {
  for (int row = 0; row < Board::get_rows(); row++) {
    for (int col = 0; col < Board::get_cols(); col++) {
      if (row == 0 && col == 0) {
        arr_[row][col] = SquareType::Human;
      }
      else if (row == 3 && col == 3) {
        arr_[row][col] = SquareType::Exit;
      }
      else if (Maze::Chance(20)) {
        arr_[row][col] = SquareType::Wall;
      }
      else if (Maze::Chance(10)) {
        arr_[row][col] = SquareType::TreasureSmall;
      }
      else if (Maze::Chance(7)) {
        arr_[row][col] = SquareType::TreasureMedium;
      }
      else if (Maze::Chance(5)) {
        arr_[row][col] = SquareType::TreasureLarge;
      }
      else if (numEnemies > 0) {
        arr_[row][col] = SquareType::Enemy;
        numEnemies--;
      }
      else {
       arr_[row][col] = SquareType::Empty;
      }
    }
  }
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

  return possibleMoves;
}

bool Board::MovePlayer(Player *p, Position pos) {
  Position current_pos = p->get_position();
  SquareType next_square = arr_[pos.row][pos.col];

  if (next_square == SquareType::TreasureSmall) {
    p->ChangePoints(100);
  } 
  else if (next_square == SquareType::TreasureMedium) {
    p->ChangePoints(500);
  }
  else if (next_square == SquareType::TreasureLarge) {
    p->ChangePoints(1000);
  }

  if (p->is_human()) {
    if (next_square == SquareType::Enemy) {
      arr_[pos.row][pos.col] = SquareType::Enemy;
    }
    else if (next_square == SquareType::Exit) {
      std::cout << "You Win!" << std::endl;
    }
    else {
      arr_[pos.row][pos.col] = SquareType::Human;
      p->SetPosition(pos);
    }
    arr_[current_pos.row][current_pos.col] = SquareType::Empty;
  }
  else {
    arr_[current_pos.row][current_pos.col] = SquareType::Empty;
    arr_[pos.row][pos.col] = SquareType::Enemy;
    p->SetPosition(pos);
  }

  if (p->get_position() == pos) {
    return true;
  }
  return false;
}

SquareType Board::GetExitOccupant() {
  return SquareType::Exit;
}

std::string Board::SquareTypeToEmoji(SquareType value) {
  if (value == SquareType::Wall) {
    return "🧱";
  }
  else if (value == SquareType::Exit) {
    return "❎";
  }
  else if (value == SquareType::Human) {
    return "😀";
  }
  else if (value == SquareType::Enemy) {
    return "💣";
  }
  else if (value == SquareType::TreasureSmall) {
    return "🌟";
  }
  else if (value == SquareType::TreasureMedium) {
    return "🔥";
  }
  else if (value == SquareType::TreasureLarge) {
    return "🍅";
  }
  else {
    return "⬜";
  }
}

bool Board::HumanOnBoard() {
  for (int row = 0; row < get_rows(); row++) {
    for (int col = 0; col < get_cols(); col++) {
      if (arr_[row][col] == SquareType::Human) {
        return true;
      }
    }
  }

  return false;
}

std::ostream& operator<<(std::ostream& os, const Board &b) {
  os << std::endl;
  for (int row = 0; row < b.get_rows(); row++) {
    for (int col = 0; col < b.get_cols(); col++) {
      os << Board::SquareTypeToEmoji(b.arr_[row][col]) << " ";
    }
    os << std::endl;
  }
  return os;
} 