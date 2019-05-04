/**
@brief Module gérant un ennemi
@file Ennemi.h
@date 2017/01/17
*/

#ifndef ENNEMI_H
#define ENNEMI_H

#include "Terrain.h"
//#include "Hero.h"
#include "Point.h"

 /**
@brief Un Ennemi = sa position 2D
*/
class Ennemi {

private :

	Position posEn;
	int dir;

public:
		bool statut;
    Ennemi();
		Ennemi(Position pEn);
		~Ennemi();

    void gauche (const Terrain & t);
    void droite (const Terrain & t);
    void haut (const Terrain & t);
    void bas (const Terrain & t);

    float getX () const;
    float getY () const;
		bool getStatut () const;
		Position getPosEn() const;

		void deplacementEnnemi (const Terrain & t);

    void bougeAuto (const Terrain & t);

};

#endif
