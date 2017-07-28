#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <mqueue.h>
#include <sys/wait.h>
#include <errno.h> //Control de errores
#include <string.h> //Para la funcion strerror()

int main() {
	
	int fildes[2];
	int status,flag;
	int twait;
	int i, message;
	ssize_t nbytes;
	const int BSIZE=100;
	char buf[BSIZE];
	pid_t rf;
	FILE *f;



	f=fopen("ejercicio3.txt","a");
	if(f==NULL){
		printf("ERROR, file cant be opened.\n");
		abort();
	}
	fprintf(f,"------------------%s----------------\n",getenv("USER"));
	fflush(f);
	status=pipe(fildes);
	if(status==-1){
		printf("Error al crear la tuberia.\n");
	}
	srand(time(NULL));



	rf = fork();

	switch (rf){
		// Error
		case -1:
			printf ("No he podido crear el proceso hijo \n");
			exit(1);
				
		case 0:	// Hijo, lee los numeros de la pipe
			close(fildes[1]);
			printf ("[HIJO]: mi PID es %d y mi PPID es %d\n", getpid(), getppid());
			fprintf(f,"[HIJO]: mi PID es %d y mi PPID es %d\n", getpid(), getppid());
			for(i=0;i<5;i++){
				nbytes=read(fildes[0],buf,BSIZE);
				message=atoi(buf);		
	
				printf("[HIJO]:leemos el numero %d de la tuberia...\n",message);
				fprintf(f,"[HIJO]:leemos el numero %d de la tuberia...\n",message);
				fflush(f);

				twait=rand()%1000000;
				usleep(twait);
			}
			close(fildes[0]);
			printf("[HIJO] Tuberia cerrada.\n");
			fprintf(f,"[HIJO] Tuberia cerrada.\n");
			break; //Saldría del switch()
	
			
		default:// Padre genera numeros y los mete en la pipe. 5 numeros cada uno en un mensaje distinto
			close(fildes[0]);
			/* Apertura de la cola */
			printf ("[PADRE]: mi PID es %d y el PID de mi hijo es %d \n", getpid(), rf);
			for(i=0;i<5;i++){
				message=rand()%10000;
			
				sprintf(buf,"%d", message);
				nbytes=write(fildes[1],buf,BSIZE); 
	
				printf ("[PADRE]: escribimos el numero aleatorio %d en la tuberia...\n",message);
				fprintf(f,"[PADRE]: escribimos el numero aleatorio %d en la tuberia...\n",message);
				fflush(f);		

				twait=rand()%1000000;
				usleep(twait);
			}
			close(fildes[1]);
	
			printf("[PADRE]: cerrando tuberia.\n");
			fprintf(f,"[PADRE]: cerrando tuberia.\n");
	
			while ((flag = wait(&status)) > 0){
				if (WIFEXITED(status)){
					printf("Hijo PID:%d finalizado, estado=%d\n", flag, WEXITSTATUS(status));
				} else if (WIFSIGNALED(status)) {  //Para seniales como las de finalizar o matar
						printf("Hijo  PID:%d finalizado al recibir la señal %d\n", flag, WTERMSIG(status));
					} else if (WIFSTOPPED(status)) { //Para cuando se para un proceso. Al usar wait() en vez de waitpid() no nos sirve.
							printf("Hijo PID:%d parado al recibir la señal %d\n", flag,WSTOPSIG(status));
						} else if (WIFCONTINUED(status)){ //Para cuando se reanuda un proceso parado. Al usar wait() en vez de waitpid() no nos sirve.
							printf("Hijo reanudado\n");		  
						}
			}
			fprintf(f,"\n\n");
			fclose(f);
			if (flag==-1 && errno==ECHILD){
					printf("No hay más hijos que esperar\n");
					printf("status de errno=%d, definido como %s\n", errno, strerror(errno));
			}else{
				printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
				exit(EXIT_FAILURE);
			}		 
		}
	
		exit(0);
	}

















