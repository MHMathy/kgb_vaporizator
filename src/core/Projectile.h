#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Point.h"
#include "Ennemi.h"
#include "Terrain.h"

class Projectile
{
private:
  bool etat;
  Position posActu;
  Position posInit;
  Vecteur direction;
  int degats;

public:
  Projectile(); // constructeur sans arguments, initialise à l'origine
  ~Projectile();
  Projectile(Position posDepart, Vecteur dir); // Constructeur qui initialise un projectile en fonction d'une position de départ en paramètre


  Position futurPos();
  void collisionTer(const Terrain & ter);
  void collisionEn(Ennemi & en);
  void trajectoire(const Terrain & ter, Ennemi * tabEnn,int nbEn);

  void chEtat();

  float getX () const;

  float getY () const;
  Position getPosProj() const;
  bool getEtat () const;

};
#endif
