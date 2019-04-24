#ifndef POINT_H
#define POINT_H

class Point
{
public:
  float x;
  float y;

  Point();
  Point(float nx,float ny);
  bool operator==(const Point & a) const;

  Point& operator=(const Point& a);

/*  Point& operator+(const Point & a, Point & b);

  Point& operator-(const Point & a, Point &b)*/

};
typedef Point Position;
typedef Point Vecteur;

#endif
