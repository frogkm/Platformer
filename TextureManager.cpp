#include "TextureManager.h"

SDL_Texture* TextureManager :: makeTexture(char* filePath){
  return(SDL_CreateTextureFromSurface(Game :: rend, IMG_Load(filePath)));
}
