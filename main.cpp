//
// Created by shimon on 28/11/2024.
//


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cmath>
#include "SdlErrors.h"
#include "keyboardInput.h"
#include "Animations.h"
#include "game.h"
float radius = 10.0f;
float yPos = 0.1;
float centerX =WIDTH/2.0f;
float centerY = HEIGHT/2.0f;
float xVelocity = 2.0f; // Horizontal speed
float yVelocity = 2.0f;
int main(int argc, char ** argv) {

    float xPos = 0.0;
    //Window ptr
    SDL_Window * window = NULL;

    SDL_Renderer * renderer =NULL;

    SDLInitSafe();



    //Creates the actual window
    window = SDL_CreateWindow("my game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED
        ,WIDTH
        ,HEIGHT,
        SDL_WINDOW_OPENGL);



    checkWindow(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    SDL_Surface * surface = nullptr;
    checkRenderer(renderer);

    int amount = 10;
    SDL_FRect * rect = get_rect(amount, 0.0 , 2.0f, HEIGHT/8.0f);
    SDL_FRect *rect2 = get_rect(amount,0.0,2.0f+HEIGHT/8.0f+1,HEIGHT/8.0f);
    SDL_FRect * rect3 = get_rect(amount,0.0,2.0f+2*(HEIGHT/8.0f)+1,HEIGHT/8.0f);

    bool quit = false;
    SDL_Event event;
    while(!quit) {
        while(SDL_PollEvent(&event)) {

            moveBar(event,&xPos);

            quit =  (event.type ==SDL_QUIT);



        }

        drawBar(renderer,xPos);

        drawBall(renderer,centerX,centerY,radius);

        updateBall(radius,&centerX,&centerY,&xVelocity,&yVelocity,xPos);

        if(updateLives(&centerY,&centerX, radius) == true) {
            SDL_Delay(2000);
        }



        SDL_SetRenderDrawColor(renderer,0, 150, 255,255);

        SDL_RenderFillRectsF(renderer,rect,amount+2);

        SDL_SetRenderDrawColor(renderer,255, 165, 0,255);

        SDL_RenderFillRectsF(renderer,rect2,amount+2);

        SDL_SetRenderDrawColor(renderer,0, 200, 0,255);

        SDL_RenderFillRectsF(renderer,rect3,amount+2);

        updateRects(&rect,amount+2,centerX, centerY , radius );

        updateRects(&rect2,amount+2,centerX, centerY , radius );

        updateRects(&rect3,amount+2,centerX, centerY , radius );

        quit = quit | checkGameOver();


        //quit = checkGameOver();

        SDL_RenderPresent(renderer);

        SDL_Delay(16);

    }
    /*char * s = "Youre score is: \n";
    sprintf(s,"%d", score);*/


    delete [] rect;
    delete [] rect2;
    delete [] rect3;
    SDL_RenderClear(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    atexit(SDL_Quit);
    return 0;
}