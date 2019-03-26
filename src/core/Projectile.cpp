#include "Projectile.h"

Projectile::Projectile()
{
  etat = false;
  posActu=Position(0,0);
  posInit=Position(0,0);
  direction=Vecteur(0,0);
  degats=0;
}

Projectile::Projectile(Position posDepart, const char dir)
{
  etat = true;
  posActu=posDepart;
  posInit=posDepart;
  Vecteur newDirection;
  switch(dir){
    case 'o':
      newDirection = Vecteur(-1,0);
      break;
    case 'e':
      newDirection = Vecteur(1,0);
      break;
    case 'n':
      newDirection = Vecteur(0,1);
      break;
    case 's':
      newDirection = Vecteur(0,-1);
      break;
  }
  direction=newDirection;
  degats = 1;
}

Position Projectile::futurPos()
{
  Position p;
  p.x = posActu.x + direction.x;
  p.y = posActu.y + direction.y;
  return p;
}
void Projectile::collisionTer(const Terrain & ter)
{
  if (ter.estPositionValide(posActu.x,posActu.y)==false) etat = false;
}
/*void Projectile::collisionEn(Ennemi & en)
{
  if(posActu==en.getPosEn()) {
    etat = false;
    en.statut = false;
  }
}*/
void Projectile::trajectoire(const Terrain & ter)//, Ennemi & en)
{
  if(etat){
  posActu = futurPos();
  //collisionEn(en);
  collisionTer(ter);
  }
}
void Projectile::chEtat()
{
  etat=!etat;
}
float Projectile::getX () const { return posActu.x; }

float Projectile::getY () const { return posActu.y; }

bool Projectile::getEtat () const { return etat; }
