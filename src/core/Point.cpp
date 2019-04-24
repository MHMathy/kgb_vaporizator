#include "Point.h"

Point::Point()
{
  x=0;
  y=0;
}

Point::Point(float nx,float ny)
{
  x=nx;
  y=ny;
}

bool Point::operator==(const Point & a) const
{
  return (x==a.x && y==a.y);
}

Point& Point::operator=(const Point& a)
{
  x = a.x;
  y = a.y;
  return *this;
}

/*Point& Point::operator+(const Point& a, const& Point b)
{
  x=a.x + b.y;
  y=a.y + b.y;
  return *this;
}

Point& Point::operator-(const Point& a, const& Point b)
{
  x=a.x- b.y;
  y=a.y- b.y;
  return *this;
}*/
