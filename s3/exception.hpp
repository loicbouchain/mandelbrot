#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Exception : public std::exception{
   public :
   Exception();
   virtual const char* what() const throw();
    
   private:
   std::string msg;
};

#endif