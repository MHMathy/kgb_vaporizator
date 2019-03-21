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
	//const Ennemi& enn = w.getConstEnnemi();

	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getXY(x,y));

    // Affichage de Pacman
	win.print(h.getX(),h.getY(),'A');
	// Affichage du Fantome
	//win.print(fan.getX(),fan.getY(),'F');

	win.draw();
}

void txtBoucle (World & w) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    AffichageTXT win (w.getConstTerrain().getDimX(),w.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,w);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'z':
				w.actionClavier('h');
				break;
			case 'q':
				w.actionClavier('g');
				break;
			case 's':
				w.actionClavier('b');
				break;
			case 'd':
				w.actionClavier('d');
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}
