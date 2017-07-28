#define N 5
#define IZQ (i-1)%N
#define DER (i+1)%N
#define PENSANDO 0
#define HAMBRIENTO 1
#define COMIENDO 2

#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

int estado[N];
sem_t exmut;
sem_t s[N];

void *filosofo(void *i);
void coger_tenedores(int i);
void dejar_tenedores(int i);
void prueba (int i);
void comer();
void pensar();

main(){
	int i;
	pthread_t filosofos[N];

	sem_init(&exmut,0,1);
	for(i=0;i<N;i++){
		sem_init(&s[i],0,1);
		}
	for(i=0;i<N;i++){
		pthread_create(&filosofos[i],NULL,filosofo, (void *) i);
	}
	for(i=0;i<N;i++){
		pthread_join(filosofos[i],NULL);	
	}
	
}



void * filosofo(void * i){
	int j;
	j=(int) i;
	while(1){
		pensar();
		coger_tenedores(j);
		comer(j);
		dejar_tenedores(j);
	}
}

void coger_tenedores(int i){
	sem_wait(&exmut);
	estado[i]=HAMBRIENTO;
	prueba(i);
	sem_post(&exmut);
	wait(&s[i]);
}

void dejar_tenedores(int i){
	sem_wait(&exmut);
	estado[i]=PENSANDO;
	prueba(IZQ);
	prueba(DER);
	sem_post(&exmut);
}

void prueba (int i){
	if((estado[i] == HAMBRIENTO) && (estado[IZQ]!=COMIENDO) &&(estado[DER] != COMIENDO)){
		estado[i]= COMIENDO;
		
		sem_post(&s[i]);
	}
}

void pensar(){
	usleep(rand()%2000000+500000);
	}
void comer(int i){
	printf("El filosofo %i esta comiendo.\n",i);
}
