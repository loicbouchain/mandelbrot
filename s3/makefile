main.exe : main.o SDLProgram.o Exception.o Mandelbrot.o
	g++ -o main.exe main.o SDLProgram.o Exception.o Mandelbrot.o -lSDL2

main.o : main.cpp
	g++ -c main.cpp -o main.o -I/usr/include/SDL2

SDLProgram.o : SDLProgram.cpp
	g++ -c SDLProgram.cpp -I/usr/include/SDL2 -o SDLProgram.o

Exception.o : exception.cpp
	g++ -c exception.cpp -I/usr/include/SDL2 -o exception.o

Mandelbrot.o : Mandelbrot.cpp
	g++ -c Mandelbrot.cpp -I/usr/include/SDL2 -o Mandelbrot.o
	
clean : 
	rm *.o *.exe