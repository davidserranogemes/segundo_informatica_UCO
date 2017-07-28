#include <cstdio>
#include <iostream>
#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h" 
#include <string>
#include <list>
#include "auxiliarFunction.h"
using namespace std;
main(){
	Crupier crupier1("32731725B","7777");//DNI Y CODIGO
	Ruleta ruleta1(crupier1);
	Jugador jugadorAuxiliar("3333","XXX");
	int select=-1;
	string DNIAux;
	string codigoAux;
	while(select!=0)
		do{	
			cout<<"Bienvenidos al casino de POO"<<'\n';
			cout<<"Elija una accion:"<<'\n'<<"1.Añadir jugador."<<'\n'<<"2.Añadir apuestas por codigo."<<'\n'<<
			cin>>select;
		while(select<0||select>10)
			switch(select){
				case 1:
					system("clear");
					cout<<"Introduzca el DNI del jugador:"<<'\n';
					cin>>DNIAux;
					cout>>"Introduzca el codigo del jugador:"<<'\n';
					cin>>codigoAux;
					
					jugadorAuxiliar.setDNI(DNIAux);
					jugadorAuxiliar.setCodigo(codigoAux);
					addJugador(jugadorAuxiliar);
				break;
			
				case 2:
