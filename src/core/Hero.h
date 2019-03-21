#ifndef HERO_H
#define HERO_H
#include "Point.h"

class Hero
{
  private:
    Position posHero;
    int health;

  public:
    Hero ();
    ~Hero ();
    void deplacementGauche();
    void deplacementDroite();
    void deplacementHaut();
    void deplacementBas();
    void tir();
    float getX() const;
    float getY() const;
};
#endif
