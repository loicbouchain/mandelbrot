#ifndef SDLPROGRAM_HPP
#define SDLPROGRAM_HPP
#include <SDL.h>
#include <iostream>

class SDLProgram {
    private:
        int width = 800;
        int height = 600;
        SDL_Renderer* renderer = nullptr;

    public:
        SDLProgram(int width, int height);
        void display();
        void loop();
        ~SDLProgram();
};

#endif