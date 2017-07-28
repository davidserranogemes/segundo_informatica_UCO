#include <sys/types.h> //Para estructura pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

main(){
	pid_t pid;
	int status, childpid;
	
	pid=fork();
	if(pid==0){
		printf("Soy el hijo y mi pid es: %d\n", getpid());
	exit(-1);

	}
	else{
		sleep(20);
	}
}
