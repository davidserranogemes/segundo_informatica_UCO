#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define CLAVE (key_t) 616

int main(int argc, char ** argv){

	pid_t *childpids;
	int numChild,i;
	int ownPid;
	int IdMemory;
	int * Memory;
	int status;
	if(argc!=2){
		printf("Syntax Error: Expected ./ejercicio2 -numOfChild-\n");
		exit(EXIT_FAILURE);
	}
	
	numChild=atoi(argv[1]);

	if((childpids=malloc(numChild*sizeof(pid_t)))==NULL){
		printf("Memory creation error.\n");
		exit(EXIT_FAILURE);
		}

	for(i=0;i<numChild;i++){
		ownPid=fork();
		if(ownPid==-1){
			printf("ERROR on pid_t fork() function.\n");
			if(errno==EAGAIN){
				printf("System lack of resources to create a new child process.Max number of child reached\n");
				exit(EXIT_FAILURE);
			}else{
				if(errno==ENOMEM){
					printf("System lack of memory to create more process.\n");
					exit(EXIT_FAILURE);
				}else{
					printf("Undefined Error\n");
					exit(EXIT_FAILURE);
				}
			}
		}
				
		if(ownPid==0){
			break;
		}
		
	}

	if((IdMemory=shmget(CLAVE, sizeof(int),0777 | IPC_CREAT))==-1){
		printf("Shared memory error.\n");
		exit(-1);
		//CONTROL DE ERRORES DE ERRNO incluir luego
		if(errno==EACCES){
			}
	}
	
	if((Memory = shmat(IdMemory, (char*) 0, 0))==NULL){
		printf("Allocation memory error.\n");
		exit(EXIT_FAILURE);
		//CONTROL DE ERRORES DE ERRNO incluir luego
	}

	if(ownPid==0){
		for(i=0;i<100;i++){
			Memory[0]++;
		}
		exit(EXIT_SUCCESS);
	}
	else{
		while(wait(&status)!=-1);
		printf("Memory=%i\n",Memory[0]);
		shmdt ((char *)Memory);
		shmctl (IdMemory, IPC_RMID, (struct shmid_ds *)NULL);		
		return(0);
	}
}

