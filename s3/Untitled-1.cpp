#include <iostream>
#include <string>

class DivisionByZero : public std::exception{
    public : 
    virtual const char* what() throw(){
        return "Division by zero !!!!!!";
    }
};
float div(float a,float b){
    
    if(b==0.0){
        throw DivisionByZero();
    }
    return a/b;
}

int main(){
    float a =5.0;
    float b =0.0;
    
    try{
       float c= div(a,b);
    }
    catch(DivisionByZero& e){
        std::cout<< e.what() << std::endl;
        return 1;
    }
//catch(...) ctach toutes les erreurs
// méthode() throw() <- mauvaise pratique
    return 0;
}