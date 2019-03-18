#include "Projectile.h"

Projectile::Projectile()
{
  posActuelle=0;
  posInitial=0;
  direction=0;
  degats=0;
}

Projectile::Projectile(Position posDepart, Vecteur newDirection)
{
  posActuelle=posDepart;
  posInitial=posDepart;
  direction=newDirection;
}
