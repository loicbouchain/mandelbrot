#include "./Mandelbrot.hpp"
#include <iostream>
using namespace std;
Mandelbrot::Mandelbrot(int width, int height,float xMin,float xMax,float yMin,float yMax,int maxIteration){
    this->width = width;
    this->height = height;
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
    this->maxIterations = maxIterations;
}
std::vector<unsigned char> Mandelbrot::drawLine(int lineNumber){
    std::vector<unsigned char> linePixels = std::vector<unsigned char>(this->width*4,0);
    int y = lineNumber;
    float zoomX = this->width/((float) this->xMax-this->xMin);
    float zoomY = this->height/((float) this->yMax-this->yMin);
    


    for ( int x = 0; x < this->width; x++)
    {
        float c_r = x /zoomX+xMin;
        float c_i = y /zoomY+yMin;
        float z_r =0;
        float z_i = 0;
        float i = 0;
        do{
            float tmp = z_r;
            z_r = z_r*z_r-z_i*z_i+c_r;
            z_i = 2*z_i*tmp+c_i;
            i=i+1;
        }
        while(z_r*z_r + z_i*z_i < 4 && i < this->maxIterations);

        if(i==this->maxIterations){
            linePixels[x*4+3]=255;
        }
        else                {
            linePixels[x*4]=(i*255)/this->maxIterations;
            
        }        
    }
    return linePixels;
       
    }
    


