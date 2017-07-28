//Fichero con los métodos de la clase persona, que incluye "inline" el codigo de las funciones.
#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona{
	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;			
	public:
		inline Persona(string DNI, string nombre="",string apellidos="",string direccion="",string localidad="",string provincia="",string pais=""){
			DNI_=DNI;
			nombre_=nombre;
			apellidos_=apellidos;
			direccion_=direccion;
			localidad_=localidad;
			provincia_=provincia;
			pais_=pais;
		 };

		inline bool setDNI(string DNI){DNI_=DNI;return(true);};
		inline string getDNI(){return (DNI_);};

		inline bool setNombre(string Nombre){nombre_=Nombre;return(true);};
		inline string getNombre(){return(nombre_);};

		inline bool setApellidos(string Apellidos){apellidos_=Apellidos;return(true);};
		inline string getApellidos(){return (apellidos_);};

		inline bool setDireccion(string Direccion){direccion_=Direccion;return(true);};
		inline string getDireccion(){return(direccion_);};
		
		inline bool setLocalidad(string Localidad){localidad_=Localidad;return(true);};
		inline string getLocalidad(){return(localidad_);};

		inline bool setProvincia(string Provincia){provincia_=Provincia;return(true);};
		inline string getProvincia(){return(provincia_);};

		inline bool setPais(string Pais){pais_=Pais;return(true);};///POR AQUI TE HAS QUEDADO
		inline string getPais(){ return(pais_);};

		inline string getApellidosyNombre(){return(getApellidos()+", "+getNombre());};

};

#endif
