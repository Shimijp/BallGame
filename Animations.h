//
// Created by shimo on 28/11/2024.
//

#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#define WIDTH 800
#define HEIGHT 600
#include <SDL2/SDL.h>
void drawBar(SDL_Renderer * renderer , float xPos);
void drawBall(SDL_Renderer * renderer,float centerX, float centerY,float  radius);
void updateBall(float radius,float * centerX, float * centerY,
    float * xVelocity, float * yVelocity, float xPos);
SDL_FRect * get_rect(int amount, float xBegin , float yBegin, float size);
#endif //ANIMATIONS_H
