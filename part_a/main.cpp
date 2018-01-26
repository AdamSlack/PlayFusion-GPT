#include <iostream>
#include <vector>

#include "point2d.h"


int main(int argc, char** argv) {
  
  Point2D pointA = Point2D(5,5);
  Point2D pointB = Point2D(0,0);
  
  pointA.describe();
  pointB.describe();

  double AToB = pointA.distanceTo(pointB);

  std::cout << "A to B: " << AToB << std::endl;
  std::cout << "A to Origin: " << pointA.distanceToOrigin() << std::endl;

  std::vector<Point2D> points = {Point2D(3,3), Point2D(0,0), Point2D(1,1)};

  std::vector<Point2D> sortedPoints = Point2D::sortFromOrigin(points);

  std::cout <<"Unordered points:"<<std::endl;
  for(Point2D point : points) {
    point.describe();
  }
  std::cout <<"Unordered points:"<<std::endl;
  for(Point2D point : sortedPoints) {
    point.describe();
  }

  return 0;
}
