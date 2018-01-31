#include <iostream>
#include <vector>

#include "point2d.h"

/*
 *  Main: Used to demonstrate the implemented Point2D Class.
 *
 */

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

  std::cout <<"Unordered points:"<< std::endl;
  for(Point2D point : points) {
    point.describe();
  }
  std::cout <<"Unordered points:"<< std::endl;
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

  Point2D A = Point2D(0,0);
  Point2D B = Point2D(2,2);

  Point2D C = Point2D(0,2);
  Point2D D = Point2D(2,0);
  
  Point2D E = Point2D(0,2);
  Point2D F = Point2D(2,4);

  bool abIntersect = Point2D::lineSegmentsIntersect(A,B,C,D);
  bool acIntersect = Point2D::lineSegmentsIntersect(A,B,E,F);
  bool bcIntersect = Point2D::lineSegmentsIntersect(C,D,E,F);

  std::cout << "A and B intersect? " << abIntersect << std::endl;
  std::cout << "A and C intersect? " << acIntersect << std::endl;
  std::cout << "B and C intersect? " << bcIntersect << std::endl;

  Point2D in = Point2D(5,5);
  Point2D out = Point2D(5,25);

  std::vector<Point2D> square = {Point2D(2,2),Point2D(2,6), Point2D(6,6), Point2D(6,2)};

  //std::cout<< Point2D::lineSegmentsIntersect(in, Point2D(7,7), Point2D(2,6), Point2D(6,6)) << std::endl;
  bool isInIn = Point2D::inPolygon(square, in);
  bool isOutIn = Point2D::inPolygon(square,out);

  std::cout << "Is the 'In' point inside the square: " << isInIn << std::endl;
  std::cout << "Is the 'out' point inside the square: " << isOutIn << std::endl;

  
  return 0;
}
