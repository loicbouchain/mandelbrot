#include <iostream>
#include <chrono>
#include "SDL2/SDL.h"
#include "./SDLProgram.hpp"
#include "./Mandelbrot.hpp"
#include "./SDLException.hpp"
#include <thread>
#include <vector>
void workerV2(SDLProgram &program,int lignedebut, int lignefin, Mandelbrot &mandelbrot,int num_worker,int height)
{
    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    for (int y = lignedebut; y < lignefin; y++)
    {
        program.updateLine(y, mandelbrot.drawLine(y));
        
    }
    int lignedebut2=(height/2) + lignedebut;
    int lignefin2=(height/2) + lignefin;
    for (int y = lignedebut2; y < lignefin2; y++)
    {
        program.updateLine(y, mandelbrot.drawLine(y));
        
    }
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

    // Display the total computation time
    std::cout
        << "Worker "<<num_worker
        << " Temps traitement : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count()
        << " millisecondes" << std::endl;
}

void worker(SDLProgram &program,int lignedebut, int lignefin, Mandelbrot &mandelbrot,int num_worker)
{
    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    for (int y = lignedebut; y < lignefin; y++)
    {
        program.updateLine(y, mandelbrot.drawLine(y));
        
    }
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

    // Display the total computation time
    std::cout
        << "Worker "<<num_worker
        << " Temps traitement : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count()
        << " millisecondes" << std::endl;


}
//faire random ?
// couper les lignes en plus de trahcnhes et les aoués auw workers genre couper en 10 et ah ouai mais non ^^ sino
// faire worker qui prend array des num de lignes, prendre des lignes de chaque tranches pour avoir un peu de tout

//couper mandelbrot en 2, w1 prend 125 prem du c1 et 125 prem c2 ...
void compute(SDLProgram &program, int height, Mandelbrot &mandelbrot, int nb_workers)
{
    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    std::thread arrayWorkers[nb_workers];
    int tranche = height/(nb_workers*2);
    for (int y = 0; y < nb_workers; y++)
    {
        int lignedebut = (tranche *y)+1;
        int lignefin = tranche*(y+1);
        arrayWorkers[y]=std::thread(workerV2, std::ref(program), lignedebut,lignefin, std::ref(mandelbrot),y,height);
        
        //arrayWorkers[y]=workerThread;
    }
    for (int y = 0; y < nb_workers; y++)
    {
        arrayWorkers[y].join();
    }
    

    
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

    // Display the total computation time
    std::cout
        << "le tout a fait "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count()
        << " milliseconds to compute the fractal." << std::endl;
}


int main(){

    // Initialize a mandelbrot object of given width and height
    int width = 1000;
    int height = 1000;
    int nb_worker=20;
    Mandelbrot mandelbrot(width,height,-2.1,0.6,-1.2,1.2,500);
    try{
        
        // Initialize a SDL Program
        SDLProgram program(width,height);
        /*
        // Get a time indicator at the start of the computation
        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();

        // Compute the Mandelbrot line by line
        for(int y = 0; y < height; y++){
            program.updateLine(y,mandelbrot.drawLine(y));
        }

        // Get a time indicator at the end of the computation
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

        // Display the total computation time
        std::cout 
        << "It took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count()
        << " milliseconds to compute the fractal." << std::endl;
        
        // Launch the render loop*/
        std::thread computeThread(compute, std::ref(program), height, std::ref(mandelbrot),nb_worker);
        computeThread.join();
        program.loop();

    }
    catch(SDLException& e){
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}