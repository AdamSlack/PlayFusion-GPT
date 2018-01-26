#include "point2d.h"
#include <iostream>
#include <math.h>

Point2D::Point2D() {
  x = 0;
  y = 0;
}

Point2D::Point2D(int xPos, int yPos) {
  x = xPos;
  y = yPos;
}

double Point2D::distanceTo(Point2D point) {
  return sqrt(pow((point.x - x),2) + pow((point.y - y),2));
}

void Point2D::describe() {
  std::cout << "Point at position: (" << x <<", " << y << ")" << std::endl;
}
