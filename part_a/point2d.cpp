#include "point2d.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>


/*
*
*  Point2D class implementation...
*
*/

/*
 *  Default Constructor.
 */
Point2D::Point2D() {
  x = 0;
  y = 0;
}

/*
 *  Parameterised Constructor
 */
Point2D::Point2D(int xPos, int yPos) {
  x = xPos;
  y = yPos;
}

/*
 *  calculate the distance to another point.
 */
double Point2D::distanceTo(Point2D point) {
  return sqrt(pow((point.x - x),2) + pow((point.y - y),2));
}

/*
 * Print out the (x,y) co-ordinates of the point.
 */
void Point2D::describe() {
  std::cout << "Point at position: (" << x <<", " << y << ")" << std::endl;
}


/*
 * Calculate the distance from this point to the origin (0,0).
 */
double Point2D::distanceToOrigin() {
  return distanceTo(Point2D(0,0));
}

/*
 * create a sorted list of points in order of shortest distance to origin to longest.
 */
std::vector<Point2D> Point2D::sortFromOrigin(std::vector<Point2D> points) {
  std::sort(points.begin(), points.end(),
                   [](Point2D a, Point2D b) -> bool {
                       return a.distanceToOrigin() < b.distanceToOrigin();
                     });
  return points;
}

/*
 * Calculate double the area of the triangle formed by points A, B, and C
 */
double Point2D::twiceSignedArea(Point2D a, Point2D b, Point2D c) {
  return ((b.x - a.x)*(c.y - a.y)) - ((b.y - a.y)*(c.x - a.x));
}

/*
 * Check if points A, B, and C are collinear
 */
bool Point2D::areCollinear(Point2D a, Point2D b, Point2D c) {
  return Point2D::twiceSignedArea(a,b,c) == 0;
}

/*
 * Check if points A, B, and C form a Anti-clockwise turn
 */
bool Point2D::formACWTurn(Point2D a, Point2D b, Point2D c) {
  return Point2D::twiceSignedArea(a,b,c) > 0;
}


/*
 * check if line formed by points A and B intersects the line formed by points C and D
 */
bool Point2D::lineSegmentsIntersect(Point2D a, Point2D b, Point2D c, Point2D d){
  return Point2D::twiceSignedArea(a, c, b) *
         Point2D::twiceSignedArea(a, d, b) < 0
         &&
         Point2D::twiceSignedArea(c, a, d) *
         Point2D::twiceSignedArea(c, b, d) < 0;
}

/*
 * Check if the point is inside the provided polygon
 */
bool Point2D::inPolygon(std::vector<Point2D> polygon, Point2D point) {
  // uses crossing number or even-odd rule algo'
  Point2D maxX = *std::max_element(polygon.begin(), polygon.end(),
                               [](Point2D a, Point2D b) -> bool {
                                 return a.x < b.x;
                               });

  Point2D maxY = *std::max_element(polygon.begin(), polygon.end(),
                               [](Point2D a, Point2D b) -> bool {
                                 return a.y < b.y;
                               });
  
  std::vector<std::pair<Point2D, Point2D>> polygonPairs;
  
  polygon.push_back(polygon.front());

  for (std::pair<std::vector<Point2D>::iterator, std::vector<Point2D>::iterator>
         it(polygon.begin(), ++polygon.begin());
       it.second != polygon.end();
       ++it.first, ++it.second){
    polygonPairs.push_back(std::pair<Point2D, Point2D>(*it.first, *it.second));
  }
  
  Point2D outsidePoint = Point2D(maxX.x + 1, maxY.y + 1);

  int numberOfIntersects = std::count_if(
               polygonPairs.begin(),
               polygonPairs.end(),
               [outsidePoint, point](std::pair<Point2D, Point2D> seg) -> bool {
                 return  Point2D::lineSegmentsIntersect(point, outsidePoint, seg.first, seg.second);
               });
  
  int numberOfVertexIntersects = std::count_if(
               polygonPairs.begin(),
               polygonPairs.end(),
               [outsidePoint, point](std::pair<Point2D, Point2D> seg) -> bool {
                 // check if colinear and between nearest and furthest...
                 return  Point2D::areCollinear(point, seg.first, outsidePoint) &&
                   seg.first.x > point.x &&
                   seg.first.y > point.y;
               });
  
  return (numberOfIntersects % 2) != 0 || (numberOfVertexIntersects == 1 && numberOfIntersects == 0);
}
