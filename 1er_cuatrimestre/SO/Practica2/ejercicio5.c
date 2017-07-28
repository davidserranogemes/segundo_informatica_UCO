#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void * leerFichero( char * cadena){
	char c;
	int * n;
	FILE *f;
	
	
	n=(int*)calloc(1,sizeof(int));
	*n=0;
	

	
	if((f=fopen(cadena,"r"))==NULL){
		printf("ERROR DE APERTURA DEL FICHERO\n");
		exit(EXIT_FAILURE);
	}
	while((c=getc(f))!=EOF){
		if(c=='\n'){
			(*n)++;
		}
	}
	fclose(f);
	printf("Se devueve el valor %i\n\n",*n);//DEPUR
	pthread_exit(n);
}

int main(int argc, char ** argv){

	int i;
	int suma=0;
	int *lineas;
	pthread_t *pth;

	if(argc<2){
		printf("Error de sintaxis, se requiere al menos un fichero");
		exit(-1);
	}
	else{		
		pth=(pthread_t *)malloc((argc-1)*sizeof(pthread_t));
		lineas=(int*)calloc(1,sizeof(int));
		
		
		for(i=1;i<argc;i++){
			pthread_create(&pth[i],NULL,(void*) leerFichero,argv[i]);
			printf("HILO %i creado.\n",i);//DEPUR
			usleep(500000);
		}
		
		for(i=1;i<argc;i++){
			*lineas=0;
			
			pthread_join(pth[i],(void**) &lineas);//Había un error l poner (void**) *lineas. ES &
									
			
			suma+=*lineas;
			

			printf("El numero del lineas del fichero %i es %i.\n",i,*lineas);
			}
		
		free(pth);		
		
		}
	printf("La suma de todas las lineas de los ficheros es: %i.\n",suma);
	}

		
	
