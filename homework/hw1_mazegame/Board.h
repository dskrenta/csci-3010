#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include "Player.h"

// you may change this enum as you need
enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure };

// TODO: implement
std::string SquareTypeStringify(SquareType sq);

class Board {
public:
	// TODO: implement
	Board(int numEnemies);

	// already implemented in line
	int get_rows() const { return 4; }  // you should be able to change the size of your
	int get_cols() const { return 4; }  // board by changing these numbers and the numbers in the arr_ field

//	// TODO: you MUST implement the following functions
	SquareType get_square_value(Position pos) const;
//
//	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value);
//
	// void PopulateCells(int numEnemies);

	bool IsValidPosition(Position pos);
//	// get the possible Positions that a Player could move to
//	// (not off the board or into a wall)
	std::vector<Position> GetMoves(Player *p);
//
//	// Move a player to a new position on the board. Return
//	// true if they moved successfully, false otherwise.
	bool MovePlayer(Player *p, Position pos);
//
	bool HumanOnBoard();
//	// Get the square type of the exit square
	SquareType GetExitOccupant();
//
	static std::string SquareTypeToEmoji(SquareType value);
//	// You probably want to implement this
	friend std::ostream& operator<<(std::ostream& os, const Board &b);

private:
	SquareType arr_[4][4];

	int rows_; // might be convenient but not necessary
	int cols_;

	// you may add more fields, as needed
}; // class Board

#endif  // _BOARD_H_

