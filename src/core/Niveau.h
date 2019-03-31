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



};

#endif
