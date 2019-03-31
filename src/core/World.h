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
  ~World();

  Terrain& getTerrain ();
  Hero& getHero ();
  Ennemi& getEnnemi(int i);
  Ennemi* getAddTabEnnemi () const;

  const Terrain& getConstTerrain () const;
  const Hero& getConstHero () const;
  const Ennemi& getConstEnnemi (int i) const;
  const Ennemi * getConstAddTabEnn() const;
  const int& getNombreEnnemi() const;


  void actionsAutomatiques ();
  void actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

};


#endif
