#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>

using namespace std;

class Terrain
{
private:
  int dimx;
  int dimy;
  char terrain[100][100];
  string cheminGrille;
  //Case tabCase[dimx0][dimy0];
public:
  Terrain();
  //Terrain(string newChemin);
  bool estPositionValide(const int x, const int y) const; // défini si la case est marchable par le Hero
  char getXY (const int x, const int y) const;

  int getDimX () const;

  int getDimY () const;
};



#endif
