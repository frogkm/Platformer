#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
#include "Values.h"

class GameObject {

  protected:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;

  public:
    GameObject(SDL_Renderer* rend, SDL_Surface* surface, int x, int y);
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);
    void setPos(int x, int y);
    int getX();
    int getY();
    int getW();
    int getH();
    SDL_Rect* getRect();
    SDL_Texture* getTexture();
    void draw(SDL_Renderer* rend);
};

#endif
