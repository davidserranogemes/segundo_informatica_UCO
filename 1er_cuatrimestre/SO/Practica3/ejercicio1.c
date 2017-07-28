#include <pthread.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#define NUM_CLI 3
#define NUM_PRO 5

pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond= PTHREAD_COND_INITIALIZER;
int camisetas[NUM_PRO]={95,82,120,55,82};

void * manejadorConsumidor(){
	int modelo;
	int cantidad;
	int i;
	modelo=rand()%5;
	cantidad=rand()%10;
	
	pthread_mutex_lock(&mtx);

	if(camisetas[modelo]>=cantidad){
		camisetas[modelo]-=cantidad;
	}
	
	
	
	printf("STOCK tras COMPRA:");
	
	for(i=0;i<NUM_PRO;i++){
		printf("[%i]",camisetas[i]);
	}
	printf("\n");
	
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

void *manejadorProductor(void *prod){//TIENES QUE PASARLE EL PRODUCTOR COMO PARAMETRO
	int cantidad;
	int i;
	int productor;

	cantidad=rand()%10+5;
	
	
	productor=(int) prod;

	pthread_mutex_lock(&mtx);
	camisetas[productor]= camisetas[productor]+cantidad;
	
	
	printf("STOCK tras restauración: ");
	for(i=0;i<NUM_PRO;i++){
		printf("[%i]",camisetas[i]);
	}
	printf("\n");
	pthread_mutex_unlock(&mtx);

	pthread_exit(NULL);

}

main(){
	pthread_t *pth_prod, *pth_cons;
	int p=0,c=0;
	int selec;
	int i;

	pth_prod=(pthread_t *)malloc(5*sizeof(pthread_t));
	pth_cons=(pthread_t *)malloc(3*sizeof(pthread_t));

	srand(time(NULL));

	while((p!=5)||(c!=3)){//selec==0 productor, selec==1 consumidor

		//decide que hilo va a usar, si un  cliente o un productor
		if(p==5){
			selec=1;
		}
		if(c==3){
			selec=0;
		}
		if((p!=5)&&(c!=3)){
			selec=rand()%2;
		}

		
		if(selec){//HILOS DE consumidores

			pthread_create(&pth_cons[c],NULL,manejadorConsumidor,NULL);
		}else{//HILOS DE productores

			pthread_create(&pth_prod[p],NULL,manejadorProductor,(void*) p);
		}
		
		//incrementa los consumidores/productores usados				
		if(selec){//selec==1 consumidores
			c++;
		}else{//selec==0 productore
			p++;
		}
		
	}

/*
for(c=0;c<3;c++){
	pthread_create(&pth_cons[c],NULL,manejadorConsumidor,NULL);
}
for(p=0;p<5;p++){
	pthread_create(&pth_prod[p],NULL,manejadorProductor,(void*) p);
	
}
*/
	pthread_join(pth_cons[0],NULL);
	pthread_join(pth_cons[1],NULL);
	pthread_join(pth_cons[2],NULL);

	pthread_join(pth_prod[0],NULL);
	pthread_join(pth_prod[1],NULL);
	pthread_join(pth_prod[2],NULL);
	pthread_join(pth_prod[3],NULL);
	pthread_join(pth_prod[4],NULL);

	pthread_mutex_destroy(&mtx);
	
	for(i=0;i<NUM_PRO;i++){
		printf("[%i]",camisetas[i]);
	}
	printf("\n");
}
