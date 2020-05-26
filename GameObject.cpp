#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject :: GameObject(char* filePath, int x, int y){

  texture = TextureManager :: makeTexture(filePath);
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  rect.x = x;
  rect.y = y;

}

void GameObject :: setX(int x){
  rect.x = x;
}
void GameObject :: setY(int y){
  rect.y = y;
}
void GameObject :: setW(int w){
  rect.w = w;
}
void GameObject :: setH(int h){
  rect.h = h;
}
void GameObject :: setPos(int x, int y){
  setX(x);
  setY(y);
}
int GameObject :: getX(){
  return rect.x;
}
int GameObject :: getY(){
  return rect.y;
}
int GameObject :: getW(){
  return rect.w;
}
int GameObject :: getH(){
  return rect.h;
}
SDL_Rect* GameObject :: getRect(){
  return &rect;
}
SDL_Texture* GameObject :: getTexture(){
  return texture;
}
void GameObject :: draw(){
  SDL_RenderCopy(Game :: rend, texture, NULL, &rect);
}
