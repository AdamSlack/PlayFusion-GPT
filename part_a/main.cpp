#include <iostream>
#include <vector>

#include "point2d.h"


int main(int argc, char** argv) {
  
  Point2D pointA = Point2D(0,0);
  Point2D pointB = Point2D(5,5);
  Point2D pointC = Point2D(10,10);
  Point2D pointD = Point2D(10,2);
  Point2D pointE = Point2D(2,10);
  
  pointA.describe();
  pointB.describe();

  double AToB = pointB.distanceTo(pointA);

  std::cout << "A to B: " << AToB << std::endl;
  std::cout << "A to Origin: " << pointB.distanceToOrigin() << std::endl;

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

  bool abcCollinear = Point2D::areCollinear(pointA,pointB,pointC);
  bool abdCollinear = Point2D::areCollinear(pointA,pointB,pointD);
  bool abeCollinear = Point2D::areCollinear(pointA,pointB,pointE);

  bool abcACW = Point2D::formACWTurn(pointA,pointB,pointC);
  bool abdACW = Point2D::formACWTurn(pointA,pointB,pointD);
  bool abeACW = Point2D::formACWTurn(pointA,pointB,pointE);

  std::cout << "ABC - Collinear: " << abcCollinear << " form ACW Turn: " << abcACW << std::endl;
  std::cout<< "ABC : " << std::endl;;
  pointA.describe();pointB.describe();pointC.describe();

  std::cout << "ABD - Collinear: " << abdCollinear << " form ACW Turn: " << abdACW << std::endl;

  std::cout << "ABE - Collinear: " << abeCollinear << " form ACW Turn: " << abeACW << std::endl;

  return 0;
}
