#ifndef AFFICHAGESDL_H
#define AFFICHAGESDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class AffichageSDL
{
private:
  SDL_Window * window;
  SDL_Renderer * renderer;
public:
  AffichageSDL ();
  ~AffichageSDL ();
  void sdlBoucle ();
  void sdlAff ();
};

#endif
