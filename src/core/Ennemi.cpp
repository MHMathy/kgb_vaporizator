#include "Ennemi.h"

Ennemi::Ennemi () {
	statut = true;
	posEn.x = posEn.y = 3;
	dir = 0;
}

void Ennemi::gauche (const Terrain & t) {
	if (t.estPositionValide(posEn.x-1,posEn.y)) posEn.x--;
}

void Ennemi::droite (const Terrain & t) {
	if (t.estPositionValide(posEn.x+1,posEn.y)) posEn.x++;
}

void Ennemi::haut (const Terrain & t) {
	if (t.estPositionValide(posEn.x,posEn.y+1)) posEn.y++;
}

void Ennemi::bas (const Terrain & t) {
	if (t.estPositionValide(posEn.x,posEn.y-1)) posEn.y--;
}

float Ennemi::getX () const { return posEn.x; }

float Ennemi::getY () const { return posEn.y; }

bool Ennemi::getStatut () const { return statut; }

Position Ennemi::getPosEn() const {return posEn; }

/*
void Ennemi::versHero (const Terrain & t, const Hero & h) {
    int dx = h.getX()-posEn.x;
    int dy = h.getY()-posEn.y;
    if (dx>0) dx=1;
    if (dx<0) dx=-1;
    if (dy>0) dy=1;
    if (dy<0) dy=-1;
    if (t.estPositionValide(posEn.x+dx,posEn.y+dy)) {
        posEn.x = posEn.x+dx;
        posEn.y = posEn.y+dy;
    }
}*/

void Ennemi::bougeAuto (const Terrain & t) {
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = posEn.x + dx[dir];
    ytmp = posEn.y + dy[dir];
    if (t.estPositionValide(xtmp,ytmp)) {
        posEn.x = xtmp;
        posEn.y = ytmp;
    }
    else dir = rand()%4;
}
