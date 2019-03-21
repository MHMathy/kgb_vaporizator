#include "Hero.h"

Hero::Hero()
{
  health = 100;
  posHero.x = 0;
  posHero.y = 0;
}

Hero::~Hero()
{

}

void Hero::deplacementGauche ()
{
  posHero.x--;
}

void Hero::deplacementDroite ()
{
  posHero.x++;
}

void Hero::deplacementHaut ()
{
  posHero.y++;
}

void Hero::deplacementBas()
{
   posHero.y--;
}

float Hero::getX () const { return posHero.x; }

float Hero::getY () const { return posHero.y; }
