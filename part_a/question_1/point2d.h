class Point2D {
   public:
     int x;
     int y;

     Point2D(int x, int y);
     double distanceTo(Point2D point);

   private:
     Point2D();
};
