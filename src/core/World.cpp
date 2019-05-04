#include "Hero.h"
#include "World.h"
#include <iostream>





World::World() : h()
{
  chargeNiveau(1);
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

bool World::testSortie(){
  return ((h.getX()>niveauActu.posSortie.x-0.5) && (h.getX()<niveauActu.posSortie.x+0.5) && (h.getY()>niveauActu.posSortie.y-0.5) && (h.getY()<niveauActu.posSortie.y+0.5));
}

void World::chargeNiveau(int numNiveau){
  Position posH;
  string chemin;
  switch(numNiveau){
    case 0:
      chemin="data/testTerrain.txt";
      niveauActu=Niveau(chemin,posH);
      break;
    case 1:
      chemin="data/testTerrain1.txt";
      niveauActu=Niveau(chemin,posH);
      break;
  }
  h.setPos(posH);
}

void World::actionsAutomatiques (Point cs) {
    Terrain& t = getTerrain();
    Ennemi* en = getAddTabEnnemi();
    h.majProj(t,en,niveauActu.nbEn);
    for(int i=0;i<niveauActu.nbEn;i++){
      if(en[i].getStatut())en[i].deplacementEnnemi(t);
    }
    h.CalculerDirHero(cs);
    if(testSortie()==true)chargeNiveau(1);

}



void World::actionClavier (const char touche)
{

  Terrain& t = getTerrain();

	switch(touche)
	{
		case  'g':
        h.deplacementGauche(t);
        t.setTabDist(h.getX(),h.getY());
				break;
		case  'd':
        h.deplacementDroite(t);
        t.setTabDist(h.getX(),h.getY());
				break;
		case  'h':
				h.deplacementHaut(t);
        t.setTabDist(h.getX(),h.getY());
				break;
		case  'b':
				h.deplacementBas(t);
        t.setTabDist(h.getX(),h.getY());
		    break;
    case  't':
				h.tir(h.getDirVect());
				break;
	}
}
