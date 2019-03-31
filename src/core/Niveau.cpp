#include "Niveau.h"
#include "Ennemi.h"

#include <iostream>


Niveau::Niveau()
{
  nbEn = 3;
  tabEn=new Ennemi[nbEn];
  for(int i=0;i<nbEn;i++)tabEn[i] = Ennemi();
  string chemin = "data/testTerrain.txt";
  terrainActu = Terrain(chemin);
  //terrainActu = Terrain();
}

Niveau::~Niveau()
{
  //delete[] tabEn;
}
