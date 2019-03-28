#ifndef HERO_H
#define HERO_H

#include "Point.h"
#include "Terrain.h"
#include "Projectile.h"

class Hero
{
  private:
    Position posHero;
    int ptVie;
    char direc;

    Projectile * tabProj;
  public:
    Hero();
    ~Hero();
    int nbproj;
    void deplacementGauche(const Terrain & t);
    void deplacementDroite(const Terrain & t);
    void deplacementHaut(const Terrain & t);
    void deplacementBas(const Terrain & t);
    Projectile * getAddTabProj() const;
    void chDir(const char newDir);
    void tir(const char dir);
    void majProj(const Terrain & ter, Ennemi* tabEnn,int nbEn);
    Projectile getConstTabProj(int i)const;
    float getX() const;
    float getY() const;
    char getDir () const;
};
#endif
