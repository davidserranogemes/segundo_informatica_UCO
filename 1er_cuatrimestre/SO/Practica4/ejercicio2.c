#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>


#define CLAVE (key_t) 616
#define CLAVE_SEM (key_t) 617
	
	

int main(int argc, char ** argv){

	pid_t *childpids;
	int numChild,i;
	int ownPid=1;
	int IdMemory;
	int IdMutex;
	int status;
	int Niter;
	sem_t *mutex;
	int * Memory;

	if(argc!=3){
		printf("Syntax Error: Expected ./ejercicio2 -numOfChild- -NumITER-\n");
		exit(EXIT_FAILURE);
	}
	numChild=atoi(argv[1]);
	Niter=atoi(argv[2]);

	if((IdMutex=shmget(CLAVE_SEM, sizeof(sem_t),0777 | IPC_CREAT))==-1){
		printf("Shared memory error.\n");
		exit(-1);
		//CONTROL DE ERRORES DE ERRNO incluir luego
		if(errno==EACCES){
			}
	}
	
	if((mutex = shmat(IdMutex, (char*) 0, 0))==NULL){
		printf("Allocation memory error.\n");
		exit(EXIT_FAILURE);
		//CONTROL DE ERRORES DE ERRNO incluir luego
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
	
	if((childpids=malloc(numChild*sizeof(pid_t)))==NULL){
		printf("Memory creation error.\n");
		exit(EXIT_FAILURE);
		}

	*Memory=0;
	sem_init(mutex,1,1);

	for(i=0;i<numChild;i++){
			
		ownPid=fork();
		if(ownPid==0){	

			for(i=0;i<Niter;i++){
				sem_wait(mutex);
				(*Memory)++;
				printf("Estoy yo aqui, incrementando: %i, en mi giro %i.\n",*Memory,i);
				sem_post(mutex);	
			}
			shmdt ((char *)Memory);
			shmdt((char *) mutex);
	
			exit(EXIT_SUCCESS);

		}
		else if(ownPid==-1){
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
				
	}

	while(wait(&status)!=-1){
		printf("Hijo terminado\n");
	}

	printf("Memory=%i\n",*Memory);

	shmdt ((char *)Memory);
	shmdt((char *) mutex);
	shmctl (IdMutex, IPC_RMID, (struct shmid_ds *) NULL);
	shmctl (IdMemory, IPC_RMID, (struct shmid_ds *)NULL);		
	free(childpids);
	return(0);
	
}

