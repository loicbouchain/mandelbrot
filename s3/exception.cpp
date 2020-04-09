#include "./exception.hpp"

Exception::Exception(){
    this->msg = std::string("SDL Encontred an error : ") + std::string(SDL_GetError());
}
const char* Exception::what() const throw(){
  return this->msg.c_str();
}   