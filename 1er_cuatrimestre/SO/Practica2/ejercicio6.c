#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct param{
	int indice;
	int *vectorCol;
	int *vectorMatriz;
};


void * productoVectores( struct param * parametros){
	int * n;
	int i, acc;
	n=(int*)calloc(1,sizeof(int));

	for(i=0;i<3;i++){
		acc=(parametros->vectorCol[i])*(parametros->vectorMatriz[i]);
		*n=*n+acc;
	}
	printf("El valor devuelto por el hilo %i es: %i\n",parametros->indice,*n);
	
	pthread_exit(n);
}
main(){
	struct param *parametros;
	struct param aux;
	int matriz[3][3]={{3,-1,8},{3,0,2},{4,-1,0}};
	int vector[3]={1,-1,2};
	int i;
	int * acc;
	int result[3];
	pthread_t pth[3];

	parametros=&aux;

	for(i=0;i<3;i++){
		parametros->indice=i;
		parametros->vectorCol=vector;
		parametros->vectorMatriz=matriz[i];
	
		pthread_create(&pth[i],NULL,(void *) productoVectores, parametros);
		usleep(500);	
	}
	
	for(i=0;i<3;i++){
		pthread_join(pth[i], (void**) &acc);
		result[i]=*acc;
	
	printf("[%i]",result[i]);

}
	printf("\n");
}
