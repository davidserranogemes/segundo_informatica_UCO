#include <cstdlib>
#include <unistd.h>
#include "Polinomio.hpp"
#include "Monomio.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]){
	int opcion=0;
	int auxValor=0;
	float result=0;
		
	ed::Polinomio p1;
	ed::Polinomio p2(2);
	ed::Polinomio p3(p2);

	cout<<"Se muestra el uso de los constructores de copia, el programa continuara en 5 segundos, limpiando la pantalla."<<endl;
	p1.escribirPolinomio();
	p2.escribirPolinomio();
	p3.escribirPolinomio();
	
	sleep(5);
	system("clear");
	do{//Menu
		do{
		
			cout<<"Elija una opcion: "<<endl;
			cout<<"1.Valor de un polinomio para un dato concreto de X"<<endl;
			cout<<"2.Suma de dos monomios."<<endl;
			cout<<"3.Multiplicacion de dos monomios."<<endl;
			cout<<"4.Lectura y escritura de un polinomio usando << y >>."<<endl;
			cout<<"5.Fin de programa"<<endl;	
			cin>>opcion;

		}while((opcion<0)||(opcion>6));
			switch(opcion){
				case 1:
					cin>>p1;
					cout<<"Introduzca el valor de x: "<<endl;
					cin>>auxValor;
					
					result=p1.obtenerResultados(auxValor);
					system("clear");
					cout<<"Resultado: "<<result<<endl;
					break;
				case 2:
					cin>>p1;
					cin>>p2;

					p3=p1+p2;
					system("clear");
					cout<<"Resultado:  "<<p3;
					break;
				case 3:
					cin>>p1;
					cin>>p2;
				
					p3=p1*p2;
					system("clear");
					cout<<"Resultado: "<<p3;
					break;
				case 4:
					cout<<p1<<endl;
					cin>>p1;
					system("clear");
					cout<<p1<<endl;
					break;
			}
	}while(opcion!=5);//Menu

}
























