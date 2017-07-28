#include "jugador.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <istream>
#include <cstdlib>

using namespace std;

bool Jugador::setApuestas(){
	char * nombre=new char[14];
	char * linea=new char[30];	
			
	Apuesta auxiliar;
	apuestas_.clear();
	
	string aux=getDNI();
	//string txt(".txt");
	aux=aux+".txt";
	strcpy(nombre,aux.c_str());
	
	
	ifstream fichero(nombre);
	
	while(fichero.getline(linea,20,',')){			
		auxiliar.tipo=atoi(linea);
		
		fichero.getline(linea,20,',');
		auxiliar.valor=linea;
		
		fichero.getline(linea,20,'\n');
		auxiliar.cantidad=atoi(linea);
		
		apuestas_.push_back(auxiliar);
		
		}
	fichero.close();
	return(true);
}
	
