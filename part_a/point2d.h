#pragma once

#include <vector>

class Point2D {
   public:
     int x;
     int y;

     Point2D(int x, int y);
     double distanceTo(Point2D point);
     double distanceToOrigin();
     void describe();

     static std::vector<Point2D> sortFromOrigin(std::vector<Point2D> points);

     static bool areCollinear(Point2D a, Point2D b, Point2D c);

     static bool formACWTurn(Point2D a, Point2D b, Point2D c);

     static double twiceSignedArea(Point2D a, Point2D b, Point2D c);

     static bool lineSegmentsIntersect(Point2D a, Point2D b, Point2D c, Point2D d);

     static bool inPolygon(std::vector<Point2D> polygon, Point2D point);
     
   private:
     Point2D();
     
};

