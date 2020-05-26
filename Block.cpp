#include "Block.h"

Block :: Block(SDL_Surface* surface, int x, int y) : GameObject(surface, x, y){
  rect.w = blockSize;
  rect.h = blockSize;
};
