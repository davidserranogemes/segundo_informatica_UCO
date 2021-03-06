#include "Monomio.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]){
	int opcion=0;
	int auxValor=0;
	float result=0;
	ed::Monomio m1;//por defecto
	ed::Monomio m2(2,1);//valores
	ed::Monomio m3(m2);//por copia
	
	cout<<m1<<endl;
	cout<<m2<<endl;
	cout<<m3<<endl;
	do{//Menu
		do{
			cout<<"Elija una opcion: "<<endl;
			cout<<"1.Valor de un monomio para un dato concreto de X"<<endl;
			cout<<"2.Multiplicacion de dos monomios."<<endl;
			cout<<"3.Fin de programa"<<endl;	
			cin>>opcion;

		}while((opcion<0)||(opcion>>4));
			switch(opcion){
				case 1:
					cin>>m1;
					cout<<"Introduzca el valor de x: "<<endl;
					cin>>auxValor;
					
					result=m1.resultadoMonomio(auxValor);
					cout<<"Resultado: "<<result<<endl;
					break;
				case 2:
					cin>>m1;
					cin>>m2;
				
					m3=m1*m2;
					cout<<m3;
			}
	}while(opcion!=3);//Menu

}
