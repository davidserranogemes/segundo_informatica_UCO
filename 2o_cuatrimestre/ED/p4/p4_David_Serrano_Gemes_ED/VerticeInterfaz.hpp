/*!
	@brief Interfaz de la clase Vertice
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Vertice
*/

#ifndef VERTICE_INTERFAZ_HPP
#define VERTICE_INTERFAZ_HPP


#include <string>

using std::string;
namespace ed{

	/**
	@brief Clase VerticeInterfaz, esppecifica la clase Vertice
		Especifica los metodos minimos de una clase Vertice
	*/
	class VerticeInterfaz{

		public:

			/**
			@brief Metodo virtual puro que devuelve un string con el dato del vertice
				Metodo virtual puro que devuelve un tipo string que contiene el dato del vertice. Actua de forma constante.
			
			*/
			virtual string getData()const=0;


			/**
			@brief Metodo virtual puro que devuelve un int con el dato de la etiqueta
				Metodo virtual puro que devuelve un tipo int que contiene el dato de la etiqueta. Actua de forma constante.
			
			*/
			virtual int getLabel()const=0;

			/**
			@brief Metodo virtual puro que no devuelve nada, y modifica Data
			@param data tipo de dato string 	
				Metodo virtual puro que no devuelve nada y modifica el valor Data con un string constante			
			*/			
			virtual void setData(const string data)=0;


			/**
			@brief Metodo virtual puro que no devuelve nada, y modifica label
			@param label tipo de dato int 				
				Metodo virtual puro que no devuelve nada y modifica el valor label con un int constante			
			*/			
			virtual void setLabel(const int label)=0;
	};
}


#endif
