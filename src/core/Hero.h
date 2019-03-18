#ifndef HERO_H
#define HERO_H
#include "Point.h"
#include <SDL2/SDL.h>
#include <math.h>

class Hero
{
  private:
    Position posHero;
    int sante;

  public:
    Hero ();
    ~Hero ();
    void deplacement(int x, int y);
    void tir();




};
#endif
