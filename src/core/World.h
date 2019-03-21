#ifndef WORLD_H
#define WORLD_H
#include "Niveau.h"
#include "Hero.h"



class World
{
private:
  Hero  h;
  Niveau  niveauActu;
public:

  World();

  Terrain& getTerrain ();
  Hero& getHero ();
  const Terrain& getConstTerrain () const;
  const Hero& getConstHero () const;
  //const Fantome& getConstEnnemi () const;
  //int getNombreEnnemi() const;
  void actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon





};


#endif
