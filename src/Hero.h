#ifndef HERO_H
#define HERO_H
#include <Position.h>
#include <SDL2/SDL.h>
#include <math.h>

class Hero {
private:
  Position posHero;

public:
  Hero ();
  ~Hero ();
  void deplacement(int x, int y);
  void tir();




};
#endif
