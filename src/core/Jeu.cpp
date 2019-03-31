#include "Jeu.h"
#include <iostream>


Jeu::Jeu() : w()
{

}

Jeu::~Jeu()
{
  w.~World();
}


//void Jeu::actionsAutomatiques () {
    //fan.versPacman(ter,pac);
  //  fan.bougeAuto(ter);
