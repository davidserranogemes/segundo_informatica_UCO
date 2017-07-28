#ifndef GRAFO_HPP 
#define GRAFO_HPP
/*!
	@brief Fichero .hpp de la clase Grafo

	Implementa la clase Grafo, heredada de GrafoInterfaz
*/




#define ERROR_CODE -1

#include <vector>
#include <limits>
#include <iostream>
#include <string>

#include "Vertice.hpp"
#include "GrafoInterfaz.hpp"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

namespace ed{


	/**
	@brief Clase Graafo, permite crear objetos de tipo Grafo
		Hereda de forma publica de GrafoInterfaz
	*/
	class Grafo:public GrafoInterfaz{
		private:

			//! Nodos_  Tipo vector de vertices de la stl, almacena los vertices del grafo
			vector<Vertice> Nodos_;

			//! matriz_ Tipo vector de vectores de enteros, una matriz hecha a partir del vector de la stl
			vector< vector< double > > matriz_;

			//!  Dirigido_ Tio booleano que  indica si el grafo es dirigido o no
			bool Dirigido_;

			//! tam_ Tipo entero que indica cuantos Vertices hay en el grafo
			int tam_;


			/**
			@brief metodo de insercion de vertices en el grafo.
			@param v Vertice que se inserta
			Añade un elemento al grafo, es privado pues este grafo no modifica su tamaño tras crearse.

			*/
			void addVertice(Vertice v);
		
		public:


			/**
			@brief Constructor de la clase dirigido,
			@param dirigido tipo booleano, por defecto false
	
			constructor parametrizado que genera un nuevo grafo vacio. Su parametro le permite indicar si sera dirigido o no

			*/
			Grafo(bool dirigido=false){
				Dirigido_=dirigido;
				tam_=0;
			}

			///OBSERVADORES

			/**
			@brief Metodo que devuelve el numero de elementos del grafo
			Metodo constante que develve el numero de elementos del grafo como un entero.
			*/
			inline int numVertices()const{return tam_;}

			/**
			@brief Metodo que devuelve el tipo de grafo
			Devuelve true si el grasfo es dirigido y false si no lo es 
			*/

			inline bool esDirigido()const{return Dirigido_;};


			/**
			@brief Metodo que devuelve el valor del lado entre dos vertices
			@param i Primer vertice
			@param j segundo vertice
			
			Devuelve el valor del lado entre i y j si existe, si no devuelve -1 (ERROR_CODE)


			*/
			inline double adyacente(int i, int j){
				if((i>numVertices())or(j>numVertices())){
					return ERROR_CODE;
				}else{
					return matriz_[i][j];
				}
			}

			/**
			@brief Metodo que devuelve la direccion del vertice si existe en el grafo
			@param data tipo string que identifica el vertice a buscar
			
			Metodo que devuelve la direccion del vertice si existe en el grafo y -1 si no lo encuentra

			*/
			int buscarVertice(string data);

			/**
			@brief Metodo que devuelve un vertice indicado
			@param i entero que indica que vector se desea

			Metodo que devuelve el vertice con label i

			*/

			Vertice getVertice(int i){
				return Nodos_[i];
			}
			///MODIFICADORES

			/**
			@brief Metodo que introduce los vertices y lado en el grafo desde un fichero

			Una forma de rellenar el grafo de forma externa.

			*/
			void leerFichero();

			/**
			@brief Metodo que pone el paramtro tam a un valor especifico
			@param tam nuevo tamaño del grafo

			Metodo que modifica el paramaetro tam_


			*/
			inline void setTam(int tam){tam_=tam;};
	};




}


#endif

