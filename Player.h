#ifndef PLAYER_H
#define PLAYER_H

#include "Block.h"
#include <vector>

class Player : public GameObject {

  public:
    Player(char* filePath, int x, int y);
    void update(vector<Block*> blocks);

    int getXSpeed();



  private:
    int xSpeed;
    int gravity;

};

#endif
