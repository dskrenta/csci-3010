/**
David Skrenta
Homework 1
Player header file
*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>

// Struct to represent position in 2D array
struct Position {
	int row;
	int col;

	bool operator==(const Position & other) {
		return row == other.row && col == other.col;
	}
};

class Player {
	public:
		// Constructor
		Player(const std::string name, const bool is_human): name_(name), is_human_(is_human) {}

		// Returns player name
		std::string get_name() const { return name_; }

		// Returns player points
		int get_points() const { return points_; }

		// Returns player position
		Position get_position() const { return pos_; }

		// Returns boolean based on if player is human
		bool is_human() const { return is_human_; }

		// Given an int, changes player points
		void ChangePoints(const int x);

		// Given a position, changes player position
		void SetPosition(Position pos);

		// Converts a position to a string based relative position
		std::string ToRelativePosition(Position other);
		
		// Converts player to string
		std::string Stringify();

	private:
		std::string name_;
		int points_ = 0;
		Position pos_{row: 0, col: 0};
		bool is_human_;
}; // class Player

#endif  // _PLAYER_H_
