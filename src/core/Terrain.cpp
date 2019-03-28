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
	for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)
		{
      terrain[x][y] = terrain1[dimy-1-y][x];

    }
  }
}

Terrain::Terrain (string chemin) {


    string terrain0[100];
    int i=0;
    ifstream file(chemin);
    if (!file) {
    cout << "Unable to open file"<<endl;
      exit(1);// call system to stop
    }
    cout<<'f';
    if(file.is_open())
    {
        while (!file.eof())
        {
            getline(file,terrain0[i]);  // get 1 line at a time. After getting this one line, I want to pass this 1 line data to another process and
            // get back to here again for the next line to process. without opening the file again
            cout<<terrain0[i]<<endl;

            i++;
        }

    }
    dimx = terrain0[0].length();
    dimy = i-1;
    //cout<<dimx<<' '<<dimy<<endl;

	for(int x=0;x<dimx;++x)
  {
		for(int y=0;y<dimy;++y)
		{
      terrain[x][y] = terrain0[y][x];

    }
  }
}

Terrain::~Terrain()
{

}

bool Terrain::estPositionValide (const int x, const int y) const
{
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (terrain[x][y]!='#'));
}


char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return terrain[x][y];
}

int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
