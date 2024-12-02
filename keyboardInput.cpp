//
// Created by shimon on 28/11/2024.
//

#include "keyboardInput.h"
void moveBar(SDL_Event &event, float *xPos ) {

        switch(event.key.keysym.sym) {
            case SDLK_RIGHT:
                if(((800/5.0f)+*xPos+(800/2.5f)) <= 800) {
                    *xPos += 5.0;
                }

            break;
            case SDLK_LEFT:
                if(((800/2.5f)+*xPos) >= 0) {
                    *xPos -= 5.0;
                }

            break;
            default:
                break;
        }

}
