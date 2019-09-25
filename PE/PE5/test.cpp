#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

Point p1 = {
  x: 1,
  y: 1
};
Point p2 = {
  x: 2,
  y: 2
};
Rectangle r(p1, p2);
Rectangle r2(p1, p2);

/*
TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
}
*/

TEST_CASE("Rectangle class constructor", "[rectangle]") {
  REQUIRE((r.get_p1().x == p1.x && r.get_p1().y == p1.y));
  REQUIRE((r.get_p2().x == p2.x && r.get_p2().y == p2.y));
}

TEST_CASE("Rectange width", "[rectangle]") {
  REQUIRE(r.GetWidth() == p2.x - p1.x);
}

TEST_CASE("Rectange height", "[rectangle]") {
  REQUIRE(r.GetHeight() == p2.y - p1.y);
}

TEST_CASE("Rectangle overlap", "[rectangle]") {
  REQUIRE(r.Overlaps(r2) == true);
}

TEST_CASE("Rectangle area", "[rectangle]") {
  REQUIRE(r.CalculateArea() == (p2.x - p1.x) * (p2.y - p1.y));
}

TEST_CASE("Expand rectangle", "[rectangle]") {
  r.Expand();

  REQUIRE((r.get_p1().x == p1.x - 1 && r.get_p1().y == p1.y - 1));
  REQUIRE((r.get_p2().x == p2.x + 1 && r.get_p2().y == p2.y + 1));
}

TEST_CASE("Shrink rectangle", "[rectangle]") {
  r.Shrink();

  REQUIRE((r.get_p1().x == p1.x + 1 && r.get_p1().y == p1.y + 1));
  REQUIRE((r.get_p2().x == p2.x - 1 && r.get_p2().y == p2.y - 1));
}