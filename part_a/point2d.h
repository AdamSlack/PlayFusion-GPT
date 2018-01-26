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
   private:
     Point2D();
};
