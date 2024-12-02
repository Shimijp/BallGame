//
// Created by shimo on 28/11/2024.
//

#include "Animations.h"
void drawBar(SDL_Renderer * renderer , float xPos) {
    SDL_FRect rect = {(WIDTH/2.5f)+xPos, HEIGHT/1.4 , WIDTH/5.0 ,HEIGHT/20.0};

    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    SDL_RenderFillRectF(renderer, &rect);
}
void drawBall(SDL_Renderer * renderer,float centerX, float centerY,float  radius) {

    float delta = 0.01f;
    for(float i = 0 ; i <= 2*M_PI; i += delta) {
        float x = (radius * cosf(i))+centerX;
        float y = (radius * sinf(i))+centerY;
        SDL_RenderDrawLineF(renderer,x,y, centerX,centerY);

    }

}


void updateBall(float radius,float * centerX, float * centerY,float * xVelocity, float * yVelocity,float xPos) {
    *centerX += *xVelocity;
    *centerY += *yVelocity;

    // Ball Collision with Screen Edges
    if (*centerX - radius <= 0 || *centerX + radius >= WIDTH) {
        *xVelocity = - *xVelocity; // Reverse horizontal velocity
    }
    if (*centerY - radius <= 0 || *centerY + radius >= HEIGHT ){
        *yVelocity = -*yVelocity; // Reverse vertical velocity
    }
    if(*centerX - radius >= (WIDTH/2.5f)+xPos &&
        *centerX- radius <=(WIDTH/2.5f)+ (WIDTH/5.0f)+xPos
        && *centerY + radius>= HEIGHT/1.4f ){
        *yVelocity = -*yVelocity;
        }
}
SDL_FRect * get_rect(int amount, float xBegin , float yBegin, float size) {
    float pointAmount = WIDTH/(amount+1);
    SDL_FRect * rect = (SDL_FRect*)malloc((amount+1)*sizeof(SDL_Rect));
    for(int i = 0; i <= amount; i++) {
        rect[i] = {(i+0.08f)*pointAmount, yBegin, pointAmount-2 , size };
    }

    return rect;
}