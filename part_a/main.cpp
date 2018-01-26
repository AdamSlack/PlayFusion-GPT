#include <iostream>
#include "point2d.h"

int main(int argc, char** argv) {
  
  Point2D point = Point2D(5,5);

  std::cout << "Point created at position: (" << point.x <<", " << point.y << ")" << std::endl;
  
  return 0;
}
