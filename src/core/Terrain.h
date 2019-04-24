#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>

using namespace std;

class Terrain
{
private:
  int dimx;
  int dimy;
  char *terrain;
  string cheminGrille;
  int *tabDist;
  //Case tabCase[dimx0][dimy0];
public:
  Terrain();
  ~Terrain();
  Terrain(string chemin);
  bool estPositionValide(const int x, const int y) const; // défini si la case est marchable par le Hero
  bool estPersoPositionValide(const int x, const int y) const;
  char getXY (const int x, const int y) const;
  int getDistXY (const int x, const int y) const;

  void clearTabDist();
  void setTabDist(float x,float y);

  int getDimX () const;

  int getDimY () const;
};



#endif
