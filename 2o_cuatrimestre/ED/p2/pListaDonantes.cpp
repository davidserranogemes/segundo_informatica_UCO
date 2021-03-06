#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Donantes.hpp"
#include "Donante.hpp"
#include "NodoDonante.hpp"
#include "ListaOrdenadaDonantes.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(){
	ed::Donante d("DAVID","SERRANO","0",true);
	ed::Donantes l;
	ed::Donante dAux;
	int opcion;

	string NombreFich, control;
	bool check;

	std::ifstream ficheroLectura;
	std::ofstream ficheroEscritura;
/* //Muestra del constructor parametrizado
	int elem;//
	cout<<"Introduce el numero de elementos de la lista"<<endl;
	cin>>elem;
	ed::Donantes lParametrizada(elem);
	lParametrizada.escribirDonantes();
*/	
	do{//Menu
		do{

		//	cout<<"getSize()="<<l.getSize()<<endl;

			cout<<"Elija una opcion: "<<endl;
			cout<<"1. Comprobar si hay donantes."<<endl;
			cout<<"2. Cargar una lista de donantes desde un fichero, añade los elementos de ese fichero a la lista actual"<<endl;
			cout<<"3. Grabar una lista de donantes en un fichero"<<endl;
			cout<<"4. Insertar un nuevo donante."<<endl;
			cout<<"5. Modificar informacion de un donante."<<endl;
			cout<<"6. Borrar un donante de la lista."<<endl;
			cout<<"7. Mostrar por pantalla los donantes de sangre."<<endl;
			cout<<"8. Leer donantes hasta que se indique."<<endl;
			cout<<"9. Fin de programa"<<endl;	
			cin>>opcion;
			
		}while((opcion<0)||(opcion>10));
			switch(opcion){
				case 1:
					system("clear");
					check=l.isEmpty();
					if(check){
						cout<<"La lista está vacia."<<endl;
					}else{
						cout<<"La lista no está vacia."<<endl;
					}
					break;
				case 2:
					system("clear");
					cout<<"Introduzca el nombre del fichero, del que se cargan los donantes."<<endl;
					cin>>NombreFich;

					//apertura del fichero
					ficheroLectura.open(NombreFich.c_str());
					std::cin.ignore(); //Elimina caracteres residuales que puedan afectar a la lectura
					ficheroLectura>>l;

					cout<<"Fichero "<<NombreFich<<" leido."<<endl;
					ficheroLectura.close();
					break;
				case 3:
					system("clear");
					cout<<"Introduzca el nombre del fichero, en el que se guardan los donantes."<<endl;
					cin>>NombreFich;

					//apertura del fichero
					ficheroEscritura.open(NombreFich.c_str());
					std::cin.ignore(); //Elimina caracteres residuales que puedan afectar a la lectura
					ficheroEscritura<<l;

					cout<<"Fichero "<<NombreFich<<" creado."<<endl;
					ficheroEscritura.close();

					break;
				case 4:
					system("clear");
					d.leerDonante();
					l.insertDonante(d);
					break;
				case 5:
					system("clear");
					d.leerDonante();
					l.ModificarDonante(d);
					break;
				case 6:
					system("clear");
					d.leerDonante();
					l.deleteDonante(d);
					break;
				case 7:
					system("clear");
					l.escribirDonantes();				
					break;
				case 8:
					system("clear");
					l.leerDonantes();		
					system("clear");		
					break; 
			}
	}while(opcion!=9);//Menu
return 0;
}



















