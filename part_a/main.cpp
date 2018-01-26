#include <iostream>
#include "point2d.h"

int main(int argc, char** argv) {
  
  Point2D pointA = Point2D(5,5);
  Point2D pointB = Point2D(0,0);
  
  pointA.describe();
  pointB.describe();

  double AToB = pointA.distanceTo(pointB);

  std::cout << "A to B: " << AToB << std::endl;
  
  return 0;
}
