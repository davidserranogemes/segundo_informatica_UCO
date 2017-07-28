#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string>


#include "Donante.hpp"
#include "MonticuloDonantes.hpp"

using std::cout;
using std::cin;
using std::endl;


int main(){
int opcion;
int numDonaciones;
ed::MonticuloDonantes m;
ed::Donante d;

	string NombreFich, control;


	std::ifstream ficheroLectura;
	std::ofstream ficheroEscritura;
	system("clear");
do{//Menu
		do{



			cout<<"Elija una opcion: "<<endl;
			cout<<"0. Salir del programa. "<<endl;
			cout<<"1. Comprobar el monticulo esta vacio."<<endl;
			cout<<"2. Cargar un monticulo de donantes desde un fichero."<<endl<<'\t'<<"Añade los elementos de ese fichero a la lista actual"<<endl;
			cout<<"3. Grabar el monticulo de donantes en un fichero"<<endl;
			cout<<"4. Mostrar el donante que esta en la cima."<<endl;
			cout<<"5. Simular donaciones."<<endl;
			cout<<"6. Insertar donante."<<endl;
			cout<<"7. Eliminar un donante."<<endl;
			cin>>opcion;
			
		}while((opcion<0)||(opcion>7));
			switch(opcion){
				case 0:
					system("clear");
					cout<<"Apagando programa...."<<endl;
					sleep(2);
					system("clear");
					break;
				case 1:
					system("clear");
					if(m.isEmpty()){
						cout<<"El monticulo esta vacio."<<endl;
					}else{
						cout<<"El monticulo no esta vacio."<<endl;
					}
					break;
				case 2:
					system("clear");
					cout<<"Introduzca el nombre del fichero, del que se cargan los donantes."<<endl;
					cin>>NombreFich;

					//apertura del fichero
					ficheroLectura.open(NombreFich.c_str());
					cin.ignore(); //Elimina caracteres residuales que puedan afectar a la lectura
					ficheroLectura>>m;

					cout<<"Fichero "<<NombreFich<<" leido."<<endl;
					ficheroLectura.close();
					break;
				case 3:
					system("clear");
					if(m.isEmpty()){
						cout<<"El monticulo esta vacio."<<endl;
					}else{
						cout<<"Introduzca el nombre del fichero, en el que se guardan los donantes."<<endl;
						cin>>NombreFich;

						//apertura del fichero
						ficheroEscritura.open(NombreFich.c_str());
						cin.ignore(); //Elimina caracteres residuales que puedan afectar a la lectura
						ficheroEscritura<<m;

						cout<<"Fichero "<<NombreFich<<" creado."<<endl;
						ficheroEscritura.close();
					}
					break;
				case 4:
					system("clear");
					if(m.isEmpty()){
						cout<<"El monticulo  esta vacio."<<endl;
					}else{
						m.Top().escribirDonante();
					}
					break;
				case 5:
					system("clear");

					if(m.isEmpty()){
						cout<<"El monticulo esta vacio."<<endl;
					}else{
						cout<<"Introduzca el numero de donaciones que se van a realizar:"<<endl;
						cin>>numDonaciones;
						
						for(int i=0;i<numDonaciones;i++){
							m.donar();
						}
						cout<<"Realizadas "<<numDonaciones<<" donaciones."<<endl;
					}
					break;
				case 6:
					system("clear");
					d.leerDonante();
					m.insert(d);
					break;
				case 7:
					system("clear");
					if(m.isEmpty()){
						cout<<"El monticulo ya esta vacio."<<endl;
					}else{
						m.remove();
					}
					break;
			}
	}while(opcion!=0);//Menu
	return 0;
	

}


