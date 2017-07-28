#include <sys/types.h>//Varias estructuras de datos, PID_T
#include <unistd.h>// PAra FORK
#include <stdio.h>

main(){
pid_t pid;
int i, status,N;
N=10;
int ERROR;
for(i=0;i<N;i++){//BUCLE que crea los procesos hijos en estrella
	pid=fork();
	
	if(pid==0){
		printf("El pid del hijo es: %d y el del padre %d. \n", getpid(),getppid());
		
		exit(-1);
		} 
	}//cierre for

if(pid!=0){//Solo para el proceso padre
	for(i=0;i<N;i++){
		if((ERROR=wait(&status))>0){
			printf("Proceso hijo finalizado correctamente.\n");
		}else{
			printf("Error en la finalizacion del hijo.%d \n",ERROR);
		}
	}
}
}
