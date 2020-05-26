#include "Block.h"

Block :: Block(char* filePath, int x, int y) : GameObject(filePath, x, y){
  rect.w = blockSize;
  rect.h = blockSize;
};
