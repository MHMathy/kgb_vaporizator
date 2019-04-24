#include "Hero.h"
#include "Projectile.h"
#include <math.h>

Hero::Hero()
{
  ptVie = 100;
  direc = 'e';
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

void Hero::CalculerDirHeroByChar(Point CoordSouris)
{
	Point diff;
	diff.x=CoordSouris.x - posHero.x;
	diff.y=CoordSouris.y - posHero.y;

	float ang=atan2(CoordSouris.x,CoordSouris.x)*180/M_PI;
	if(ang < -45) ang+=360;


	if (-45<ang && ang<=45){ direc='e'; }
	else if (45<ang && ang<=135){ direc='n' ;}
	else if (135<ang && ang<=225){ direc='o';}
	else if (225<ang && ang<=-45){ direc='s';}

}

void Hero::tir(const char dir)
{
  bool boucle = true;
  int i=0;
  while(boucle)
  {
    if(tabProj[i].getEtat()==false){
      tabProj[i] = Projectile(posHero,dir);
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

void Hero::chDir(const char newDir)
{
  direc = newDir;
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

char Hero::getDir () const { return direc; }
