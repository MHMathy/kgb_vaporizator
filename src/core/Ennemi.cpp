#include "Ennemi.h"
//faire la fontion bouge auto pour que les ennemies ait un pattern a leur création
Ennemi::Ennemi () {
	statut = true;
	posEn.x = posEn.y = 3;
	dir = 0;
}

Ennemi::Ennemi (Position pEn) {
	statut = true;
	posEn = pEn;
	dir = 0;
}

Ennemi::~Ennemi()
{}

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

Point calculMouvement(const Terrain & t,float x,float y,int val,char choix,int lim){
	int dx [4] = { 1, 0, -1, 0};
	int dy [4] = { 0, 1, 0, -1};
	Point tab[4];

		for(int i=0;i<4;i++)
		{
			if(choix=='<'){
			int val2 = t.getDistXY(x+dx[i],y+dy[i]);
			if(val2<val && val2>=lim && t.estPositionValide(x+dx[i],y+dy[i])){
				tab[i]=Point(dx[i],dy[i]);
			}
			else{
				tab[i]=Point(0,0);
			}
		}

		if(choix=='>'){
		int val2 = t.getDistXY(x+dx[i],y+dy[i]);
		if(val2>val && val2<=lim && t.estPositionValide(x+dx[i],y+dy[i])){
			tab[i]=Point(dx[i],dy[i]);
		}
		else{
			tab[i]=Point(0,0);
			}
		}
	}
	while(true)
	{
		int RandIndex = rand() % 4; //generates a random number between 0 and 3
		if(tab[RandIndex]==Point(0,0)){}
		else {
			return tab[RandIndex];
			break;
		}
	}
}

void Ennemi::deplacementEnnemi (const Terrain & t) {
	int val = t.getDistXY(posEn.x,posEn.y);
	int lim=5;
	Point nextPos[2];
	nextPos[0] = Point();nextPos[1] = Point();
	if(val!=0)
	{
		if (val>lim){
			nextPos[0] = calculMouvement(t,posEn.x,posEn.y,val,'<',lim);
			nextPos[1] = calculMouvement(t,posEn.x+nextPos[0].x,posEn.y+nextPos[0].y,val,'<',lim-1);
		}
		if (val<lim){
			nextPos[0] = calculMouvement(t,posEn.x,posEn.y,val,'>',lim);
			nextPos[1] = calculMouvement(t,posEn.x+nextPos[0].x,posEn.y+nextPos[0].y,val,'>',lim+1);
		}

		if(t.estPositionValide(posEn.x+nextPos[1].x,posEn.y+nextPos[1].y))
			{
				posEn.x += nextPos[0].x/10;// +nextPos[1].x/20 ;
		  	posEn.y += nextPos[0].y/10;// +nextPos[1].y/20 ;
			}
		else if( !(posEn.x==int(posEn.x) && posEn.y==int(posEn.y))) {
			posEn.x += nextPos[0].x/10;
			posEn.y += nextPos[0].y/10;
		}
		else{
			posEn.x += nextPos[0].x/10;
			posEn.y += nextPos[0].y/10;
		}
	}
	else{ bougeAuto(t);}
}


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
