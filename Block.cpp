#include "Block.h"

Block :: Block(SDL_Renderer* rend, SDL_Surface* surface, int x, int y) : GameObject(rend, surface, x, y){
  rect.w = blockSize;
  rect.h = blockSize;
};
