#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "AffichageTXT.h"
#include "txtJeu.h"
#include "Jeu.h"
#include "World.h"


void txtAff(AffichageTXT & win, const World & w) {
	const Terrain& ter = w.getConstTerrain();
	const Hero& h = w.getConstHero();
	const Ennemi * tEn=w.getAddTabEnnemi();
	const Projectile * proj = h.getConstAddTabProj();


	win.clear();
	int xmin=h.getX()-5;
	if (xmin<0) xmin = 0;
	int xmax=h.getX()+5;
	if (xmax>ter.getDimX()) xmax = ter.getDimX();
	int ymin=h.getY()-5;
	if (ymin<0) ymin = 0;
	int ymax=h.getY()+5;
	if (ymax>ter.getDimY()) ymax = ter.getDimY();
    // Affichage des murs
	/*for(int x=xmin;x<xmax;++x)
		for(int y=ymin;y<ymax;++y)
			win.print(x,y,ter.getXY(x,y));*/

	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getXY(x,y));

char charHero;//⇦ ⇨ ⇧ ⇩ //⬅  ➡ ⬆ ⬇ // ◀ ▶ ▲ ▼  //◁ ▷ △ ▽
switch(h.getDir()){
	case 'o':
		charHero = '<';
		break;
	case 'e':
		charHero = '>';
		break;
	case 'n':
		charHero = '^';
		break;
	case 's':
		charHero = 'v';
		break;

}
    // Affichage de Hero
	win.print(21,15,h.getDir());
	win.print(h.getX(),h.getY(),charHero);
	// Affichage de l'ennemi
	//if(en.getX()>xmin && en.getX()<xmax && en.getY()>ymin && en.getY()<ymax)
	for(int i=0;i<3;i++){
		if(tEn[i].statut)win.print(tEn[i].getX(),tEn[i].getY(),'E');
}
	for(int i=0;i<20;i++){
		if(proj[i].getEtat()) win.print(proj[i].getX(),proj[i].getY(),'+');
	}

	win.draw();
}

void txtBoucle (World & w) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    AffichageTXT win (w.getConstTerrain().getDimX(),w.getConstTerrain().getDimY());

	bool ok = true;


	do {
	    txtAff(win,w);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		w.actionsAutomatiques();

		switch (win.getCh()) {
			case 's':
				w.actionClavier('h');
				break;

			case 'z':
				w.actionClavier('b');
				break;

			case 'q':
				w.actionClavier('g');
				break;

			case 'd':
				w.actionClavier('d');
				break;
			case 'o'://72: //KEY_UP
				w.actionClavier('n');
				break;

			case 'l'://80: //KEY_DOWN
				w.actionClavier('s');
				break;

			case 'k'://75: //KEY_LEFT
				w.actionClavier('o');
				break;

			case 'm'://77: //KEY_RIGHT
				w.actionClavier('e');
				break;

			case 32:
				w.actionClavier('t');
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}
