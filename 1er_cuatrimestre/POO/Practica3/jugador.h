#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"
#include <list>


struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador : public Persona{
	private:
		int dinero_;
		string codigo_;
		list<Apuesta> apuestas_;
	public:
		inline Jugador(string DNI,string codigo,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="") : Persona(DNI,nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo;dinero_=1000;};//Constructor de la clase jugador.

		inline bool setCodigo(string Codigo){codigo_=Codigo;return(true);};
		inline string getCodigo(){return(codigo_);}
		
		inline bool setDinero(int Dinero){dinero_=Dinero;return(true);};
		inline int getDinero(){return(dinero_);};
		
		inline list<Apuesta> getApuestas(){return(apuestas_);}
		bool setApuestas();

		
		
};
#endif
