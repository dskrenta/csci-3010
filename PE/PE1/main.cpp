/*
David Skrenta
PE 1
Main file
*/

#include <iostream>
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

/*
    Prints point coordinates

    @param point point passed point.
    @return void.
*/
void printPoint(Point point) {
  cout << "x: " << point.x << ", y: " << point.y << endl;
}

int main() {
  // Create points
  Point point1;
  point1.setX(1);
  point1.setY(1);

  Point point2;
  point2.setX(4);
  point2.setY(4);

  Point point3;
  point3.setX(2);
  point3.setY(7);

  // Print point distances
  printPointDistances(point1, point2, point3);

  // Print points
  printPoint(point1);
  printPoint(point2);
  printPoint(point3);

  // Translate point by positive 5
  point1.translate(5);

  // Print point distances
  printPointDistances(point1, point2, point3);

  // Print points
  printPoint(point1);
  printPoint(point2);
  printPoint(point3);

  // Translate point by negative 5
  point1.translate(-5);

  // Print point distances
  printPointDistances(point1, point2, point3);

  // Print points
  printPoint(point1);
  printPoint(point2);
  printPoint(point3);

  return 0;
}
