#include "World.h"
#include "Hero.h"
#include <iostream>

//Jeu::Jeu () : ter(), pac(), fan() {
//	ter.mangePastille(pac.getX(),pac.getY());
//}

World::World() : h(), niveauActu()
{

}

Terrain& World::getTerrain () { return niveauActu.terrainActu; }

Hero& World::getHero () {	return h; }

const Terrain& World::getConstTerrain () const { return niveauActu.terrainActu; }

const Hero& World::getConstHero () const { return h; }

//const Ennemi& World::getConstEnnemi () const { return fan; }

//int World::getNombreEnnemi() const { return 1; }

void World::actionClavier (const char touche)
{

  Terrain& t = getTerrain();
  Hero& h = getHero();
	switch(touche)
	{
		case 'g' :
        if (t.estPositionValide(h.getX()-1,h.getY()))
        {	h.deplacementGauche();}
				break;
		case 'd' :
        if (t.estPositionValide(h.getX()+1,h.getY()))
        {h.deplacementDroite();}
				break;
		case 'h' :
        if (t.estPositionValide(h.getX(),h.getY()+1))
				{h.deplacementHaut();}
				break;
		case 'b' :
        if (t.estPositionValide(h.getX(),h.getY()-1))
				{h.deplacementBas();}
				break;
	}
}
