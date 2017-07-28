#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void esMesage(int nflag,int uflag,int gflag,struct passwd *pwd);
void enMesage(int nflag,int uflag,int gflag,struct passwd *pwd);

int main(int argc, char *argv[]){
//Flags y value
	int nflag=0;//Excluyente con la de abajo
	int uflag=0;
	char *nvalue=NULL;
	char *uvalue=NULL;

	int gflag=0;

	int eflag=0;//Excluyente con la de abajo
	int sflag=0;

	int optvalue;

//No necesarias
	int hflag=0;
	//Char
	const char * lang="LANG";
	const char * user="USER";
	char * langSys;
	char * userSys;
	//struct
	struct passwd * pwd;
	
	opterr=0;

	system("clear");

	while((optvalue= getopt (argc, argv, "n:u:gesh"))!=-1){
		//printf("optind: %d, optarg: %s, optopt: %c\n", optind,optarg, optopt);//DEPUR
		switch(optvalue){
			case 'n':
				nflag=1;
				nvalue=optarg;
				break;
			case 'u':
				uflag=1;
				uvalue=optarg;
				break;
			case 'g':
				gflag=1;
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
				if(optopt=='n'){
					fprintf(stderr, "La opcion %c requiere un argumento.\n",optopt);
					abort();
				}else{ 	if(optopt=='u'){
						fprintf(stderr, "La opcion %c requiere un argumento.\n",optopt);
						abort();
					}else {	if (isprint (optopt)){
	              					fprintf (stderr, "Opción desconocida '-%c'.\n", optopt);
						abort();
	            				}else{
	                				fprintf (stderr, "Caracter `\\x%x'.\n", optopt);
							abort();
						}
				}
	          		return 1;
				break;
	        	default:
	        		abort ();
				break;
			}
		}
	}
	if(hflag){
		system("clear");
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("---Bienvenido a la ayuda del usuario.								---\n");
		printf("---Utilice -u <id> para expresar la id del usuario del que requiere informacion.		---\n");
		printf("---Utilice -n <login-name> para expresar login del usuario del que requiere informacion.	---\n");
		printf("---Las opciones anteriores no pueden usarse simultaneamente.					---\n");
		printf("---No indicar ninguna hara que se informe sobre el usuario actual.				---\n");
		printf("---Utilice -s para marcar que desea la informacion en español.					---\n");
		printf("---Utilice -e para marcar que desea la informacion en ingles.					---\n");
		printf("---No indicar ninguna hara que se informe en el lenguaje actual.				---\n");
		printf("---Las opciones anteriores no pueden usarse simultaneamente.					---\n");
		printf("---Incluya -g si desea obtener informacion del grupo del usuario.				---\n");
		printf("---------------------------------------------------------------------------------------------------\n");
	}else{
		//Obtencion del usuario, bien por ID o por nombre
		if(eflag&&sflag){
			printf("No se pueden activar la opcion -e y -s simultaneamente.\n");
			abort();
		}
		if(!eflag&&!sflag){
			langSys=getenv(lang);
		}
		if(uflag&&nflag){
			printf("No se pueden activar la opcion -u y -n simultaneamente.\n");
			abort();
		}
		if(!uflag&&!nflag){
			userSys=getenv(user);
		}
		
		if(!uflag){
			if(nflag){
				if((pwd=getpwnam(nvalue))==NULL){
					//CONTROL DE ERRORES DE POSIX
					printf("No existe el usuario\n");
					abort();
				}
			}else{
				if((pwd=getpwnam(userSys))==NULL){
					//CONTROL DE ERRORES DE POSIX
					abort();
				}
			}
		}else{
			if((pwd=getpwuid(atoi(uvalue)))==NULL){
				//CONTROL POSIX
				printf("No existe la ID de usuario\n");
				abort();
			}
		}
		if(eflag){
			enMesage(nflag,uflag,gflag,pwd);
		}
		if(sflag){
			esMesage(nflag,uflag,gflag,pwd);
		}
		if(!eflag&&!sflag){
			if(strstr(langSys,"ES")){
				esMesage(nflag,uflag,gflag,pwd);
			}
			if(strstr(langSys,"GB")){
				enMesage(nflag,uflag,gflag,pwd);
			}
		}
	}
}










void esMesage(int nflag,int uflag,int gflag,struct passwd *pwd){
	struct group *grp;
	
	printf("Nombre: %s\n",pwd->pw_gecos);
	printf("Contraseña: %s\n",pwd->pw_passwd);
	printf("Id usuario: %d\n",pwd->pw_uid);
	printf("Id grupo: %d\n",pwd->pw_gid);
	//printf("Tiempo: %d\n",pwd->pw_change);
	//printf("Clase: %s\n,pwd->pw_class);
	printf("Direccion home: %s\n",pwd->pw_dir);
	printf("Login Shell: %s\n",pwd->pw_shell);
	//printf("Tiempo expiracion contraseña: %d\n",pwd->pw_expire);
	if(!nflag){
		printf("Nombre Login: %s\n",pwd->pw_name);
		}
	if(gflag){
		grp = getgrgid(pwd->pw_gid);
			//CONTROL POSIX
		printf("Nombre del grupo principal: %s\n", grp->gr_name);
		printf("Id grupo: %d\n",pwd->pw_gid);
	}
}

void enMesage(int nflag,int uflag,int gflag,struct passwd *pwd){
	struct group *grp;
	
	printf("Name: %s\n",pwd->pw_gecos);
	printf("Password: %s\n",pwd->pw_passwd);
	printf("User Id: %d\n",pwd->pw_uid);
	printf("Group Id: %d\n",pwd->pw_gid);
	//printf("Time: %d\n",pwd->pw_change);
	//printf("Class: %s\n,pwd->pw_class);
	printf("Home direcction: %s\n",pwd->pw_dir);
	printf("Shell login: %s\n",pwd->pw_shell);
	//printf("Tiempo expiracion contraseña: %d\n",pwd->pw_expire);
	if(!nflag){
		printf("Login name: %s\n",pwd->pw_name);
		}
	if(gflag){
		grp = getgrgid(pwd->pw_gid);
			//CONTROL POSIX
		printf("Group name: %s\n", grp->gr_name);
		printf("Group Id: %d\n",pwd->pw_gid);
	}

}
























