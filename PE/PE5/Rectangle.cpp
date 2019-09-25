/*
Original bugs: Shrink rectangle does not properly modify point1 coordinates
*/

#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2) {
  p1_ = p1;
  p2_ = p2;
}

int Rectangle::GetWidth() {
  return p2_.x - p1_.x;
}

int Rectangle::GetHeight() {
  return p2_.y - p1_.y;
} 

bool Rectangle::Overlaps(Rectangle& other) {
  if (p1_.x < other.get_p2().x && p2_.x > other.get_p1().x && p1_.y > other.get_p2().y && p2_.y < other.get_p1().y) {
    return true;
  }

  return false;
}

int Rectangle::CalculateArea() {
  return Rectangle::GetWidth() * Rectangle::GetHeight();
}

void Rectangle::Expand() {
  p1_ = { x: p1_.x - 1, y: p1_.y - 1 };
  p2_ = { x: p2_.x + 1, y: p2_.y + 1 };
}

void Rectangle::Shrink() {
  p1_ = { x: p1_.x + 1, y: p1_.y + 1 };
  p2_ = { x: p2_.x - 1, y: p2_.y - 1 };
}