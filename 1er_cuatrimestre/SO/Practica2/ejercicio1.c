#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <string.h>

void *ImprimirCaracter(void *caracteres){
int i;
char cadena[30];
strcpy(cadena,(char *) caracteres);

for(i=0;i<strlen(cadena);i++){
	putchar(cadena[i]);
	}
	putchar(' ');
return(NULL);
}
main(){
	
	pthread_t tid1, tid2;
	char hola[10]={"hola\0"};
	char mundo[10]={"mundo\0"};
	
/*
	pthread_create (&tid1, NULL, (void *) ImprimirCaracter, (void *) hola);
	pthread_create (&tid2, NULL, (void *) ImprimirCaracter, (void *) mundo);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

*/
	pthread_create (&tid1, NULL, (void *) ImprimirCaracter, (void *) hola);
	pthread_join(tid1,NULL);

	pthread_create (&tid2, NULL, (void *) ImprimirCaracter, (void *) mundo);
	pthread_join(tid2,NULL);
		
	printf("\nSe ha mostrado hola mundo.\n");
}
