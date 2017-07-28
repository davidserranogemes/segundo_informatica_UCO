OBJS=pPolinomio pMonomio
CC=g++
FLAGS=-lm -g

all: $(OBJS)

pPolinomio: Polinomio.o Monomio.o pPolinomio.cpp
	$(CC) Polinomio.o Monomio.o pPolinomio.cpp -o pPolinomio $(FLAGS)

pMonomio: Monomio.o pMonomio.cpp
	$(CC) Monomio.o pMonomio.cpp -o pMonomio $(FLAGS)

Monomio.o: Monomio.cpp Monomio.hpp MonomioInterfaz.hpp
	$(CC) Monomio.cpp -c

Polinomio.o: Polinomio.cpp Polinomio.hpp Monomio.hpp PolinomioInterfaz.hpp
	$(CC) Polinomio.cpp -c -lm


clean:
	rm pPolinomio pMonomio *.o 
