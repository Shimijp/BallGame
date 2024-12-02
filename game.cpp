//
// Created by shimo on 01/12/2024.
//

#include "game.h"

#include <SDL_ttf.h>
#include <thread>
#include <unistd.h>

#include "Animations.h"

int checkCollisionSquare(SDL_FRect * rects , int size,float centerX, float centerY , float radius) {
    for (int i = 0; i < size; ++i) {
        float closestX = std::max(rects[i].x, std::min(centerX, rects[i].x + rects[i].w));
        float closestY = std::max(rects[i].y, std::min(centerY, rects[i].y + rects[i].h));

        float distanceX = centerX - closestX;
        float distanceY = centerY - closestY;

        float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
        if (distanceSquared <= (radius * radius)) {
            score++;
            return i; // Collision found
        }
    }
    return NOT_FOUND; // No collision found
}
void updateRects(SDL_FRect ** rects,int size, float centerX, float centerY , float radius)
{
   int  index = checkCollisionSquare((*rects),size, centerX,centerY, radius);
    if(index != NOT_FOUND) {
        (*rects)[index] = zeroRect;
    }
}
int updateLives(float * centerY, float * centerX ,float radius) {
    float barY =(HEIGHT/1.4);
    if((*centerY+radius) > (barY +2*HEIGHT/20.0)){
        lives--;

        *centerX = WIDTH/2.0f;
        *centerY = HEIGHT/2.0f;


        SDL_Delay(200);
        return 1;

    }
    return 0;
}
bool checkGameOver() {
    if(lives <= 0) {

        return true;
    }
    return false;
}
/*void renderGameOver(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color color = {255, 0, 0}; // Red color for "Game Over"
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Game Over!", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect destRect = {WIDTH / 4, HEIGHT / 3, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}*/