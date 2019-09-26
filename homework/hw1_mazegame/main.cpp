/**
David Skrenta
Homework 1
main.cpp file
*/

#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

int main() {
  // Creates a player
  Player player("Player1", true); 

  // Creates a maze
  Maze maze;
  maze.NewGame(&player, 2); 

  return 0;
}