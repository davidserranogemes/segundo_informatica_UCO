#ifndef MONTICULO_DONANTES_INTERFAZ_HPP
#define MONTICULO_DONANTES_INTERFAZ_HPP

/*!
	@brief Interfaz de la clase Monticulo interfaz
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Donante	
*/

#include "Donante.hpp"

/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/
namespace ed{
	/**
	@brief Clase MonticuloDonantesInterfaz, esppecifica la clase MonticuloDonantes
		Especifica los metodos minimos de una clase MonticuloDonantes
	*/
	
	class MonticuloDonantesInterfaz{
		public:
			///Observadores

			/**
				@brief Metodo virtual puro que devuelve un booleano segun el estado del heap
				Metodo virtual puro que devuelve un tipo booleano segun si hay algun elemento en el heap o no. Si esta vacio devuelve true, si tiene algun donante devuelve false. Es un metodo constante
			*/
			virtual bool isEmpty()const=0;

			/**
			@brief Metodo virtual puro que devuelve el donante en la cima.
				Metodo virtual puro que debe permitir la interaccion con el heap. Devuelve el donante de la cabeza, siendo este el que menos veces ha donado. Actua de forma constante.			
			*/
			virtual Donante Top()const=0;

			///Modificadores
			
			/**
			@brief Metodo virtual puro, devuelve void e inserta un donante en el heap
			@param d El donante que se va a insertar en el heap
			Metodo virtual puro que permite insertar un nuevo donante en el heap.
			*/
			virtual void insert(Donante d)=0;

/**
			@brief Metodo virtual puro, devuelve void y elminina el donante de cima.
			Metodo virtual puro que permite eliminar el donante de la cabeza, debiendose reordenar el heap
			*/
			virtual void remove()=0;

	};

}
#endif
