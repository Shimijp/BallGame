//
// Created by shimon on 28/11/2024.
//

#include "SdlErrors.h"
void checkWindow(const SDL_Window * window) {
    if(window == nullptr) {
        printf("could not init window SDL error %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

}
void checkRenderer(const SDL_Renderer * renderer) {
    if(!renderer) {
        printf("error init the renderer , SDL_error: %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}
void SDLInitSafe() {
    //Check if the init was successful
    if(SDL_Init(SDL_INIT_VIDEO |SDL_INIT_TIMER)==-1) {
        printf("could not init sdl %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}
