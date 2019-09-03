/*
David Skrenta
PE 1
Point implementation file
*/

#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

/*
  Point constructor
*/
Point::Point() {
  x = 0;
  y = 0;
}

/*
  Returns distance from instance point to passed point

  @param point p passed pont.
  @return double distance between .
*/
double Point::distance(Point p) {
  int differenceX = abs(p.x - x);
  int differenceY = abs(p.y - y);

  return sqrt(pow(differenceX, 2) + pow(differenceY, 2));
}

/*
  Translates a point by an increment

    @param int translation translation quantity
    @return void.
*/
void Point::translate(int translation) {
  x += translation;
  y += translation;
}
