#include <pthread.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>

pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;

void * plusFunc(){

int i;

pthread_mutex_lock(&mtx);
for(i=0;i<5;i++){
	putchar('+');
	fflush(stdout);
	usleep(500000);
}
pthread_mutex_unlock(&mtx);

pthread_exit(NULL);
}

void * minusFunc(){

int i;

pthread_mutex_lock(&mtx);
for(i=0;i<5;i++){
	putchar('-');
	fflush(stdout);
	usleep(500000);
}
pthread_mutex_unlock(&mtx);

pthread_exit(NULL);
}

void * commaFunc(){

int i;

pthread_mutex_lock(&mtx);
for(i=0;i<5;i++){
	putchar(',');
	fflush(stdout);
	usleep(500000);
}
pthread_mutex_unlock(&mtx);

pthread_exit(NULL);
}



main(){
	int i;
	pthread_t minus, plus, comma;

	pthread_create(&plus,NULL,plusFunc,NULL);
	pthread_create(&minus,NULL,minusFunc,NULL);
	pthread_create(&comma,NULL,commaFunc,NULL);
	
pthread_mutex_lock(&mtx);
	for(i=0;i<5;i++){
		putchar('?');
		fflush(stdout);
		usleep(500000);
	}
pthread_mutex_unlock(&mtx);

	pthread_join(plus,NULL);
	pthread_join(minus,NULL);
	pthread_join(comma,NULL);
printf("\n");
	pthread_mutex_destroy(&mtx);
}
