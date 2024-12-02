//
// Created by shimo on 28/11/2024.
//

#ifndef SDLERRORS_H
#define SDLERRORS_H
#include <SDL2/SDL.h>
#include <iostream>

void checkWindow(const SDL_Window * window);
void checkRenderer(const SDL_Renderer * renderer);
void SDLInitSafe();
#endif //SDLERRORS_H
