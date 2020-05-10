#include "./SDLProgram.hpp"

SDLProgram::SDLProgram(int width, int height){
    this->width = width;
    this->height = height;
    if (SDL_Init( SDL_INIT_VIDEO ) < 0){
        std::cout << "SDL could not initialize: " << SDL_GetError() << std::endl;
    }
    else{
        SDL_Window* window = nullptr;
        SDL_CreateWindowAndRenderer(this->width, this->height, 0, &window, &this->renderer);
    }
}

void SDLProgram::loop(){
    if(this->renderer == nullptr){
        return;
    }
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            break;
        }
        this->display();
        SDL_RenderPresent(this->renderer); //Attente de la prochaine frame
    }
}

void SDLProgram::display(){

}

SDLProgram::~SDLProgram(){
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}