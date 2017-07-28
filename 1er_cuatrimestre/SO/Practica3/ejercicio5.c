#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define CICLOS 30

sem_t mutex;
int *BUFFER;
int consume;
int llena;


void * productor(void *tamBUFFER){
	int *tam2,tam,i;
	tam2=(int*) tamBUFFER;
	tam=*tam2;
	tam--;


	while(1){	
		sem_wait(&mutex);
		if(BUFFER[llena]==0){
			BUFFER[llena]=1;
			llena++;
			llena=llena%tam;
			printf("Lleno: ");
			for(i=0;i<tam;i++){
				printf("[%i]",BUFFER[i]);
			}
			//usleep(500000);
			printf("\n");
			
		}
		sem_post(&mutex);
	}		

}


void * consumidor(void *tamBUFFER){
	int *tam2,tam,i;
	tam2=(int*) tamBUFFER;
	tam=*tam2;
	tam--;


	while(1){	
		sem_wait(&mutex);
		if(BUFFER[consume]==1){
			BUFFER[consume]=0;
			consume++;
			consume=consume%tam;
			printf("Consumo: ");
			for(i=0;i<tam;i++){
				printf("[%i]",BUFFER[i]);
			}
			printf("\n");
			//usleep(500000);
		}
		sem_post(&mutex);
	}		


}




main(int argc, char**argv){
	int tamBUFFER;
	pthread_t prod, cons;
	

	if(argc!=2){
		printf("Syntax ERROR:\nExpected ./ejercicio5 tamBUFFER(int)\n");
		exit(EXIT_FAILURE);
	}
		

	tamBUFFER=atoi(argv[1]);

	sem_init(&mutex,0,1);

	BUFFER=calloc(tamBUFFER,sizeof(int));
	if(BUFFER==NULL){
		printf("No se puede inicializar la memoria\n");
	}
	llena=0;
	consume=0;

	pthread_create(&prod, NULL, productor,(void *) &tamBUFFER);
	pthread_create(&cons, NULL, consumidor,(void *) &tamBUFFER);

	pthread_join(prod,NULL);
	pthread_join(cons,NULL);

	free(BUFFER);

}








































