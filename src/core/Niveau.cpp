#include "Niveau.h"
#include <iostream>


Niveau::Niveau() : en()
{
  string chemin = "data/testTerrain.txt";
  terrainActu = Terrain(chemin);
  //terrainActu = Terrain();
}
