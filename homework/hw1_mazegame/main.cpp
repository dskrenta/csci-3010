#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

int main() {
  // Create player
  Player player("Player1", true); 

  // std::cout << player.Stringify() << std::endl;

  // Create maze
  Maze maze;
  maze.NewGame(&player, 2); 
  // std::cout << maze << std::endl;

  return 0;
}