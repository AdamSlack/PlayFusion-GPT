#include "point2d.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

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

double Point2D::distanceToOrigin() {
  return distanceTo(Point2D(0,0));
}

std::vector<Point2D> Point2D::sortFromOrigin(std::vector<Point2D> points) {
  std::sort(points.begin(), points.end(),
                   [](Point2D a, Point2D b) -> bool {
                       return a.distanceToOrigin() < b.distanceToOrigin();
                     });
  return points;
}
