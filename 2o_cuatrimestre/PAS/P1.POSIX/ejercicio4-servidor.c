#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include "common.h"
#include <regex.h>
#include <getopt.h>
#include <signal.h>
#include <unistd.h>

// Apuntador al fichero de log (se utilizará en el ejercicio resumen)
FILE *fLog = NULL;
// Cola del servidor, si no se ponen aqui no se pueden cerrar las colas desde los manejadores de señal
mqd_t mq_server;
mqd_t mq_client;

//Prototipo de funcionn
void funcionLog(char *);
void cerrarColas();
void mostrarAyuda();
void sigterm();
void sigint();
void sighup();
void sigalarm();


int main(int argc, char **argv)
{	
	//Valores por linea comandos
	int rflag=0;
	int hflag=0;
	int tflag=0;
	int timeExpire;
	char* rvalue=NULL;
	
//Expresiones
	regex_t regex;
	int reti;
	char msgbuf[100];
	int optvalue;
	int option_index;
	static struct option long_options[] =
	{
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0,
		   identificador de la opción */
		{"regex",  required_argument,	 0, 'r'},
		{"help",  no_argument, 0, 'h'},
		{"time",  no_argument, 0, 't'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};


	// Atributos de la cola
	struct mq_attr attr;

	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE + 1];
	char bufferCliente[MAX_SIZE + 1];
	char bufferPantalla[MAX_SIZE +1];

	//Variable para control de errores
	ssize_t bytes_read;

	// flag que indica cuando hay que parar
	int must_stop = 0;

	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje

	
		//Asignacion de señales
    if (signal(SIGINT, sigint) == SIG_ERR)
        printf("No puedo asociar la señal SIGINT al manejador!\n");
    if (signal(SIGHUP, sighup) == SIG_ERR)
        printf("No puedo asociar la señal SIGHUP al manejador!\n");
    if (signal(SIGTERM, sigterm) == SIG_ERR)
        printf("No puedo asociar la señal SIGTERM al manejador!\n");
    if (signal(SIGALRM, sigalarm) == SIG_ERR)
        printf("No puedo asociar la señal SIGALRM al manejador!\n");


	system("clear");//Inicio del programa


	while ((optvalue = getopt_long (argc, argv, "hr:t:",long_options, &option_index))!=-1){
		//printf("optind: %d, optarg: %s, optopt: %c\n", optind,optarg, optopt);//DEPUR
		switch(optvalue){
			case 'r':
				rflag=1;
				rvalue=optarg;
				break;
			case 'h':
				hflag=1;
				break;
			case 't':
				tflag=1;
				timeExpire=atoi(optarg);
				break;
			case '?':
				mostrarAyuda();
	          		return 1;
				break;
	        default:
				mostrarAyuda();
	        	abort ();
				break;
			}
	}
	if(hflag){
		mostrarAyuda();
		exit(1);
	}	
	if(!rflag&&!rvalue){//El programa no puede funcionar sin  la expresion regular
		printf("Se requiere la opcion -r/--regex.\n");
		mostrarAyuda();
		abort();
	}
	if(tflag){
		alarm(timeExpire);
	}
	// Crear la cola de mensajes del servidor
	mq_server = mq_open(SERVER_QUEUE, O_CREAT | O_RDONLY, 0644, &attr);
	if(mq_server == (mqd_t)-1 ){
   		perror("Error al abrir la cola del servidor");
     		exit(-1);
	}

	mq_client = mq_open(CLIENT_QUEUE, O_CREAT | O_WRONLY, 0644, &attr);
	if(mq_server == (mqd_t)-1 ){
   		perror("Error al abrir la cola del servidor");
    		exit(-1);
	}	
	//Crear expresion regular

	reti = regcomp(&regex,rvalue, 0);//Iniciacion de la expresion regular
        if( reti ){ 
		fprintf(stderr, "Could not compile regex\n");
		abort();
	}
	//CHAT
	do {
	
		// Recibir el mensaje
		bytes_read = mq_receive(mq_server, buffer, MAX_SIZE, NULL);
		// Comprar que la recepción es correcta (bytes leidos no son negativos)
		if(bytes_read < 0){
			perror("Error al recibir el mensaje");
			exit(-1);
		}
		
		// Cerrar la cadena
		buffer[bytes_read] = '\0';
		//COMPRUEBA LA EXPRESION REGULAR
		reti = regexec(&regex, buffer, 0, NULL, 0);//0 si coincide. El primer 0 hace referencia al numero de veces que se debe encontrar, 0 indica que no nos importa el numero
       		if( !reti ){
	            //Meter en bufferCliente "empareja"
				sprintf(bufferCliente,"Empareja");
        	}else if( reti == REG_NOMATCH ){
         	    //Meter en bufferCliente "no empareja"
				sprintf(bufferCliente,"No empareja");
        		}else{//Muestra el error producido en la funcion regexec
	                	regerror(reti, &regex, msgbuf, sizeof(msgbuf));
	                	fprintf(stderr, "Regex match failed: %s\n", msgbuf);
	                	exit(1);
	       		}
		
		

	
		if(strcmp("exit",buffer)==0){	//Comprueba si se ha enviado la señal de final, para avisar al cliente en vez de emparejar/no emparejar
			sprintf(bufferCliente,"Fin de la ejecucion.");
		}
		//ENVIA EL MENSAJE EMPAREJA o NO EMPAREJA
		if((bytes_read=mq_send(mq_client,bufferCliente,MAX_SIZE,0))==-1){//envio del mensaje a la cola
			printf("ERROR expresion regular.\n");
			abort();
		}
		// Comprobar el fin del bucle
		if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0){
			must_stop = 1;
			sprintf(bufferPantalla,"Recibido el mensaje: %s.", buffer);
			funcionLog(bufferPantalla);
		}else{//Muestra por pantalla el mensaje recibido y su contenido. Mete los mensajes en el log
			sprintf(bufferPantalla,"Recibido el mensaje: %s.", buffer);
			printf("%s\n",bufferPantalla);
			funcionLog(bufferPantalla);

			sprintf(bufferPantalla,"Mensaje enviado: %s.", bufferCliente);
			funcionLog(bufferPantalla);
		}	
	// Iterar hasta que llegue el código de salida
	} while (!must_stop);

	// Cerrar la cola del servidor
	if(mq_close(mq_server) == (mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}

	// Eliminar la cola del servidor
	if(mq_unlink(SERVER_QUEUE) == (mqd_t)-1){
		perror("Error al eliminar la cola del servidor");
		exit(-1);
	}
	//Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}

	// Eliminar la cola del cliente
	if(mq_unlink(CLIENT_QUEUE) == (mqd_t)-1){
		perror("Error al eliminar la cola del cliente");
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
void sigalarm(){
	printf("Fin de la rodaja de tiempo!!!!!\n");
	funcionLog("Fin de la rodaja de tiempo!!!!!\n");
	cerrarColas(SIGALRM);
	exit(-1);
}


void cerrarColas(int senhal){
	ssize_t bytes_read;
	char bufferLog[MAX_SIZE + 1];
	sprintf(bufferLog,"exit");

	if((bytes_read=mq_send(mq_client,bufferLog,MAX_SIZE,1))==-1){//envio del mensaje a la cola
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

	// Eliminar la cola del servidor
	if(mq_unlink(SERVER_QUEUE) == (mqd_t)-1){
		perror("Error al eliminar la cola del servidor");
		exit(-1);
	}
	//Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}

	// Eliminar la cola del cliente
	if(mq_unlink(CLIENT_QUEUE) == (mqd_t)-1){
		perror("Error al eliminar la cola del cliente");
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
	sprintf(nombreFichero,"log-servidor.txt");
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

void mostrarAyuda(){

	printf("El servidor recibe mensajes de un cliente que escribe.\nAl iniciar debe incluirse la opcion -r/--regex <expresion regular>\nSi se incluye la opcion -h/--help se muestra la ayuda.\nLa opcion -t/--time requiere un entero. Indica en cuantos segundos se cerrara el programa.\n\n\n");

}



























