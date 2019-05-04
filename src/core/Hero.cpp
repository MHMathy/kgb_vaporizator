#include "Hero.h"
#include "Projectile.h"
#include <math.h>

Hero::Hero()
{
  ptVie = 100;
  direc = 'e';
  direction=Vecteur(0,0);
  posHero.x = 1;
  posHero.y = 8;
  nbproj = 20;
  tabProj = new Projectile[20];
  for(int i=0;i<nbproj;i++) tabProj[i]=Projectile();
}

Hero::~Hero ()
{
  //delete[] tabProj;
}

void Hero::deplacementGauche (const Terrain & t)
{
  if (t.estPositionValide(posHero.x-1,posHero.y)) posHero.x--;
}

void Hero::deplacementDroite (const Terrain & t)
{
  if (t.estPositionValide(posHero.x+1,posHero.y)) posHero.x++;
}

void Hero::deplacementHaut (const Terrain & t)
{
  if (t.estPositionValide(posHero.x,posHero.y+1)) posHero.y++;
}

void Hero::deplacementBas(const Terrain & t)
{
   if (t.estPositionValide(posHero.x,posHero.y-1)) posHero.y--;
}

void Hero::CalculerDirHero(Point CoordSouris)
{
  Point diff;/*
	diff.x=(CoordSouris.x - (posHero.x+1)*32)+16;
	diff.y=(CoordSouris.y - (posHero.y+1)*32)+16;
*/
  diff.x=(CoordSouris.x - 360);
  diff.y=(CoordSouris.y - 240);
  if(abs(diff.x)>abs(diff.y))
  {
    direction = Vecteur(diff.x/abs(diff.x),diff.y/abs(diff.x));
    if(diff.x>0)direc='d';
    else if(diff.x<0)direc='g';
  }
  else if(abs(diff.x)<abs(diff.y))
  {
    direction = Vecteur(diff.x/abs(diff.y),diff.y/abs(diff.y));
    if(diff.y>0)direc='b';
    else if(diff.y<0)direc='h';
  }
  //cout<<direc<<endl;
}

void Hero::tir(Point direction)
{
  bool boucle = true;
  int i=0;
  while(boucle)
  {
    if(tabProj[i].getEtat()==false){
      tabProj[i] = Projectile(posHero,direction);
      boucle = false;
    }
    i++;
  }
}

void Hero::majProj(const Terrain & ter, Ennemi* tabEnn,int nbEn)
{
  for(int i=0;i<20;i++)
  {
    tabProj[i].trajectoire(ter,tabEnn,nbEn);
  }
}

Projectile* Hero::getAddTabProj()
{
  return tabProj;
}

const Projectile* Hero::getConstAddTabProj() const
{
  return tabProj;
}
Projectile Hero::getConstTabProj(int i) const
{
  return tabProj[i];
}

float Hero::getX () const { return posHero.x; }

float Hero::getY () const { return posHero.y; }

Position Hero::getPosH () const { return posHero; }

void Hero::setPos(Position pos){posHero=pos;}

char Hero::getDirChar () const { return direc; }

Vecteur Hero::getDirVect () const { return direction; }
