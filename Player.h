#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
  private:
    int jumpHeight;

  public:
    Player(SDL_Renderer* rend, SDL_Surface* surface, int x, int y);


};

#endif
