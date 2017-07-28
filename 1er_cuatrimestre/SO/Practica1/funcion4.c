#include "funcion4.h"

#include <sys/types.h> //Para estructura pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>


void HijoCalcuadora(char ** cad){
int error;	

	if((error=(execlp(cad[1],cad[1],NULL)))==-1){
		printf("ERROR\n");
		exit(-1);
	}else{
		printf("Conseguido calculadora\n");
		exit(1);
	}
	
}
void HijoGedit(char **cad){


	execvp(cad[2], &cad[2]);
	exit(1);
}

