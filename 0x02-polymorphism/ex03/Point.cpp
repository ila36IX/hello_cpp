#include "Point.h"

Point::Point() : x(0), y(0)
{
}

Point::Point(float x, float y) : x(x), y(y)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
        if (this == &other)
                return (*this);
        this->x = other.x;
        this->y = other.y;
        return (*this);
}

Fixed Point::getx() const
{
        return (this->x);
}

Fixed Point::gety() const
{
        return (this->y);
}
