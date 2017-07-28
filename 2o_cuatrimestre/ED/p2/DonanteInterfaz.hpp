/*!
	@brief Interfaz de la clase Donante
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Donante	
*/


#ifndef DONANTEINTERFAZ_HPP_
#define DONANTEINTERFAZ_HPP_

#include <string>
/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/
using std::string;
namespace ed{
	class DonanteInterfaz{
		public:
			//HAY QUE COMENTAR TODOS LOS METODOS

			/**
			@brief Metodo virtual puro que devuelve un string con el nombre del donante
				Metodo virtual puro que devuelve un tipo string que contiene el nombre del donante. Actua de forma constante.
			
			*/
			virtual string getNombre()const=0;

			/**
			@brief Metodo virtual puro que devuelve un string con los apelidos del donante
				Metodo virtual puro que devuelve un tipo string que contiene los apellidos del  donante. Actua de forma constante.
			
			*/
			virtual string getApellidos()const=0;

			/**
			@brief Metodo virtual puro que devuelve un string con el grupo sanguineo del donante
				Metodo virtual puro que devuelve un tipo string que contiene el grupo sanguineo del  donante. Actua de forma constante.
			
			*/			
			virtual string getGrupoSanguineo()const=0;

			/**
			@brief Metodo virtual puro que devuelve un booleano que indica el RH del donante
				Metodo virtual puro que devuelve un tipo bool. El valor true significara RH+ y el valor negativo RH-. Actua de forma constante.
			
			*/
			virtual bool getRH()const=0;


			/**
			@brief Metodo virtual puro, devuelve void y modifica el valor del nombre
			@param nombre tipo string que contiene el nuevo valor del nombre			
			Metodo virtual puro que permite modificar el valor de la informacion del donante, de tipo string
			*/
			virtual void setNombre(string nombre)=0;
			
			/**
			@brief Metodo virtual puro, devuelve void y modifica el valor de los apellidos
			@param apellidos tipo string que contiene el nuevo valor de los apellidos			
			Metodo virtual puro que permite modificar el valor de la informacion del donante, de tipo string
			*/			
			virtual void setApellidos(string apellidos)=0;

			/**
			@brief Metodo virtual puro, devuelve void y modifica el valor del grupo sanguineo
			@param GrupoSanguineo tipo string que contiene el nuevo valor del grupo sanguineo			
			Metodo virtual puro que permite modificar el valor de la informacion del donante, de tipo string
			Solamente debe aceptar los valores "A", "B", "AB" y "0"
			*/
			virtual void setGrupoSanguineo(string GrupoSanguineo)=0;

			/**
			@brief Metodo virtual puro, devuelve void y modifica el valor del RH
			@param RH tipo string que contiene el nuevo valor del RH			
			Metodo virtual puro que permite modificar el valor de la informacion del donante, de tipo booleano
			El valor true significa RH+ y el valor false significa RH-
			*/
			virtual void setRH(bool RH)=0;

	};

}









#endif
