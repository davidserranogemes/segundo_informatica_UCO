#include <sys/types.h> //Para estructura pid_t 
#include <unistd.h> //Para fork()
#include "funcion4.h"

int main(int argc, char **argv){
	pid_t pid1, pid2;
	int status, childpid;

	pid1=fork();

	if(pid1==0){
		HijoCalcuadora(argv);
	}
	pid2=fork();

	if(pid2==0){
		HijoGedit(argv);
	}
	wait(&status);
	wait(&status);
}
