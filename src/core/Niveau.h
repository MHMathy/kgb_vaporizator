#ifndef NIVEAU_H
#define NIVEAU_H

#include "Terrain.h"
//#include "TableauDynamique.h"
#include "Ennemi.h"
class Niveau
{
public:
  Position posSortie;
  int nbEn;
  Ennemi* tabEn;
  Terrain terrainActu;

  Niveau();
  Niveau(string chemin,Position & pHero);
  ~Niveau();

//creer fonction terrain qui renvoie tableau de position des ennemis
//intialiser les ennemis en fontion

};

#endif
