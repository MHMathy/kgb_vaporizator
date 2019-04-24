#ifndef NIVEAU_H
#define NIVEAU_H

#include "Terrain.h"
//#include "TableauDynamique.h"
#include "Ennemi.h"
class Niveau
{
public:
  int nbEn;
  Ennemi* tabEn;
  Terrain terrainActu;

  Niveau();
  ~Niveau();

//creer fonction terrain qui renvoie tableau de position des ennemis
//intialiser les ennemis en fontion

};

#endif
