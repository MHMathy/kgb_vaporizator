#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;
int mouseX;
int mouseY;
Point * pp;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer)
{
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;


    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,(surface->pixels),(surface->pitch));
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : wor() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;sound = Mix_LoadWAV("data/son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; SDL_Quit(); exit(1);
        }
    }
    else withSound = true;

	int dimx, dimy;
  /*
	dimx = wor.getConstTerrain().getDimX();
	dimy = wor.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;
  */
  dimx=720;
  dimy=480;
    // Creation de la fenetre
    window = SDL_CreateWindow("KGB Vaporizator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_hero_d0.loadFromFile("data/Hero/d0.png",renderer);
    im_hero_g0.loadFromFile("data/Hero/g0.png",renderer);
    im_hero_b0.loadFromFile("data/Hero/b0.png",renderer);
    im_hero_h0.loadFromFile("data/Hero/h0.png",renderer);
    im_mur.loadFromFile("data/mur2.png",renderer);
    im_sol.loadFromFile("data/sol.png",renderer);
    im_pastille.loadFromFile("data/pastille.png",renderer);
    im_ennemi.loadFromFile("data/fantome.png",renderer);


    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
	}
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"KGB Vaporizator",font_color));
	font_im.loadFromCurrentSurface(renderer);

    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; SDL_Quit(); exit(1);
        }
    }
}

sdlJeu::~sdlJeu () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    wor.~World();
}

bool visible(Position pHero,Position pElement){
  return ((pElement.x-pHero.x>-12) && (pElement.x-pHero.x<13) && (pElement.y-pHero.y>-8) && (pElement.y-pHero.y<9));
}


void sdlJeu::sdlAff () {
	//Remplir l'�cran de blanc
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Terrain& ter = wor.getConstTerrain();
	const Hero& hero = wor.getConstHero();
	const Ennemi* enn = wor.getConstAddTabEnn();
  const Projectile* tabP = hero.getConstAddTabProj();



    // Afficher les sprites des murs et des pastilles
	for (x=0;x<ter.getDimX();x++)
		for (y=0;y<ter.getDimY();y++){
			if (ter.getXY(x,y)=='#' && visible(hero.getPosH(),Position(x,y)))
				im_mur.draw(renderer,344-(hero.getX()-x)*TAILLE_SPRITE,224-(hero.getY()-y)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      if (ter.getXY(x,y)=='.' && visible(hero.getPosH(),Position(x,y)))
				im_sol.draw(renderer,344-(hero.getX()-x)*TAILLE_SPRITE,224-(hero.getY()-y)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }
	// Afficher le sprite du hero
  /*
  switch(hero.getDirChar()){
    case 'd':
      im_hero_d0.draw(renderer,hero.getX()*TAILLE_SPRITE,hero.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'g':
      im_hero_g0.draw(renderer,hero.getX()*TAILLE_SPRITE,hero.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'h':
      im_hero_h0.draw(renderer,hero.getX()*TAILLE_SPRITE,hero.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'b':
      im_hero_b0.draw(renderer,hero.getX()*TAILLE_SPRITE,hero.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
  }
*/
  switch(hero.getDirChar()){
    case 'd':
      im_hero_d0.draw(renderer,344,224,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'g':
      im_hero_g0.draw(renderer,344,224,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'h':
      im_hero_h0.draw(renderer,344,224,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
    case 'b':
      im_hero_b0.draw(renderer,344,224,TAILLE_SPRITE,TAILLE_SPRITE);
      break;
  }



	// Afficher le sprite des ennemis
  for(int i=0;i<wor.getNombreEnnemi();i++){
    if(enn[i].getStatut() && visible(hero.getPosH(),enn[i].getPosEn()))
    im_ennemi.draw(renderer,344-(hero.getX()-enn[i].getX())*TAILLE_SPRITE,224-(hero.getY()-enn[i].getY())*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);}
  for(int i=0;i<hero.nbproj;i++) {
    if(tabP[i].getEtat() && visible(hero.getPosH(),tabP[i].getPosProj()))
    im_pastille.draw(renderer,344-(hero.getX()-tabP[i].getX())*TAILLE_SPRITE,224-(hero.getY()-tabP[i].getY())*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);}
    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
      Point cs;

    Uint32 fps = SDL_GetTicks(),t = SDL_GetTicks(), nt;

	// tant que ce n'est pas la fin ...
	while (!quit) {
    // début du getsouris
    int trucx = int (cs.x*32);
    int * tempcsx=&trucx;
    int trucy = int (cs.y*32);
    int * tempcsy=&trucy;
    SDL_GetMouseState(tempcsx,tempcsy);
    cs.x=trucx;
    cs.y=trucy;
    //cout<<"cs.x  =  " <<trucx<<endl<<"cs.y  =  "<<trucy<<endl;
    //fin du getsouris

        nt = SDL_GetTicks();
        if (nt-t>50) {
            wor.actionsAutomatiques(cs);
            t = nt;



		// tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if ((events.type == SDL_KEYDOWN) || (events.type == SDL_MOUSEBUTTONDOWN)) {              // Si une touche est enfoncee ou un clique souris est enfoncé
				switch (events.key.keysym.scancode) {

          case SDL_SCANCODE_S:
    				wor.actionClavier('h');
    				break;

    			case SDL_SCANCODE_W:
    				wor.actionClavier('b');
    				break;

    			case SDL_SCANCODE_A:
    				wor.actionClavier('g');
    				break;

    			case SDL_SCANCODE_D:
    				wor.actionClavier('d');
    				break;

    			case SDL_SCANCODE_SPACE:
    				wor.actionClavier('t'  );
    				break;
					break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_P:
                    quit = true;
                    break;
				default: break;
				}


      }

				if ((withSound) && false)
                    Mix_PlayChannel(-1,sound,0);
			}
		}

		// on affiche le jeu sur le buffer cach�
    nt = SDL_GetTicks();
    if (nt-fps>10) {
  	sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
        fps = nt;
      }
	}
}
