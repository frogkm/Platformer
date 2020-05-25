#ifndef BLOCK_H
#define BLOCK_H

#include "GameObject.h"

class Block : public GameObject {

  public:
    Block(SDL_Renderer* rend, SDL_Surface* surface, int x, int y);


};

#endif
