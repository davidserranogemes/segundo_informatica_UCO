FLAGS= -c -g -ansi -Wall
EXE= pGrafo
CC=g++


all: $(EXE)

pGrafo: Vertice.o pGrafo.o funciones.o Grafo.o
	$(CC) pGrafo.o funciones.o Grafo.o Vertice.o -o pGrafo
Vertice.o: Vertice.cpp Vertice.hpp VerticeInterfaz.hpp
	$(CC) Vertice.cpp $(FLAGS) -o Vertice.o
Grafo.o: Grafo.cpp Grafo.hpp Vertice.hpp VerticeInterfaz.hpp 
	$(CC) Grafo.cpp $(FLAGS) -o Grafo.o
funciones.o: funciones.cpp funciones.hpp Grafo.hpp Vertice.hpp VerticeInterfaz.hpp
	$(CC) funciones.cpp $(FLAGS) -o funciones.o
pGrafo.o: pGrafo.cpp funciones.hpp Grafo.hpp Vertice.hpp VerticeInterfaz.hpp
	$(CC) pGrafo.cpp $(FLAGS) -o pGrafo.o
clean: 
	rm *.o pGrafo -f
