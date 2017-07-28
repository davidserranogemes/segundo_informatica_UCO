#include <list>
#include "ruleta.h"
#include <fstream>
#include "jugador.h"
#include <cstdio>
#include <iostream>
using namespace std;

/*Comprueba si un jugador está en la lista de jugadores.
Si está devuelve false.
Si no está lo mete dentro y compruba si existe un fichero asociado a su nombre.
Si existe no hace nada más y devuelve true.
Si no existe lo crea "nombre_Jugador".txt y devuelve true
*/
bool Ruleta::addJugador(Jugador jugadorNuevo){
	bool existe=false;
	list<Jugador>::iterator i;
	
	for(i=jugadores_.begin();i!=jugadores_.end();i++){
		if(i->getDNI()==jugadorNuevo.getDNI()){
			existe=true;
		}
	}

	if(!existe){	
		//Si no existe lo mete dentro
		jugadores_.push_back(jugadorNuevo);
		string nombreFichero;

		nombreFichero=jugadorNuevo.getDNI();
		nombreFichero=nombreFichero+".txt";

		ifstream fichero(nombreFichero.c_str());

		if(!fichero){
				fichero.close();
		}else{
				ofstream fichero(nombreFichero.c_str());
				fichero.close();
		}
		return(true);	

	}else{//Si existe no hace nada
		return(false);
	}
}

/*
Comprueba que la lista no esté vacía.
Si está vacía devueve un -1 
Si no lo está comprueba que el jugador esté en a lista.
Si está o elimina  y devueve un 1
Si no está en la lista devuelve un -2
*/


int Ruleta::deleteJugador(Jugador jugadorEliminar){
	int status=-2;
	
	if(jugadores_.size()==0){//Lista vacia
		status=-1;
	}else{
		list<Jugador>::iterator i;
		
		for(i=jugadores_.begin();i!=jugadores_.end();i++){
			if(i->getDNI()==jugadorEliminar.getDNI()){//EL jugador existe
				jugadores_.erase(i);
				i--;
				status=1;
				}
		}
		
	}
	return(status);
}
/*Otra manera de hacerlo, llamando a la función delete Jugador ya creada, MISMO RESULTADO aunque más lento debido a que hace una llamada a una funciom

int Ruleta::deleteJugador(Jugador jugadorEliminar){
	int status;
	status=deleteJugador(jugadorEliminar.getDNI());
	return(status);
	}
*/	
/* 
Comprueba que la lista no esté vacía.
Si está vacía devueve un -1 
Si no lo está comprueba que el jugador esté en a lista.
Si está o elimina  y devueve un 1
Si no está en la lista devuelve un -2
*/

int Ruleta::deleteJugador(string DNIEliminar){	
	//cout<<"hola2"<<'\n';	
	int status=-2;
		if(jugadores_.size()==0){//Lista vacia
		status=-1;
		//cout<<"hola lista vacia"<<'\n';
	}else{
	//	cout<<"hola creando iterador"<<'\n';
		list<Jugador>::iterator i;
	//	cout<<"hola iterador creado"<<'\n';
		for(i=jugadores_.begin();i!=jugadores_.end();i++){

			if(i->getDNI()==DNIEliminar){//EL jugador existe
				jugadores_.erase(i);
				i--;//Hay que retrasar en uno el puntero de la lista
				status=1;
				}
		}
		
	}
	return(status);
}

/*
Funcion que vuelca una lista de Jugadores en un fichero, con formato:
	, entre campos de un mismo jugador
	\n entre jugadores 
*/
void Ruleta::escribeJugadores(){//Vuelca la lista en un fichero
	ofstream fichero("jugadores.txt");
	list<Jugador>::iterator i;
	
	for(i=jugadores_.begin();i!=jugadores_.end();i++){
		fichero << i->getDNI() << "," << i->getCodigo() << "," << i->getNombre() << "," << i->getApellidos()<< "," << i->getDireccion() << "," << i->getLocalidad() << "," << i->getProvincia() << "," << i->getPais() << "," << i->getDinero() << '\n';
		
	}
	
	fichero.close();
}

/*
Lee los jugadores del fichero jugadores.txt y los añade a la lista
*/

