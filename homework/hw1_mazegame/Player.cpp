#include <iostream>
#include "Player.h"

void Player::ChangePoints(const int x) {
  points_ = x;
}

void Player::SetPosition(Position pos) {
  pos_ = pos;
}

std::string Player::Stringify() {
  std::cout << "Name: " << name_ << ", Points: " << points_ << ", Position: " << pos_ << ", Is Human: " << is_human_ << std::endl;
}
