#include "funcion4.h"
#include <sys/types.h> //Para estructura pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>
#include <string.h>

main(int argc, char** argv){
	pid_t pid;
	int status,error;
	char * fichero;
	FILE *f;
	strcpy( fichero,argv[1]);

	if((f=fopen(fichero,"w"))==NULL){
		printf("ERROR en la apertura del fichero %s.\n",fichero);
		exit(-1);
		}
	else{
		pid=fork();
		if(pid==0){
			
			fputs("---------\n",f);
			sleep(1);
			fputs("---------\n",f);
			sleep(1);
			fputs("---------\n",f);
			exit(EXIT_SUCCESS);
		}else{
			fputs("+++++++++\n",f);
			sleep(1);
			fputs("+++++++++\n",f);
			sleep(1);
			fputs("+++++++++\n",f);
			wait(&status);
		}
		fclose(f);
		
		if((error=execlp("gedit","gedit",fichero,NULL))==-1){
			printf("ERROR de gedit al abrir el archivo %s\n.", fichero);
			exit(EXIT_FAILURE);
		}
		else{
			printf("Apertura del fichero %s correcta.\n", fichero);
		}
	}
}	
