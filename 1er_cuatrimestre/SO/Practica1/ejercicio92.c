#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_usr1(){
	return;
}
void alarma(){
	return;
}

int main(int arc, char** argv){

	pid_t pid_otro;
	int i;

	pid_otro=atoi(argv[1]);
	signal(SIGALRM,alarma);

	printf("Soy ejercicio92.exe, voy a llamar a ejercicio91.exe.\n\n");


	for(i=0;i<8;i++){
		alarm(3);
		pause();
		printf("Estoy esperando a la señal de alarma.\n");
		alarm(0);
		kill(pid_otro,SIGUSR1);
		}

	alarm(0);

	sleep(5);

	printf("Cerrando ejercicio91.exe.\n");
	kill(pid_otro,SIGINT);
	sleep(5);

	printf("\nCerrando este programa.\n");
	kill(getpid(),SIGINT);
}


