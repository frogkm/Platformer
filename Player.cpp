#include "Player.h"

Player :: Player(char* filePath, int x, int y) : GameObject(filePath, x, y){
  xSpeed = 5;
  gravity = -5;

};

int Player :: getXSpeed(){
  return xSpeed;

}

void Player :: update(vector<Block*> blocks){
  setY(getY() - gravity);
  for(Block* block : blocks){
    if(getY() < block->getY() && SDL_HasIntersection(getRect(),block->getRect())){
      setY(block->getY() - getH());
    }

  }

}
