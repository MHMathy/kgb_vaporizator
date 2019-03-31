#include "Hero.h"
#include "World.h"
#include <iostream>





World::World() : h(), niveauActu()
{

}

World::~World()
{
  niveauActu.~Niveau();
  h.~Hero();
}

Terrain& World::getTerrain () { return niveauActu.terrainActu; }

Hero& World::getHero () {	return h; }

Ennemi& World::getEnnemi (int i) { return niveauActu.tabEn[i]; }

Ennemi* World::getAddTabEnnemi () const{return niveauActu.tabEn;}


const Terrain& World::getConstTerrain () const { return niveauActu.terrainActu; }

const Hero& World::getConstHero () const { return h; }

const Ennemi& World::getConstEnnemi (int i) const { return niveauActu.tabEn[i]; }

const Ennemi * World::getConstAddTabEnn() const {return niveauActu.tabEn;}

const int& World::getNombreEnnemi() const { return niveauActu.nbEn; }

void World::actionsAutomatiques () {
    const Terrain& t = getTerrain();
    Ennemi* en = getAddTabEnnemi();
    h.majProj(t,en,niveauActu.nbEn);
    for(int i=0;i<niveauActu.nbEn;i++){
      if(en[i].getStatut())en[i].bougeAuto(t);
    }

}


void World::actionClavier (const char touche)
{

  Terrain& t = getTerrain();
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
