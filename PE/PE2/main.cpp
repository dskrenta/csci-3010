/*
David Skrenta
PE 1
Main file
*/

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

/*
    Prints distance between 3 passed points

    @param point p1, point p2, point p3 three points.
    @return void.
*/
void printPointDistances(Point p1, Point p2, Point p3) {
  cout << "Distance between Point1 and Point2: " << p1.distance(p2) << endl;
  cout << "Distance between Point2 and Point3: " << p2.distance(p3) << endl;
  cout << "Distance between Point3 and Point1: " << p3.distance(p1) << endl;
}

int main() {
  // Create points
  Point point1({1, 2, 3});
  Point point2({4, 5, 6});
  Point point3({});

  // Distance between point1 and point2
  std::cout << point1.distance(point2) << std::endl;

  // Distance between point1 and point3
  std::cout << point1.distance(point3) << std::endl;

  // Translate point1 positive 1
  point1.translate(1);

  // Distance between point1 and point2
  std::cout << point1.distance(point2) << std::endl;

  // Translate point1 negative 1
  point1.translate(-1);

  // Distance between point1 and point2
  std::cout << point1.distance(point2) << std::endl;

  // Translate point with no defined values
  point3.translate(1);

  return 0;
}
