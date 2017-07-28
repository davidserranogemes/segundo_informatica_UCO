#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

main(){
pid_t pid;
int i;
int state;
int childpid;
for(i=0;i<10;i++){
	pid=fork();
	if(pid!=0){
		childpid=wait(&state);
		if(childpid>0){
			printf("Proceso hijo finalizado correctamente.\n");
		}else{
			printf("Error en la finalizacion del hijo.%d \n",childpid);}
		exit(-1);
	}
	if(pid==0){
		printf("El pid del hijo es: %d y el del padre es: %d.\n",getpid(),getppid());
	}
}
}
