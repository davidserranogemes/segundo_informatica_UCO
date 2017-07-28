#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <stdlib.h>

void * randomNumber(void * indice){
	int rNumber1, rNumber2,acum;
	rNumber1=rand()%10+1;
	rNumber2=rand()%10+1;
	printf("Soy el hilo %i y mis num. aleatorios son: %i y %i.\n",((int) indice)+1, rNumber1,rNumber2);
	acum=rNumber1+rNumber2;
	printf("Su suma es: %i \n", acum);
	pthread_exit((void*) acum);
}

int main (){
	int N=10;
	int i;
	int suma=0,acc;
	pthread_t tid[N];

	for(i=0;i<N;i++){
		pthread_create(&tid[i],NULL, (void*) randomNumber,(void*) i);
		pthread_join(tid[i],(void*) &acc);	
		suma+=acc;
		printf("La suma acumulada es: %i. acc=%i \n",suma,acc);

		}
}
	
