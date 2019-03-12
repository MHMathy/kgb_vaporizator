#include <iostream>
#include "Affichage.h"
using namespace std;

int main (void)
{
  AffichageSDL aff;
  aff();
  aff.sdlBoucle();
  return 0;
};
