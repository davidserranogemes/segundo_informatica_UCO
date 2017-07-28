.PHONY: clean dist

CC = gcc
CFLAGS = -Wall -g
INCLUDES = #-I.
LFLAGS = #-L.
LIBS = -lrt #-lpthread

MAIN = ejercicio1 ejercicio2 ejercicio3 ejercicio4-cliente ejercicio4-servidor

all:    $(MAIN)
	@echo  Terminado

%:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) $<  -o $@

ejercicio4-servidor:	ejercicio4-servidor.c common.h
		$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS) 

ejercicio4-cliente:	ejercicio4-cliente.c common.h
		$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS) 

ejercicio3:	ejercicio3.c
		$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS) 
ejercicio2:	ejercicio2.c
		$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS) 
ejercicio1:	ejercicio1.c
		$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS) 

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf pas-practica3.tar.gz *.c Makefile htdocs/*

