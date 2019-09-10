/*
David Skrenta
PE 1
Point header file
*/

#include <vector>
#ifndef POINT
#define POINT

class Point {
  public:
    // Point contructor
    Point(std::vector<int> initialCoordinates);

    // Get coordinate by index
    int getCoordinate(int index) { return coordinates_[index]; } 

    // Push another coordinate to vector
    void setCoordinate(int value) { coordinates_.push_back(value); }

    // Calculates distance between instance and passed n-dimensional point
    double distance(Point compPoint);

    // Translates n-dimensional point
    void translate(int translation);

  private: 
    std::vector<int> coordinates_;
};

#endif
