#ifndef TERRAIN_H
#define TERRAIN_H
#include "Point.h"
#include <SDL2/SDL.h>
#include <math.h>

class Terrain
{
private:
  string cheminGrille;
  Case tabCase[300][300];
public:
  Terrain(string newChemin);
};



#endif
