#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"


class Crupier : public Persona {
	private:
		string Codigo_;
	public:
		inline Crupier(string DNI, string Codigo,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="") : Persona(DNI,nombre, apellidos, direccion, localidad, provincia, pais){Codigo_=Codigo;};

		inline bool setCodigo(string Codigo){Codigo_=Codigo;return(true);};
		inline string  getCodigo(){return(Codigo_);};
		
};
#endif
