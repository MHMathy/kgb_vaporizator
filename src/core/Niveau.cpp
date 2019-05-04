#include "Niveau.h"
#include "Ennemi.h"

#include <iostream>


Niveau::Niveau()
{
  nbEn = 3;
  tabEn=new Ennemi[nbEn];
  for(int i=0;i<nbEn;i++)tabEn[i] = Ennemi();
  string chemin = "data/testTerrain.txt";
  terrainActu = Terrain();
  //terrainActu = Terrain();
}

Niveau::Niveau(string chemin,Position & pHero)
{
  nbEn = 0;
  Position elem[30];
  terrainActu = Terrain(chemin,elem,nbEn);
  tabEn=new Ennemi[nbEn];
  for(int i=0;i<nbEn;i++)tabEn[i] = Ennemi(elem[i+2]);
  pHero=elem[0];
  posSortie=elem[1];


  //terrainActu = Terrain();
}

Niveau::~Niveau()
{
  //delete[] tabEn;
}
