#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

void esMesage(struct group *grp);
void enMesage(struct group *grp);
void mostrarAyuda();
void mostrarTodosEng();
void mostrarTodosEsp();

int main(int argc, char *argv[]){

static struct option long_options[] =
	{
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0,
		   identificador de la opción */
		{"all",  no_argument,	 0, 'a'},
		{"group",  required_argument, 0, 'g'},
		{"english",  no_argument, 0, 'e'},
		{"spanish",	no_argument, 0, 's'},
		{"help", no_argument, 0, 'h'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

//Flags y value
	int aflag=0;
	int gflag=0;
	char *gvalue=NULL;
	int eflag=0;//Excluyente con la de abajo
	int sflag=0;

	int optvalue;
	int option_index=0;
//No necesarias
	int hflag=0;
	//Char
	const char * lang="LANG";
	const char * user="USER";
	char * langSys;
	char * userSys;
	//struct
	struct passwd * pwd;
	struct group * grp;
	
	opterr=0;

	system("clear");

	while ((optvalue = getopt_long (argc, argv, "aeshg:",long_options, &option_index))!=-1){
		//printf("optind: %d, optarg: %s, optopt: %c\n", optind,optarg, optopt);//DEPUR
		switch(optvalue){
			case 'a':
				aflag=1;
				break;
			case 'g':
				gflag=1;
				gvalue=optarg;
				break;
			case 'e':
				eflag=1;
				break;
			case 's':
				sflag=1;
				break;
			case 'h':
				hflag=1;
				break;
			case '?':
				mostrarAyuda();
	          		return 1;
				break;
	        	default:
	        		abort ();
				break;
			}
	}
	
	if(hflag){
		system("clear");
		mostrarAyuda();
	}else{
		//Obtencion del usuario, bien por ID o por nombre
		if(eflag&&sflag){
			printf("No se pueden activar la opcion -e y -s simultaneamente.\n");
			abort();
		}
		if(!eflag&&!sflag){
			langSys=getenv(lang);
		}
	}
	if(!aflag){
		if(!gflag){
			userSys=getenv(user);
			pwd=getpwnam(userSys);
			grp = getgrgid(pwd->pw_gid);//VIOLACION
		}else{
			grp = getgrnam(gvalue);	
		}
		if(sflag){
			esMesage(grp);
		}
		if(eflag){
			enMesage(grp);
		}
		if(!eflag&&!sflag){
			if(strstr(langSys,"ES")){
				esMesage(grp);
			}
			if(strstr(langSys,"GB")){
				enMesage(grp);
			}
		}
	}else{
		if(eflag){
			mostrarTodosEng();
		}
		if(sflag){
			mostrarTodosEsp();
		}
		if(!eflag&&!sflag){
			if(strstr(langSys,"ES")){
				mostrarTodosEsp();
			}
			if(strstr(langSys,"GB")){
				mostrarTodosEng();
			}
		}
	}		
}










void esMesage(struct group * grp){
	printf("Nombre del grupo principal: %s\n", grp->gr_name);
	printf("Id grupo: %d\n",grp->gr_gid);
}

void enMesage(struct group * grp){
	printf("Group name: %s\n", grp->gr_name);
	printf("Group Id: %d\n",grp->gr_gid);
}


void mostrarAyuda(){
		printf("\n\n\n---------------------------------------------------------------------------------------------------\n");
		printf("---Bienvenido a la ayuda del usuario.								---\n");
		printf("---Utilice -a/--all para ver todos los grupos. Si se incluye esta opcion se obvia la opcion -g	---\n");
		printf("---Utilice -s/--spanish para marcar que desea la informacion en español.			---\n");
		printf("---Utilice -e/--english para marcar que desea la informacion en ingles.				---\n");
		printf("---No indicar ninguna hara que se informe en el lenguaje actual del sistema.			---\n");
		printf("---Las opciones anteriores no pueden usarse simultaneamente.					---\n");
		printf("---Incluya -g/--group <grupo> para opbtener informacion de dicho grupo. No especificar esta	---\n---opcion hara que se muestre la informaciond del grupo del usuario actual .			---\n");
		printf("---------------------------------------------------------------------------------------------------\n");

}
void mostrarTodosEng(){
	struct group *grp;
	char nombreGrupo[30];
	char cadenaAux[150];
	int i=0;
	FILE * f;
	
	f=fopen("/etc/group","r");  //abrir fichero
	if(f==NULL){
		printf("Failure. The file couldnt be opened.\n");
		abort();
	}
	while(fgets(cadenaAux,150,f)!=NULL){
		i=0;

		while(cadenaAux[i]!=':'){
			nombreGrupo[i]=cadenaAux[i];
				i++;
		}
		nombreGrupo[i]='\0';//Si no se incluye, hay un caracter espureo en la cadena haciendo que falle
		grp = getgrnam(nombreGrupo);
		if(grp==NULL){//CONTROL POSIX
			printf("FAIL NO PILLA EL NOMBRE");
			abort();
		}
		enMesage(grp);
	
	}
	fclose(f);
}

void mostrarTodosEsp(){
	struct group *grp;
	char nombreGrupo[30];
	char cadenaAux[150];
	int i=0;
	FILE * f;
	
	f=fopen("/etc/group","r");  //abrir fichero
	if(f==NULL){
		printf("Failure. The file couldnt be opened.\n");
		abort();
	}
	while(fgets(cadenaAux,150,f)!=NULL){
		i=0;

		while(cadenaAux[i]!=':'){
			nombreGrupo[i]=cadenaAux[i];
				i++;
		}
		nombreGrupo[i]='\0';//Si no se incluye, hay un caracter espureo en la cadena haciendo que falle
		grp = getgrnam(nombreGrupo);
		if(grp==NULL){//CONTROL POSIX
			printf("FAIL NO PILLA EL NOMBRE");
			abort();
		}
		esMesage(grp);
	
	}
	fclose(f);
}



















