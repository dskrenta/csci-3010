#include "Maze.h"
#include "Board.h"

/**
    Board constructor

    @param numEnemies Number of enemies to start with
*/
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

/**
    Returns the SquareType of a position

    @param pos Position.
    @return SquareType of passed position.
*/
SquareType Board::get_square_value(Position pos) const {
  return arr_[pos.row][pos.col];
} 

/**
    Sets a square value.

    @param pos Position.
    @param value SquareType
*/
void Board::SetSquareValue(Position pos, SquareType value) {
  arr_[pos.row][pos.col] = value;
}

/**
    Returns boolean based on if given position is valid for a player.

    @param pos Position.
    @return Boolean value.
*/
bool Board::IsValidPosition(Position pos) {
  return pos.row < 0 || 
    pos.col < 0 || 
    pos.row > Board::get_rows() - 1 || 
    pos.col > Board::get_cols() - 1 || 
    Board::get_square_value(pos) == SquareType::Wall;
}

/**
    Returns a vector with the possible moves given a player.

    @param p The player.
    @return Vector of possible moves.
*/
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

/**
    Moves player to new given location

    @param p Player.
    @param pos Position.
    @return Success boolean.
*/
bool Board::MovePlayer(Player *p, Position pos) {
  Position current_pos = p->get_position();
  SquareType next_square = arr_[pos.row][pos.col];

  // Treasure point assignments
  if (next_square == SquareType::TreasureSmall) {
    p->ChangePoints(100);
  } 
  else if (next_square == SquareType::TreasureMedium) {
    p->ChangePoints(500);
  }
  else if (next_square == SquareType::TreasureLarge) {
    p->ChangePoints(1000);
  }

  // Player is human
  if (p->is_human()) {
    // Player is about to move on enemy
    if (next_square == SquareType::Enemy) {
      arr_[pos.row][pos.col] = SquareType::Enemy;
    }
    // Player is about to move on exit
    else if (next_square == SquareType::Exit) {
      std::cout << "You Win!" << std::endl;
    }
    // Player is moving to a regular square
    else {
      arr_[pos.row][pos.col] = SquareType::Human;
      p->SetPosition(pos);
    }
    arr_[current_pos.row][current_pos.col] = SquareType::Empty;
  }
  // Player is enemy
  else {
    arr_[current_pos.row][current_pos.col] = SquareType::Empty;
    arr_[pos.row][pos.col] = SquareType::Enemy;
    p->SetPosition(pos);
  }

  // If player moved, return true
  if (p->get_position() == pos) {
    return true;
  }
  return false;
}

/**
    Returns the SqureType of the exit square.

    @return SquareType of the exit square.
*/
SquareType Board::GetExitOccupant() {
  return SquareType::Exit;
}

/**
    Returns an emoji contained within a string given a SquareType.

    @param value SquareType.
    @return String containing emoji.
*/
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

/**
    Returns boolean based on if board contains a human.

    @return Boolean based on if board contains a human.
*/
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

/**
    Overloads << for Board.

    @param os Standard output.
    @param b Board.
    @return Standard output.
*/
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