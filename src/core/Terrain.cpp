#include "Terrain.h"
#include <cassert>
#include <iostream>
#include <string>
#include <fstream>




const char terrain1[15][21] = {
 "####################",
 "#        ##        #",
 "# #####  ##   #### #",
 "#        ##        #",
 "#        ###       #",
 "#   #  #    #      #",
 "#      #   ##      #",
 "#####  #    #  #####",
 "#      ##   #      #",
 "#      #    #      #",
 "#                  #",
 "#                  #",
 "#     #      #     #",
 "#     #      #     #",
 "####################"
};

Terrain::Terrain () {
	dimx = 20;
	dimy = 15;

  terrain = new char[dimx*dimy];
	for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)
		{char val=terrain1[dimy-1-y][x];
      terrain[x+y*dimx] = val;
    }
  }
}

Terrain::Terrain (string chemin,Position tabPos[],int & nbEn) {
    string terrain0[100];
    int i=0;
    ifstream file(chemin);
    if (!file) {
    cout << "Unable to open file"<<endl;
      exit(1);// call system to stop
    }
    if(file.is_open())
    {
        while (!file.eof())
        {
            getline(file,terrain0[i]);  // get 1 line at a time. After getting this one line, I want to pass this 1 line data to another process and
            // get back to here again for the next line to process. without opening the file again
            i++;
        }

    }
    dimx = terrain0[0].length();
    dimy = i-1;
    cout<<"dim"<<dimx<<' '<<dimy<<endl;
    terrain = new char[dimx*dimy];
    tabDist = new int [dimx*dimy];
	for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)
		{
      if(terrain0[y][x]=='H'){
        cout<<"trouver hero"<<endl;
        terrain[x+y*dimx]= '.';
        tabPos[0]=Position(x,y);}
      else if(terrain0[y][x]=='S'){
        cout<<"trouver sortie"<<endl;
        terrain[x+y*dimx]= '.';
        tabPos[1]=Position(x,y);}
      else if(terrain0[y][x]=='E'){
        cout<<"trouver ennemi"<<endl;
        terrain[x+y*dimx]= '.';
        tabPos[nbEn+2]=Position(x,y);nbEn++;}
      else{
        terrain[x+y*dimx] = terrain0[y][x];
      }


      tabDist[x+y*dimx] = 0;

    }
  }/*
  for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)cout<<terrain[x+y*dimx]<<' ';
    cout<<endl;
  }
  cout<<endl<<endl;*/
}

Terrain::~Terrain()
{
}

bool Terrain::estPositionValide (const int x, const int y) const
{
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (terrain[x+y*dimx]=='.'));
}

bool Terrain::estPersoPositionValide (const int x, const int y) const
{
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (terrain[x+y*dimx]=='.') && (terrain[x+1+y*dimx]=='.')&& (terrain[x+(y+1)*dimx]=='.')&& (terrain[x+1+(y+1)*dimx]=='.'));
}

void Terrain::clearTabDist()
{
  for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)tabDist[x+y*dimx]=0;
  }
}

//void Terrain::calculTabDist(float x,float y)

void Terrain::setTabDist(float x,float y)
{
  clearTabDist();
  Point * tabBuffActu = new Point [1];
  Point * tabBuffSuiv;
  tabDist[int(x)+int(y)*dimx]=1;
  tabBuffActu[0]=Point(x,y);
  int nbW=1;


  for(int i=2;i<22;i++){
    tabBuffSuiv = new Point [(i+1)*(i+1)];
    int nbN=0;

    for(int j=0;j<nbW;j++){
      int nx=tabBuffActu[j].x;
      int ny=tabBuffActu[j].y;
      int dx [4] = { 1, 0, -1, 0};
      int dy [4] = { 0, 1, 0, -1};

      for(int k=0;k<4;k++){
        if(estPositionValide(nx+dx[k],ny+dy[k]) && (tabDist[nx+dx[k]+dimx*(ny+dy[k])]==0)) {
          tabDist[nx+dx[k]+dimx*(ny+dy[k])]=i;
          tabBuffSuiv[nbN] = Point(nx+dx[k],ny+dy[k]);
          nbN++;}

    }
  }
    delete[] tabBuffActu;
    tabBuffActu=tabBuffSuiv;
    nbW=nbN;
  }/*
  for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)cout<<tabDist[x+y*dimx]<<' ';
    cout<<endl;
  }
  cout<<endl<<endl;
*/
}

char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return terrain[x+y*dimx];
}
int Terrain::getDistXY (const int x, const int y) const {
  assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
  return tabDist[x+y*dimx];
}

int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
