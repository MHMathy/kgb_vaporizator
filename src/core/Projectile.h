ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SDL2/SDL.h>
#include <math.h>
#include "Point.h"

class Projectile
{
private:
  Position posActuelle;
  Position posInitial;
  Vecteur direction;
  int degats;

public:
  Projectile(); // constructeur sans arguments, initialise à l'origine
  Projectile(Position posDepart, Vecteur newDirection); // Constructeur qui initialise un projectile en fonction d'une position de départ en paramètre
  ~Projectile();

};
#endif
