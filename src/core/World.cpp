#include "World.h"
#include <iostream>





World::World() : h(), niveauActu()
{

}

Terrain& World::getTerrain () { return niveauActu.terrainActu; }

Hero& World::getHero () {	return h; }

Ennemi& World::getEnnemi () { return niveauActu.en; }

const Terrain& World::getConstTerrain () const { return niveauActu.terrainActu; }

const Hero& World::getConstHero () const { return h; }

const Ennemi& World::getConstEnnemi () const { return niveauActu.en; }

int World::getNombreEnnemi() const { return 1; }

void World::actionsAutomatiques () {
    const Terrain& t = getTerrain();
    Ennemi& en = getEnnemi();
    Hero& h = getHero();
    h.majProj(t);//,en);
    en.bougeAuto(t);

}


void World::actionClavier (const char touche)
{

  Terrain& t = getTerrain();
  Hero& h = getHero();
	switch(touche)
	{
		case  'g':
        h.deplacementGauche(t);
				break;
		case  'd':
        h.deplacementDroite(t);
				break;
		case  'h':
				h.deplacementHaut(t);
				break;
		case  'b':
				h.deplacementBas(t);
		    break;
    case  'o':
        h.chDir('o');
				break;
		case  'e':
        h.chDir('e');
				break;
		case  'n':
				h.chDir('n');
				break;
		case  's':
				h.chDir('s');
				break;
    case  't':
				h.tir(h.getDir());
				break;
	}
}
