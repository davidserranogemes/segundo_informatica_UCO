#ifndef GRAFOINTERFAZ_HPP
#define GRAFOINTERFAZ_HPP
/*!
	@brief Interfaz de la clase Grafo
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Grafo
*/


namespace ed{

	/**
	@brief Clase VerticeInterfaz, esppecifica la clase Vertice
		Especifica los metodos minimos de una clase Vertice
	*/

	class GrafoInterfaz{
		public:
			
			/**
			@brief Metodo virtual puro que devuelve un entero con el dato del numero de Vertices
				Metodo virtual puro que devuelve un tipo entero que contiene el dato del numero de vertices. Actua de forma constante.
			
			*/

			virtual int numVertices()const=0;

			/**
			@brief Metodo virtual puro que devuelve un booleano que indica si el grafo es o no dirigido

				Metodo virtual puero que devuelve un booleano segun elk tipo de grafo. Devuelve true si el grafo es dirigido y falso si no lo es

			*/

			virtual bool esDirigido()const=0;

			/**
			@brief metodo virtual puro que devuelve un double con el valor de un lado
			@param i Primer vertice del lado
			@param j Segundo vertice del lado
			
			Metodo virtual que devuelve un double con el valor de lado entre los vertices i y j

			*/

			virtual double adyacente(int i, int j)=0;

			/**
			@brief metodo virtual puro que devuelve un entero con la posicion de un Vertice si existe
			@param data Recibe un string con el data del vertice a buscar
	
			Devuelve el identificador de un vertice si este existe en el grafo. Si no devuelve -1
			*/

			virtual int buscarVertice(string data)=0;
	};



}
#endif
