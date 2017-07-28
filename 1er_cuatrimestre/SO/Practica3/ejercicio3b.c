#include <pthread.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int BUFFER[5]={1,1,1,0,0};
int N=3;

void * productor(){
	int i;
	int j;
	for(i=0;i<20;i++){
		
		pthread_mutex_lock(&mtx);
		
		while(N==5){
			pthread_cond_wait(&cond,&mtx);
		}
		BUFFER[N]=BUFFER[N]+1;
		
		printf("El BUFFER tras producir:");
		for(j=0;j<5;j++){
			printf("[%d]",BUFFER[j]);
		}
			
		printf("    %d  \n",N);
		N++;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mtx);
	}
		
			
}






void * consumidor(){
	int i;
	int j;
	
	for(i=0;i<20;i++){

		pthread_mutex_lock(&mtx);
		while(N==0){
			pthread_cond_wait(&cond,&mtx);
		}
	
		BUFFER[N-1]=BUFFER[N-1]-1;
	
	printf("El BUFFER tras consumir:");
		for(j=0;j<5;j++){
			printf("[%d]",BUFFER[j]);
		}
		printf("\n");
		N--;
		pthread_cond_signal(&cond);
		
		pthread_mutex_unlock(&mtx);

	}
}

main(){

pthread_t pthcons, pthprod;
int j;
	pthread_create(&pthcons,NULL,consumidor,NULL);
	pthread_create(&pthprod,NULL,productor,NULL);

	pthread_join(pthcons,NULL);
	pthread_join(pthprod,NULL);

	for(j=0;j<5;j++){
		printf("[%d]",BUFFER[j]);
	}
	printf("\n");
		
	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&cond);
}
