#include "Donante.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]){
	int opcion=0;
	std::ifstream fichero("donante.txt");
	std::ofstream fichero2("donanteRES.txt");
	ed::Donante d1;
	ed::Donante d2("David","Serrano Gemes","0",true);
	ed::Donante d3(d2);
//Muestra de los constructores por defecto, por valor y valores por defecto

/*
	d1.escribirDonante();
	d2.escribirDonante();
	d3.escribirDonante();
	cout<<"Se muestra el uso de los constructores de copia, el programa continuara en 5 segundos, limpiando la pantalla."<<endl;
	
	sleep(5);
	system("clear");
*/
	do{//Menu
		do{

			cout<<"Elija una opcion: "<<endl;
			cout<<"1. Leer un donante desde el teclado."<<endl;
			cout<<"2. Escribir un donante por pantalla"<<endl;
			cout<<"3. Modificar datos de un donante"<<endl;
			cout<<"4. Comparacion lexico grafica de dos donantes. El que esta en memoria y otro que se introduce."<<endl;
			cout<<"5. ¿Se llaman dos donantes igual? El que esta en memoria y otro que se introduce."<<endl;
			cout<<"6. Muestra de la sobrecarga de << y >>"<<endl;
			cout<<"7. Fin de programa"<<endl;	
			cin>>opcion;
			
		}while((opcion<0)||(opcion>8));
			switch(opcion){
				case 1:
					system("clear");
					d1.leerDonante();
					break;
				case 2:
					system("clear");
					cout<<"Muestra los datos del donante cargado en memoria."<<endl;
					d1.escribirDonante();
					break;
				case 3:
					d1.modificarDonante();
					break;
				case 4:
					d2.leerDonante();
					if(d1==d2){
						cout<<endl<<"El donante en memoria se llama igual que el donante introducido."<<endl;	
						break;					
					}
					if(d1<=d2){
						cout<<endl<<"El donante en memoria es anterior alfabeticamente que el donante introducido."<<endl;
					}else{
						cout<<endl<<"El donante en memoria es posterior alfabeticamente que el donante introducido."<<endl;
					}
					break;
				case 5:
					d2.leerDonante();
					if(d1==d2){
						cout<<endl<<"El donante en memoria se llama igual que el donante introducido."<<endl;
					}else{
						cout<<endl<<"El donante en memoria se llama diferente que el donante introducido."<<endl;
					}
					break;
				case 6:
					cin.ignore();
					fichero>>d1;
					fichero2<<d1;
					break;
				/*case 7:					
					break;*/ //Por si se incluyen mas
			}
	}while(opcion!=7);//Menu

}

	

















