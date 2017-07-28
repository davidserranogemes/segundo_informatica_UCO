/*!
	@brief Fichero .hpp de la clase MonticuloDonantesInterfaz

	Especifica los minimos que debe cumplir toda clase MonticuloDonantes
*/


#ifndef MONTICULO_DONANTES_HPP
#define MONTICULO_DONANTES_HPP
#include <vector>
#include <cassert>

#include "Donante.hpp"
#include "MonticuloDonantesInterfaz.hpp"


namespace ed{

	/**
	@brief Clase MonticuloDonantes, permite crear objetos de tipo MonticuloDonantes
		Hereda de forma publica de MonticuloDonantesInterfaz
	*/
	
	class MonticuloDonantes : public MonticuloDonantesInterfaz{

		private:
			//! heap_ parametro de tipo vector,(STL), que mantiene todos los donantes del heap
			std::vector<Donante> heap_;
			//! tam_ parametro de tipo int que mantiene el numero de elementos del heap
			int tam_;

			/**
			@brief Metodo privado que aumenta el tamaño en uno
			Aumenta el tamaño en uno
			*/
			void tamPlus(){tam_++;};

			/**
			@brief Metodo privado que disminuye el tamaño en uno
			Disminuye el tamaño en uno
			*/			
			void tamMinus(){tam_--;};
			
				
			/**
			@brief Metodo privado que comprueba si la cabeza es el minimo, si no, la hunde.
			Metodo privado que comprueba si la cabeza es el minimo, si no, la hunde y vuelve a comprobar si ese donante debe ser cabeza del subarbol.
			*/
			void hundir();
			/**
			@brief Metodo privado que comprueba si ultimo nodo hoja esta en la posicion correcta y si no es asi, flota.
			Comprueba si un nodo deberia estar en la posicion de su padre y los intercambia si no estan bien colocados. Esto se realiza hasta que dicho hijo no sea superior que su padre o se convierta en cima.

			*/
			void flotar();

		public:

			/**
			@brief Constructor de la clase MonticuloDonantes.

			Constructor de la clase MonticuloDonantes, el monticulo empieza vacio y el tamaño a 0
			*/
			MonticuloDonantes(){
				tam_=0;
			}
				

			/**
			@brief Metodo que comprueba si el heap esta vacio
			Metodo que devuelve true si el heap esta vacio y false si no esta vacio.
			*/
			inline bool isEmpty()const{
				return heap_.empty();
			}

			/**
			@brief Metodo que devuelve el donante de la cima
			Metodo constante que devuelve el donante con menos donaciones, que es el que esta en la cima			
			*/
			inline Donante Top()const{
				assert(!isEmpty());
				return heap_[0];
			}
			/**
			@brief Metodo que devuelve el numero de elementos del heap
			Metodo constante que develve el numero de elementos del heap como un entero.
			*/
			inline int getTam(){return tam_;};
			///Modificadores

			/**
			@brief Metodo que inserta un elemento en el heap.
			@param d tipo Donante que se inserta

			Metodo que inserta un donante en la primera hoja disponible, e intenta flotar.

			*/			
			void insert(Donante d);

			/**
			@brief Metodo que elimina el elemento de cima

			Metodo que elimina el elemento de la cima, pone en la cima el elemento de la ultima hoja ocupada e intenta hundirlo
			*/
			void remove();

			/**
			@brief Metodo que simula donaciones aumentando las donaciones del donante de cima

			Metodo que pide cuantas donaciones se van a realizar. Realiza donacion a donacion y va comprobando si el elemento de la cima debe hundirse, antes de realizar la siguiente donacion
			*/		
			void donar();	

 			///Sobrecarga de operadores

			/*!
			@brief Sobrecarga del operador >> mediante una funcion friend
			@param stream Referencia a un tipo istream del cual se leen los datos que se introducen en m
			@param m Referencia a un tipo MonticuloDonantes en el que se introducen los datos que recibe de stream
			@return stream Tipo istream

				Sobrecarga del operador >> lo que permite leer directamente desde un fichero un monticulo de donantes, funcion de tipo friend
			*/
			friend istream &operator>>(istream &stream, MonticuloDonantes &m);


			/*!
			@brief Sobrecarga del operador << mediante una funcion friend
			@param stream Referencia a un tipo ostream en el que se escriben los datos del parametro m
			@param m Referencia a un tipo MonticuloDonantes en el que se leen los datos para que los use stream 
			@return stream Tipo ostream

				Sobrecarga del operador << lo que permite escribir directamente a un fichero la informacion de un heap de donantes, funcion de tipo friend
			*/	
			friend ostream &operator<<(ostream &stream, MonticuloDonantes &m);

		
	};



}
#endif
