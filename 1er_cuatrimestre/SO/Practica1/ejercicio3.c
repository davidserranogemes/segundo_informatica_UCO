#include <sys/types.h> //Para estructura pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

main(){
	pid_t pid1,pid2,pid3,pid4,pid5;

	int digito,suma,status;
	suma=0;
	pid1=fork();
	if(pid1==0){
		digito=getpid()%10;
		printf("Soy un hijo 1 y mi ultima cifra es: %d\n",(getpid()%10));
		exit(digito);
	}
	pid2=fork();
	
	if(pid2==0){
		pid3=fork();
	
		if(pid3==0){
			digito=getpid()%10;
			printf("Soy un nieto 3 y mi ultima cifra es: %d\n",(getpid()%10));
			exit(digito);
		}
		pid4=fork();
		if(pid4==0){
			pid5=fork();
			if(pid5==0){
				digito=getpid()%10;
				printf("Soy un bisnieto 5 y mi ultima cifra es: %d\n",(getpid()%10));
				exit(digito);
			}
		while(wait(&status)!=-1){
		suma=suma+WEXITSTATUS(status);
		
		}
		digito=suma+getpid()%10;
		printf("Soy un nieto 4 y mi ultima cifra es: %d\n",(getpid()%10));
		exit(digito);
		}
	while(wait(&status)!=-1){
		suma=suma+WEXITSTATUS(status);
		
	}
	digito=suma+getpid()%10;
	printf("Soy un hijo 2 y mi ultima cifra es: %d\n",(getpid()%10));
	exit(digito);
	}

	while(wait(&status)!=-1){
		suma=suma+WEXITSTATUS(status);
		
	}
	suma=suma+getpid()%10;
	printf("Soy el proceso padre y mi ultimo digito es: %d\n",(getpid()%10));
	printf("La suma de los últimos numeros de cada hijo  y del padre es: %d\n",suma);
}
