#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Block.h"
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <fstream>


class Game {
  private:
    SDL_Window* win;
    SDL_Renderer* rend;
    bool running;
    void loop();
    void checkKeyboard();
    void draw();
    void checkCollision();
    void cleanUp();
    void init();
    void populateBlocks();
    Player* player;
    vector<Block*> blocks;

  public:
    Game();
};


#endif
