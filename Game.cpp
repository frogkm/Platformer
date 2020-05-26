#include "Game.h"

SDL_Renderer* Game :: rend = nullptr;

Game :: Game() {
  init();
  while(running){
    loop();
  }
  cleanUp();
}

void Game :: init(){
  win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sW, sH, 0);
  Game :: rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  running = true;
  populateBlocks();
  player = new Player("Resources/Player.png", 200, 300);

}

void Game :: loop(){
  checkKeyboard();

  player->update(blocks);

  draw();
}

void Game :: populateBlocks(){
  string line;
  ifstream myfile ("mapTest.txt");
  for(int i = 0; getline(myfile, line); i++){
    for(int j = 0; j < line.length(); j++){
      switch(line[j]){
        case '0':
          break;
        case '1':
          blocks.push_back(new Block("Resources/yellow.png", j * blockSize, i * blockSize));
          break;
      }
    }
  }
  myfile.close();

}


void Game :: draw(){
  SDL_RenderClear(Game :: rend);
  for(Block* block : blocks){
    block->draw();
  }

  player->draw();
  SDL_RenderPresent(Game :: rend);
  SDL_Delay(1000 / 60);
}

void Game :: cleanUp(){
  SDL_DestroyRenderer(Game :: rend);
  SDL_DestroyWindow(win);
}

void Game :: checkKeyboard(){
  const Uint8* keys;
  SDL_PumpEvents();
  keys = SDL_GetKeyboardState(NULL);

  if (SDL_QuitRequested()){
    running = false;
  }

  if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
    player->setX(player->getX() - player->getXSpeed());
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
    player->setX(player->getX() + player->getXSpeed());
  }


}
