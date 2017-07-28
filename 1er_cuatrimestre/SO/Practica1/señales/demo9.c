/* alarm.c - Implementa un sleep con la señal de alarma */

#include	<signal.h>
#include	<stdio.h>
#include	<unistd.h>

static void sig_alrm(int signo)
{
	printf("entre en la funcion\n");
	return;	/* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int nsecs)
{
	alarm(nsecs);		/* start the timer */
	pause();			/* next caught signal wakes us up */
}


int main ()
{
	signal(SIGALRM, sig_alrm);
    printf ("Una alarma en 3 segundos.\n");
    sleep1(3);
    printf ("Terminado el primer sleep...\n");
    sleep1(2);
    printf ("Terminado el segundo sleep...\n");
}
