#include <pthread.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct AUX{

	char nombreFichero[30];
	int indice;
	int maxwriter;
};

//VARIABLES GLOBALES
int END=0;
int WRITER;
char BUFFER[1024];

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtx2=PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;





void * leeFichero(void * parametros){//Escribe en el BUFFER

FILE * f;
int i;
int DEPUR=0;
char aux[1024];
struct AUX *aux1;

	aux1= (struct AUX *) parametros;
	
	
	if((f=fopen(aux1->nombreFichero,"r"))==NULL){
		printf("El fichero no existe, introduzca un fichero real.\n");
		exit(EXIT_FAILURE);
		}



	
	while((fgets(aux,1024,f))!=NULL){
		DEPUR++;
		
		pthread_mutex_lock(&mtx2);
	
		WRITER=0;

		pthread_mutex_unlock(&mtx2);
		pthread_mutex_lock(&mtx);
		
		strcpy(BUFFER,aux);

		printf("Se ha leido una linea del fichero:\n%s y se ha copiado en el BUFFER.\n",BUFFER);//DEPUR
		pthread_mutex_unlock(&mtx);

		for(i=0;i<aux1->maxwriter;i++){
			pthread_cond_signal(&cond);
		}

		pthread_cond_wait(&cond2,&mtx2);
		pthread_mutex_unlock(&mtx2);
		printf("LLEGA LA SEÑAL,%i. END=%i\n\n",DEPUR,END);

	}
	pthread_mutex_lock(&mtx);
	END=1;
	pthread_mutex_unlock(&mtx);
	for(i=0;i<aux1->maxwriter;i++){
			pthread_cond_signal(&cond);
	}
	printf("FIN del fichero");//DEPUR
	fclose(f);
	pthread_exit(NULL);
}


void *escribeFichero(void * parametros){//Lee del BUFFER

FILE *f;
struct AUX *aux1;
struct AUX aux;
char ind[5];

	aux1= (struct AUX *) parametros;
	aux.indice=aux1->indice;
	strcpy(aux.nombreFichero,aux1->nombreFichero);

	sprintf(ind, "%i", aux.indice);
	strcat(aux.nombreFichero,ind);

	if((f=fopen(aux.nombreFichero,"w"))==NULL){
		printf("ERROR en la creacion del fichero");
	}


	while(1){
		pthread_cond_wait(&cond,&mtx);
		pthread_mutex_unlock(&mtx);

	
		if(END){
			pthread_mutex_unlock(&mtx);
			break;

		}else{
			fputs(BUFFER,f);
			usleep(500);
			pthread_mutex_lock(&mtx2);
			WRITER++;		
		
			if(WRITER==aux1->maxwriter){//Comprueba si todos los escritores han hecho su trabajo, si lo han echo, desbloquea al lector.
				printf("Enviando señal.\n");
				pthread_cond_signal(&cond2);
				
				pthread_mutex_unlock(&mtx2);
	
			}else{
				pthread_mutex_unlock(&mtx2);
			}
		}
	}
	fclose(f);
	pthread_exit(NULL);
}
	
main(int argc, char **argv){

	if(argc!=3){
		printf("Syntax ERROR. Expected: ./program_name file_name numer_of_copies.\n");
		exit(EXIT_FAILURE);
		}

	pthread_t *writer;
	pthread_t reader;

	int i, numFiles;
	
		struct AUX param;
		param.indice=0;
		strcpy(param.nombreFichero, argv[1]);

	WRITER=0;//Con otro valor entre 1 y 4 incluindos se bloquea

	numFiles=atoi(argv[2]);
	writer=malloc(numFiles*sizeof(pthread_t));
	param.maxwriter=numFiles;

		

		for(i=0;i<numFiles;i++){
			param.indice=i;
			pthread_create(&writer[i],NULL,escribeFichero, &param);
			//printf("\nSe ha creado el hilo escritor %i con nombre %s\n",param.indice,param.nombreFichero);
			usleep(50000);
		}
		usleep(100000);
		pthread_create(&reader,NULL,leeFichero, &param);

		pthread_join(reader,NULL);
		
		for(i=0;i<numFiles;i++){
			pthread_join(writer[i],NULL);
		}	

}


























