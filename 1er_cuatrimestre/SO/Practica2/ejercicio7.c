#include <pthread.h>
#include <stdio.h>

long GLOBAL;

void * incrementarGlobal(){
	long i;
	for(i=0;i<30000;i++){
		GLOBAL++;
	}
	pthread_exit(NULL);
	}
main(){
	pthread_t pth[10];
	int i;
	
	for(i=0;i<10;i++){
		pthread_create(&pth[i],NULL,(void *) incrementarGlobal,NULL);
	}
	for(i=0;i<10;i++){
		pthread_join(pth[i],NULL);
	}
	printf("GLOBAL=%ld\n",GLOBAL);
}
