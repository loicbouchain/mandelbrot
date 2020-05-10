main.exe : main.o SDLProgram.o
	g++ -o main.exe main.o SDLProgram.o -lSDL2

main.o : main.cpp
	g++ -c main.cpp -o main.o -I/usr/include/SDL2

SDLProgram.o : SDLProgram.cpp
	g++ -c SDLProgram.cpp -I/usr/include/SDL2 -o SDLProgram.o

clean : 
	rm *.o *.exe