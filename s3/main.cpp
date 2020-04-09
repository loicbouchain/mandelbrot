#include "./SDLProgram.hpp"
#include "./Mandelbrot.hpp"
#include "./exception.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>
void worker_thread(Mandelbrot &mandelbrot, SDLProgram &program, int y){
    program.updateLine(y,mandelbrot.drawLine(y));
   
}
int main(){

    int width =1000;
    int height=800;
    Mandelbrot mandelbrot(width,height,-2.1,0.6,-1.2,1.2,100);
    try{
        SDLProgram program(width,height);
        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
         for(int y =0; y< 800; y++){
             worker_thread(mandelbrot,program,y);
             program.loop2();
        }
       
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_begin).count() << std::endl;
        program.loop();
    
    }
    catch(Exception& a){
        std::cout << a.what() << std::endl;
        return 1;
        }
    return 0;
}
