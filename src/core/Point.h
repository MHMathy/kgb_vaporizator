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
};

typedef Point Position;
typedef Point Vecteur;
#endif
