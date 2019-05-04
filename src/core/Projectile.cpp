#include "Projectile.h"
#include "Point.h"


Projectile::Projectile()
{
  etat = false;
  posActu=Position(0,0);
  posInit=Position(0,0);
  direction=Vecteur(0,0);
  degats=0;
}

Projectile::Projectile(Position posDepart, Vecteur dir)
{
  etat = true;
  posActu=posDepart;
  posInit=posDepart;
  direction = Vecteur(dir.x,dir.y);
  degats = 1;
}

Projectile::~Projectile()
{}

Position Projectile::futurPos()
{
  Position p;
  p.x = posActu.x + direction.x;
  p.y = posActu.y + direction.y;
  return p;
}
void Projectile::collisionTer(const Terrain & ter)
{
  if (ter.estPositionValide(posActu.x+0.5,posActu.y+0.5)==false) etat = false;
}

void Projectile::collisionEn(Ennemi & en)
{Position posE = en.getPosEn();
  if(en.getStatut() && (posActu.x+0.5>posE.x) && (posActu.x+0.5<posE.x+1) && (posActu.y+0.5>posE.y) && (posActu.y+0.5<posE.y+1)) {
    etat = false;
    en.statut = false;
  }
}

void Projectile::trajectoire(const Terrain & ter, Ennemi * tabEnn ,int nbEn)
{
  if(etat){
  posActu = futurPos();
  //for(int i=0;i<nbE;i++)collisionEn(tabEnn[0]);
  for(int i=0;i<nbEn;i++)collisionEn(tabEnn[i]);
  collisionTer(ter);
  }
}

void Projectile::chEtat()
{
  etat=!etat;
}
float Projectile::getX () const { return posActu.x; }

float Projectile::getY () const { return posActu.y; }

Position Projectile::getPosProj () const { return posActu; }

bool Projectile::getEtat () const { return etat; }
