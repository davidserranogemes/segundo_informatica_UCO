/*!
	@brief Fichero .hpp de la clase ListaOrdenadaDonantes

	Implementa la clase ListaOrdenadaDonantes, requiere de una clase Donante y de una clase NodoDonante
*/
/**
@brief Fichero .hpp de la clas ListaOrdenadaDonantes

Define un tipo lista de donantes doblemente enlazada utilizando la clase NodoDonante
Depende de las clases NodoDonante y la clase Donante
*/

#ifndef LISTAORDENADADONANTES_HPP
#define LISTAORDENADADONANTES_HPP

#include "Donante.hpp"
#include "NodoDonante.hpp"

/*!
@brief namespace de la asignatura Estructura de Datos
*/
namespace ed{

	class ListaOrdenadaDonantes{
		private:
			NodoDonante * lista_;///Parametro de tipo puntero a NodoDonante. Tiene la direccion de memoria de la cabeza de la lista
			int size_; ///Parametro de tipo entero que contiene el numero de elementos de la lista

			void setCabeza(NodoDonante * n){lista_=n;}; ///Metodo privado que permite modificar la cabeza. Se encuentra protegido para que solo se pueda hacer esta accion por medio de las funciones generales de una lista
			NodoDonante * getCabeza()const{return lista_;}; ///Metodo privado que permite obtener la direccion de memoria de la cabeza.Se encuentra protegido para que solo se pueda hacer esta accion por medio de las funciones generales de una lista
			void sizePlus(){size_++;};//Metodo privado para poder mantener la integridad del valor de size_,aumentando su valor. Es privado para evitar que el valor de size_ este corrupto
			void sizeMinus(){size_--;};//Metodo privado para poder mantener la integridad del valor de size_, disminuyendo su valor. Es privado para evitar que el valor de size_ este corrupto
		public:

			/**
			@brief Constructor de la clase ListaOrdenadaDonantes
				Carece de parametros. La lista se inicializa con 0 elementos y con la cabeza apuntando a NULL
			*/
			ListaOrdenadaDonantes(){
				lista_=NULL;
				size_=0;
			}

			//Observadores

			/**
			@brief Observador que comprueba si hay elementos en la lista
				Devuelve un valor booleano segun si la lista tiene o no elementos. Devuelve true cuando el puntero de la lista es NULL, es decir, esta vacia y size_ es 0.
				Devuelve false cuando no se cumplen ambas opciones.
			*/			
			inline bool isEmpty()const{if((lista_==NULL)&&(size_==0)){return true;}else{return false;}};

			/**
			@brief Observador que devuelve el numero de elementos de la lista
				Devuelve un tipo int que contiene el numero de elementos que tiene la lista
			*/
			inline int getSize()const{return size_;};


			/**
			@brief Observador que devuelve un valor booleano segun si la posicion pedida es valida
			@param pos Tipo int que debe pasarse a la funcion. Indica un posicion  de la lista

			Si el tamaño de la lista menos uno es mayor o igual que pos entonces devuelve true. Si no, devuelve false
			*/
			bool isValid(int pos)const;
			
			/**
			@brief Observador que devuelve un valor booleano segun si la posicion pedida es la ultima
			@param pos Tipo int que debe pasarse a la funcion. Indica un posicion  de la lista

			Si el tamaño de la lista menos uno, es igual que pos entonces devuelve true. Si no, devuelve false
			*/
			bool isLast(int pos)const;

			/**
			@brief Observador que devuelve el Donante de una posicion
			@param pos TIpo int que debe pasarse a la funcion. Indica una posicion de lalista

			Devuelve el donante de una determinada posicion. Si la posicion no existe devuelve el donante por defecto
			*/		
			Donante item(int pos)const;
		

			/**
			@brief Observador que devuelve  la posicion de un Donante a partir de una posicion
			@param d Donante que se busca en la lista
			@param from Entero que indica la posicion a partir de la cual se va a buscar al donante

			Devuelve la posicion del donante si existe en la lista, si el donante no existe en la lista devuelve -1
			*/
			int findItem(Donante d, int from)const;
				
			//Modificadores
		
			/**
			@brief Modificador que inserta un Donante ordenadamente
			@param d Tipo donante que contiene un Donante que se inserta
			Funcion que inserta por orden alfabetico los donantes. El nombre de los donantes debe seguir siempre el mismo formato, por ejemplo la primera letra del nombre y de los apellidos en mayuscula y el resto en minuscula
			*/	
			void insert(Donante d);

			/**
			@brief Modificador que elimina el donante de una posicion
			@param pos Entero que indica la posicion del elemento que se elimina.
			
			Busca el elemento de la posicion pos y lo elimina de la lista. Si lo encuentra devuelve true, si no devuelve false
			*/
			bool deletePosition(int pos);
	};


}
#endif








