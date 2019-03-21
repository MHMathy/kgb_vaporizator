#include "Terrain.h"
#include <cassert>


const char terrain0[10][11]=
{
  "....######",
  ".........#",
  ".........#",
  "....##...#",
  ".........#",
  ".........#",
  ".........#",
  ".........#",
  ".........#",
  "##########"
  /*
  "000#####00",
  "00#11111#0",
  "0#111111#0",
  "#111##111#",
  "#111##111#",
  "#11111111#",
  "#11111111#",
  "#11111111#",
  "0#111111#0",
  "00######00"
  */
};


Terrain::Terrain()
{
  dimx=10;
  dimy=10;
  for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)
    {
			terrain[x][y] = terrain0[x][y];
    }
  }
}


bool Terrain::estPositionValide (const int x, const int y) const
{
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (terrain[x][y]=='.'));
}


char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return terrain0[x][y];
}

int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
