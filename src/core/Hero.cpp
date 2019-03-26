#include "Hero.h"

Hero::Hero()
{
  ptVie = 100;
  direc = 'o';
  posHero.x = 1;
  posHero.y = 1;
  for(int i=0;i<20;i++) tabProj[i]=Projectile();
}

Hero::~Hero ()
{

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

void Hero::majProj(const Terrain & ter)//, Ennemi & enn)
{
  for(int i=0;i<20;i++)
  {
    tabProj[i].trajectoire(ter);//,enn);
  }
}

void Hero::chDir(const char newDir)
{
  direc = newDir;
}

Projectile Hero::getConstTabProj(int i) const
{
  return tabProj[i];
}

float Hero::getX () const { return posHero.x; }

float Hero::getY () const { return posHero.y; }

char Hero::getDir () const { return direc; }
