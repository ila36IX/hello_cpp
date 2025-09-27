#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
      private:
        Fixed x;
        Fixed y;

      public:
        Point();
        Point(const Point &);
        Point(float x, float y);
        Point &operator=(const Point &);
        ~Point();
        Fixed getx() const;
        Fixed gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif // POINT_H
