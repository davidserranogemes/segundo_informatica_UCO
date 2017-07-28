FLAGS= -c -g -ansi -Wall
EXE= pMonticulo
CC=g++

all: $(EXE)

pMonticulo:  Donante.o  MonticuloDonantes.o pMonticulo.o 
	$(CC) pMonticulo.o Donante.o MonticuloDonantes.o  -o pMonticulo

Donante.o: Donante.cpp Donante.hpp DonanteInterfaz.hpp
	$(CC) Donante.cpp $(FLAGS) -o Donante.o

MonticuloDonantes.o: MonticuloDonantes.cpp MonticuloDonantes.hpp Donante.hpp MonticuloDonantesInterfaz.hpp
	$(CC) MonticuloDonantes.cpp $(FLAGS) -o MonticuloDonantes.o

pMonticulo.o: pMonticulo.cpp Donante.hpp DonanteInterfaz.hpp MonticuloDonantes.hpp MonticuloDonantesInterfaz.hpp
	$(CC) pMonticulo.cpp $(FLAGS) -o pMonticulo.o

clean:
	rm *.o pMonticulo -f
