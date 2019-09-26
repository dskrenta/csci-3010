/**
David Skrenta
Homework 1
Maze header file
*/

#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>
#include "Player.h"
#include "Board.h"

class Maze {
  public:
    // Constructor
    Maze();

    // Creates a new game given a human and a number of enemies
    void NewGame(Player *human, const int enemies);

    // Given a player, runs turn
    void TakeTurn(Player *p);

    // Get next turn player
    Player * GetNextPlayer();

    // Boolean function checking game status
    bool IsGameOver();

    // Generates a report of the game
    std::string GenerateReport();
    
    // Overloads << for maze
    friend std::ostream& operator<<(std::ostream& os, const Maze &m);
    
    // Boolean value returned based on a percentage given
    static bool Chance(int percentage);

    // Checks if two passed strings are equal ignoring case
    static bool StringEqual(std::string s1, std::string s2);

  private:
    Board *board_;
    std::vector<Player *> players_;
    int turn_count_;
};  // class Maze

#endif  // _MAZE_H_
