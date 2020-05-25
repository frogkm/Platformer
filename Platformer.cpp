#include "Game.h"

int main()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      printf("error initializing SDL: %s\n", SDL_GetError());
  }
  TTF_Init();
  Game* game = new Game();
  TTF_Quit();
  SDL_Quit();
  return 0;
}
