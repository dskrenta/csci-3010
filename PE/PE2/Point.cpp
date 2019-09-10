/*
David Skrenta
PE 1
Point implementation file
*/

#include <iostream>
#include <math.h>
#include <vector>
#include "Point.h"

/*
  Point constructor
*/
Point::Point(std::vector<int> initialCoordinates) {
  for (int i = 0; i < initialCoordinates.size(); i++) {
    coordinates_.push_back(initialCoordinates[i]);
  } 
}

/*
  Returns distance from instance point to passed point

  @param point p passed pont.
  @return double distance between points
*/
double Point::distance(Point compPoint) {
  if (coordinates_.size() == compPoint.coordinates_.size()) {
    double difference = 0;

    for (int i = 0; i < coordinates_.size(); i++) {
      difference += pow(abs(coordinates_[i] - compPoint.coordinates_[i]), 2);
    }

    return sqrt(difference);
  }
  else {
    std::cout << "Cannot calculate distance between points with different dimensions" << std::endl;
  }

  return 0.0;
}

/*
  Translates a point by an increment

    @param int translation translation quantity
    @return void
*/
void Point::translate(int translation) {
  if (coordinates_.size() > 0) {
    for (int i = 0; i < coordinates_.size(); i++) {
      coordinates_[i] += translation;
    }
  }
  else {
    std::cout << "Point has no values to translate" << std::endl;
  }
}
