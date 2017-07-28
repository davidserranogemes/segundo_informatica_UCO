#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void * funcHilo(void * fichero){
	char ejec[40]={"gedit \0"};
	
	strcat(ejec,(char*) fichero);
	strcat(ejec," &");
	printf("La orden a ejecutar es: %s \n",ejec);

	system(ejec);
	printf("Se ha abierto el fichero.\n");
	pthread_exit(NULL);
}


int main(int argc, char ** argv){
	
	pthread_t pth1, pth2;
	
	char *gedit1, *gedit2;
	
	gedit1=argv[1];
	gedit2=argv[2];

	if(argc!=3){	
		printf("Error de sintaxis, introduzca: <nombre_programa> <nombre-fichero1> <nombre_fichero2>\n");
		exit(EXIT_FAILURE);
	}
	pthread_create(&pth1,NULL,(void*) funcHilo, (void *) gedit1);
	pthread_create(&pth2,NULL,(void*) funcHilo, (void *) gedit2);

	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);
	
	printf("Se han abierto ambos ficheros, se cierra el programa.\n");

	return 0;
}
	
	
	
	
