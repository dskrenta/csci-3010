#include <iostream>
#include "Player.h"

void Player::ChangePoints(const int x) {
  points_ = x;
}

void Player::SetPosition(Position pos) {
  pos_ = pos;
}

std::string Player::Stringify() {
  return "Name: " + name_ + ", Points: " + std::to_string(points_) + ", Position: (" + std::to_string(pos_.row) + ", " + std::to_string(pos_.col) + "), Is Human: " + std::to_string(is_human_);
}
