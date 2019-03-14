#ifndef POINT_H
#define POINT_H

class Point
{

private:
  float x,y;

public:

  float getX();
  //Fonction permettant de récupérer la coordonnée X
  float getY();
  //Fonction permettant de récupérer la coordonnée Y

  void setX(float new_x);
  void setY(float new_y);
};







#endif
