#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP
#include <SDL2/SDL.h>
#include <vector>
class Mandelbrot {
    private:
        int width = 800;
        int height = 800;
        float xMin = -2.1;
        float xMax = 0.6;
        float yMin = -1.2;
        float yMax = 1.2;
        int maxIterations = 20;
    public:
        Mandelbrot(int width, int height,float xMin,float xMax,float yMin,float yMax,int maxIteration);
        std::vector<unsigned char> drawLine(int lineNumber);
        
};

#endif