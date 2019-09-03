/*
David Skrenta
PE 1
Point header file
*/

#ifndef POINT
#define POINT

class Point {
  public:
    // Point Contructor
    Point();

    // Getters
    int getX() { return x; }
    int getY() { return y; }

    // Setters
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }

    // Distance and translate methods
    double distance(Point p);
    void translate(int inc);

    // Initialize point values
    int x;
    int y;
};

#endif
