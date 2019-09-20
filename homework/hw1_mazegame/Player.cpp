#include <iostream>
#include "Player.h"

/**
    Changes a player's points.

    @param x Points.
*/
void Player::ChangePoints(const int x) {
  points_ = x;
}

/**
    Changes a player's position.

    @param pos New position.
*/
void Player::SetPosition(Position pos) {
  pos_ = pos;
}

/**
    Returns a string representation of a player.

    @return String representation of player.
*/
std::string Player::Stringify() {
  return "Name: " + name_ + ", Points: " + std::to_string(points_) + ", Position: (" + std::to_string(pos_.row) + ", " + std::to_string(pos_.col) + "), Is Human: " + std::to_string(is_human_);
}

/**
    Returns a textual position relative to the current player.

    @param pos Position to get relative string.
    @return Textual relative position.
*/
std::string Player::ToRelativePosition(Position pos)  {
  if (pos.row == pos_.row) {
    // in the same row
    if (pos.col > pos_.col) return "right";
    else return "left";
  }
  else {
    // in the same col
    if (pos.row > pos_.row) return "right";
    else return "left";
  }
}
