#include "Game.h"

Game :: Game() {
  init();
  while(running){
    loop();
  }
  cleanUp();
}

void Game :: init(){
  win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sW, sH, 0);
  rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  running = true;
  populateBlocks();
  player = new Player(rend, IMG_Load(const_cast<char*>("Resources/Player.png")), 0, 0);
  player->setPos(sW / 2 - player->getW() / 2, sH - player->getH());

}

void Game :: loop(){
  checkKeyboard();
  checkCollision();
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
          blocks.push_back(new Block(rend, IMG_Load(const_cast<char*>("Resources/yellow.png")), j * blockSize, i * blockSize));
          break;
      }
    }
  }
  myfile.close();

}

void Game :: checkCollision(){

}

void Game :: draw(){
  SDL_RenderClear(rend);
  for(Block* block : blocks){
    block->draw(rend);
  }

  player->draw(rend);
  SDL_RenderPresent(rend);
  SDL_Delay(1000 / 60);
}

void Game :: cleanUp(){
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
}

void Game :: checkKeyboard(){
  const Uint8* keys;
  SDL_PumpEvents();
  keys = SDL_GetKeyboardState(NULL);

  if (SDL_QuitRequested()){
    running = false;
  }
  /*
  if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
    player->setX(player->getX() - player->getSpeed());
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
    player->setX(player->getX() + player->getSpeed());
  }
  */

}