void Ruleta::leeJugadores(){
	ifstream fichero("jugadores.txt");
	char * aux=new char[30];
	Jugador auxJugador("33XX", "1");
	int dineroAux;

	jugadores_.clear();
	
	while(fichero.getline(aux,30,',')){
		auxJugador.setDNI(aux);//Metemos el DNI en el jugador auxiliar
		
		fichero.getline(aux,30,',');
		auxJugador.setCodigo(aux);//Metemos el Codigo en el jugador auxiliar
		
		fichero.getline(aux,30,',');
		auxJugador.setNombre(aux);//Metemos el Nombre en el jugador auxiliar

		fichero.getline(aux,30,',');
		auxJugador.setApellidos(aux);//Metemos el Apellido en el jugador auxiliar
	
		fichero.getline(aux,30,',');
		auxJugador.setDireccion(aux);//Metemos la Direccion en el jugador auxiliar

		fichero.getline(aux,30,',');
		auxJugador.setLocalidad(aux);//Metemos la Localidad en el jugador auxiliar.
	
		fichero.getline(aux,30,',');
		auxJugador.setProvincia(aux);//Metemos la Provincia en el jugador auxiliar

		fichero.getline(aux,30,',');
		auxJugador.setPais(aux);//Metemos el Pais en el jugador auxiliar
		
		fichero.getline(aux,30,'\n');
		dineroAux=atoi(aux);
		auxJugador.setDinero(dineroAux);//Metemos el Dinero en el jugador auxiliar
		
		addJugador(auxJugador);
		
		//cout<<auxJugador.getDNI()<<","<<auxJugador.getCodigo()<<","<<auxJugador.getNombre()<<","<<auxJugador.getApellidos()<<","<<auxJugador.getDireccion()<<","<<auxJugador.getLocalidad()<<","<<auxJugador.getProvincia()<<","<<auxJugador.getPais()<<","<<auxJugador.getDinero()<<'\n';

	}

	delete(aux);
}


//Selecciona el color de a bola, si es cero directamente devuelve "cero"
string Ruleta::getColor_(int numero){
	if(numero==0){
		return("cero");
	}else{

		switch(numero){
			case 1:
			case 3:
			case 5:
			case 7:
			case 9:
			case 12:
			case 14:
			case 16:
			case 18:
			case 19:
			case 21:
			case 23:
			case 25:
			case 27:
			case 30:
			case 32:
			case 34:
			case 36:
				return("rojo");
			default:
				return("negro");
		}
	}
}
//Comprueba si e numero es alto o bajo y si es cero directamente devuelve "cero"

string Ruleta::getAltura_(int numero){
	if(numero==0){
		return("cero");
	}else{
	
		if(numero<19){
			return("bajo");
		}else{
			return("alto");
		}
	}

}


/*
Función que evalua cada lista de apuestas de cada jugador.
*/


void Ruleta::getPremios(){
	
	struct Apuesta ind;
	list<Apuesta> aux;
	list<Jugador>::iterator i;
	list<Apuesta>::iterator j;
//AÑADIR COMPROBAR QUE SE HA LANZAO LA BOLA AL MENOS UNA VEZ
	for(i=jugadores_.begin();i!=jugadores_.end();i++){
		i->setApuestas();		
		aux=i->getApuestas();

		for(j=aux.begin();j!=aux.end();j++){
			ind=*j;
			
			switch (ind.tipo){
				case 1://Apuesta a un numero si se ha acertado el numero se gana 35 a 1
					int dinAP;//variable auxiliar para saber el saldo en movimiento
					int pred;//prediccion del usuario cuando es un numero
					pred=atoi((ind.valor).c_str());					
					if(pred==bola_){
						dinAP=35*ind.cantidad;
						
						i->setDinero(i->getDinero()+dinAP);
						banca_=banca_-dinAP;
					}else{
						i->setDinero(i->getDinero()-ind.cantidad);
						
						banca_=banca_+ind.cantidad;
					}
					break;

				case 2://Apuesta al color si se ha acertado se gana 1 a 1
					if(ind.valor==getColor_(bola_)){
						i->setDinero(i->getDinero()+ind.cantidad);						
						
						banca_=banca_-ind.cantidad;
					}else{
						i->setDinero(i->getDinero()-ind.cantidad);

						banca_=banca_+ind.cantidad;
					}
					break;

				case 3://Apuesta a par o impar, si se ha acertado se gana 1 a 1
					if(ind.valor==getParidad_(bola_)){
						i->setDinero(i->getDinero()+ind.cantidad);

						banca_=banca_-ind.cantidad;
					}else{
						i->setDinero(i->getDinero()-ind.cantidad);

						banca_=banca_+ind.cantidad;
					}
				break;

				case 4://Apuesta a alto bajo, si se ha acertado se gana 1 a 1. Alto:1-18 Bajo:19-36
					if(ind.valor==getAltura_(bola_)){
						i->setDinero(i->getDinero()+ind.cantidad);

						banca_=banca_-ind.cantidad;
					}else{
						i->setDinero(i->getDinero()-ind.cantidad);

						banca_=banca_+ind.cantidad;
					}
					break;
				}
					
		}
	}
}



















