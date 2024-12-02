//
// Created by shimo on 01/12/2024.
//

#ifndef GAME_H
#define GAME_H
#include <SDL_rect.h>
#include <SDL_render.h>
#define NOT_FOUND -1
inline SDL_FRect zeroRect = {0,0,0,0};
inline int score = 0;
inline int lives = 3;
int checkCollisionSquare(SDL_FRect * rects , float centerX, float centerY , float radius);
void updateRects(SDL_FRect ** rects,int size, float centerX, float centerY , float radius);
int updateLives(float * centerY, float * centerX ,float radius);
bool checkGameOver();
#endif //GAME_H
