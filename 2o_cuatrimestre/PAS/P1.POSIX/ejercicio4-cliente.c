#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include "common.h"
#include <signal.h>
#include <unistd.h>

// Apuntador al fichero de log (se utilizará en el ejercicio resumen)
FILE *fLog = NULL;
// Cola del servidor. Si no son globales la funcion cerrarColas no puede usarlas.
mqd_t mq_server;
mqd_t mq_client;

//Prototipos de funciones
void cerrarColas();
void funcionLog(char *);
void sigterm();
void sigint();
void sighup();

int main(int argc, char **argv){
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
	char bufferCliente[MAX_SIZE];
	char bufferPantalla[MAX_SIZE + 1];
	int must_stop=1;

	//Asignacion de señales
    if (signal(SIGINT, sigint) == SIG_ERR)
        printf("No puedo asociar la señal SIGINT al manejador!\n");
    if (signal(SIGHUP, sighup) == SIG_ERR)
        printf("No puedo asociar la señal SIGHUP al manejador!\n");
    if (signal(SIGTERM, sigterm) == SIG_ERR)
        printf("No puedo asociar la señal SIGTERM al manejador!\n");

	// Abrir la cola del servidor
	mq_server = mq_open(SERVER_QUEUE, O_WRONLY);
	if(mq_server == (mqd_t)-1 ){
        	perror("Error al abrir la cola del servidor");
       		exit(-1);
	}
	mq_client = mq_open(CLIENT_QUEUE, O_RDONLY);
	if(mq_server == (mqd_t)-1 ){
        	perror("Error al abrir la cola del servidor");
       		exit(-1);
	}
	system("clear");

		
	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	do {
		printf("> ");
		fflush(stdout);                  // Limpiar buffer de salida
		memset(buffer, 0, MAX_SIZE);     // Poner a 0 el buffer
		fgets(buffer, MAX_SIZE, stdin);  // Leer por teclado
		buffer[strlen(buffer)-1] = '\0'; // Descartar el salto de línea

		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_server, buffer, MAX_SIZE, 0) != 0){
			perror("Error al enviar el mensaje");
			exit(-1);
		}
		

		if(mq_receive(mq_client, bufferCliente, MAX_SIZE, NULL)<0){
			perror("Error al recibir el mensaje.\n");
		}
		if(strcmp("exit",bufferCliente)==0){	//Comprueba si se ha enviado la señal de final, para avisar al cliente en vez de emparejar/no emparejar SOLO SE ACTIVA SI SE PRODUCE UNA FINALIZACION FORZADA POR PARTE DEL SERVIDOR
			sprintf(bufferCliente,"Fin de la ejecucion debido la terminacion forzada por la salida del servidor");
			funcionLog(bufferCliente);
			must_stop=0;
		}else{
			sprintf(bufferPantalla,"Mensaje enviado: %s.", buffer);
			funcionLog(bufferPantalla);

			printf("%s\n",bufferCliente);
			sprintf(bufferPantalla,"Mensaje recibido: %s.",bufferCliente); 
			funcionLog(bufferPantalla);
	}
	// Iterar hasta escribir el código de salida
	} while ((strncmp(buffer, MSG_STOP, strlen(MSG_STOP))&&must_stop));

	// Cerrar la cola del servidor
	if(mq_close(mq_server) == (mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}
	// Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}
	return 0;
}





void sigterm(){
	cerrarColas(SIGTERM);
	exit(-1);	
}
void sigint(){
	cerrarColas(SIGINT);
	exit(-1);
}
void sighup(){
	cerrarColas(SIGHUP);
	exit(-1);
}

void cerrarColas(int senhal){
	ssize_t bytes_read;
	char bufferLog[MAX_SIZE + 1];
	sprintf(bufferLog,"exit");

	if((bytes_read=mq_send(mq_server,bufferLog,MAX_SIZE,1))==-1){//envio del mensaje a la cola
			printf("ERROR envio de señal de salida.\n");
			abort();
	}
	sprintf(bufferLog,"Enviado el mensaje: exit, debido a la señal %d.\n",senhal);
	funcionLog(bufferLog);

		// Cerrar la cola del servidor
	if(mq_close(mq_server) == (mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}

	//Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}

}




// Función auxiliar, escritura de un log
void funcionLog(char *mensaje) 
{
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;

	// Abrir el fichero
	sprintf(nombreFichero,"log-cliente.txt");
	if(fLog==NULL){
		fLog = fopen(nombreFichero,"at");
		if(fLog==NULL){
			perror("Error abriendo el fichero de log");
			exit(1);
		}
	}

	// Obtener la hora actual
	t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(mensajeAEscribir, 1000, "[%Y-%m-%d, %H:%M:%S]", p);

	// Vamos a incluir la hora y el mensaje que nos pasan
	sprintf(mensajeAEscribir, "%s ==> %s\n", mensajeAEscribir, mensaje);
	
	// Escribir finalmente en el fichero
	resultado = fputs(mensajeAEscribir,fLog);
	if ( resultado < 0)
		perror("Error escribiendo en el fichero de log");

	fclose(fLog);
	fLog=NULL;
}





