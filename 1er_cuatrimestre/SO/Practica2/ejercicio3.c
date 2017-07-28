#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define N 10
struct sum{
	int V[N];
	int init;
	int end;
};

void *sumaVector(void *tec){
	int inicio=((struct sum*)tec)->init;
	int final=((struct sum*)tec)->end;
	int vector[N], z;
	int *suma;
	suma=calloc(1,sizeof(int));
	for(z=0;z<N;z++){
		vector[z]= ((struct sum *)tec)->V[z];	
	}
	
	for(z=inicio;z<final;z++){
		*suma+=vector[z];
	}
	pthread_exit((void *) suma);
}
		
		

int main(int argc,char**argv){
	int i,j, num_hilos;
	int suma=0;
	int *acc;
	int sumat=0;
	struct sum tec;
	pthread_t pth[N];
	
	if(argc!=2){
		printf("Error de sintaxis. Debe escribir:\n./<nombrejecutable> <numero de valores del vector que quiero sumar>\n");
		exit(EXIT_FAILURE);
	}
	num_hilos=atoi(argv[1]);

	if((num_hilos>N)||(num_hilos<1)){
		printf("Error de sintaxis. Debe escribir:\n./<nombrejecutable> <numero de valores del vector que quiero sumar entre 1 y 10>\n");
		exit(EXIT_FAILURE);
	}
	tec.init=0;
	tec.end=N/num_hilos;

	srand(time(NULL));
	
	for(i=0;i<N;i++){
		tec.V[i]=rand()%10;
	}
	
	for(i=0,j=1;i<num_hilos;i++,j++){
		pthread_create(&pth[i],NULL,(void *) sumaVector,(void *) &tec);
		usleep(500);
		tec.init+=N/num_hilos;

		if(j!=(num_hilos-1)){
			tec.end+=N/num_hilos;
		}else{	
			tec.end=N;}
	
	}
	system("clear");

	for(i=0;i<num_hilos;i++){
		if((pthread_join(pth[i],(void **) &acc))!=0){
			printf("ERROR\n");
			exit(-1);}
		suma+= *acc;
	}
	
	for(i=0;i<N;i++){
		sumat=sumat+tec.V[i];
		//printf("[%d]",tec.V[i]);//DEPUR, muestra el vector
	}
	printf("\n");
	printf("La suma normal es: %d y la acum. por hilos es: %d.\n",sumat,suma);
return(0);
}
