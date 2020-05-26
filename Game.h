#ifndef GAME_H
#define GAME_H

#include "Block.h"
#include "Player.h"
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <fstream>


class Game {
  private:
    SDL_Window* win;

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
    static SDL_Renderer* rend;
    Game();
};


#endif
