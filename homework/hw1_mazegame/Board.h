/**
David Skrenta
Homework 1
Board header file
*/

#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include "Player.h"

// Enumeration for types of squares
enum class SquareType { 
	Wall, 
	Exit, 
	Empty, 
	Human, 
	Enemy, 
	TreasureSmall, 
	TreasureMedium, 
	TreasureLarge 
};

class Board {
	public:
		// Constructor
		Board(int numEnemies);

		// Returns rows
		int get_rows() const { return 4; }
		
		// Returns cols
		int get_cols() const { return 4; }

		// Get SquareType from 2D position
		SquareType get_square_value(Position pos) const;

		// Set square value given a 2D position and a SquareType value
		void SetSquareValue(Position pos, SquareType value);

		// Boolean value is returned based on passed position being a valid position for a player to move to 
		bool IsValidPosition(Position pos);

		// Returns a vector of moves given a player
		std::vector<Position> GetMoves(Player *p);

		// Given a player and a position this function moves the player 
		bool MovePlayer(Player *p, Position pos);

		// Boolean based on if there is a human on the board
		bool HumanOnBoard();

		// Returns SquareType of the exit square
		SquareType GetExitOccupant();

		// Returns an emoji contained in a string given a SquareType
		static std::string SquareTypeToEmoji(SquareType value);

		// Overloads << for Board
		friend std::ostream& operator<<(std::ostream& os, const Board &b);

	private:
		SquareType arr_[4][4];
}; // class Board

#endif  // _BOARD_H_

