/*!
	@brief Fichero .hpp de la clase NodoDonante

	Implementa la clase NodoDonante,  dependiente de la clase Donante
	Esta clase permite implementar listas doblemente enlazadas de donantes.
*/


#ifndef NODODONANTE_HPP
#define NODODONANTE_HPP
#include "Donante.hpp"
/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/
namespace ed{

	class NodoDonante{
		private: 
			Donante donante_; /// donante_ Parametro de tipo donante que contiene la informacion de un donante
			NodoDonante * anterior_; /// anterior_ Parametro de tipo puntero a NodoDonante  que contiene la direccion del NodoDonante previo
			NodoDonante * siguiente_;/// siguiente_ Parametro de tipo puntero a NodoDonante  que contiene la direccion del NodoDonante siguiente
		public:

			/**
			@brief Constructor parametrizado de la clase NodoDonante
			@param d Tipo donante que será guardado en el nodo creado. Debe recibir un Donante obligatoriamente
			@param a Tipo puntero que dará la informacion de donde se encuentra el Nodo anterior al creado. Tiene como valor por defecto NULL
			@param s Tipo puntero que dará la informacion de donde se encuentra el Nodo siguiente al creado. Tiene como valor por defecto NULL

			Constructor parametrizado de la clase NodoDonante que debe recibir un Donante obligatoriamente y dos punteros. Uno al siguiente NodoDonante y otra al anterior. Ambos pueden decibir valores, aunque tienen como valor por defecto NULL
			*/
			NodoDonante(Donante d,NodoDonante * a=NULL, NodoDonante *s=NULL){
				donante_=d;
				anterior_=a;
				siguiente_=s;
			}
	

			///Observadores

			/**
			@brief Metodo constante que devuelve el Donante que contiene

				Metodo constante que devuelve el Donante que contiene el nodo, para permitir su tratamiento
			*/
			inline Donante getDonante()const{return donante_;};

			/**
			@brief Metodo constante que devuelve la direccion de memoria del nodo anterior
				Metodo constante que devuelve la direccion de memoria  que contiene el nodo anterior
			*/
			inline NodoDonante* getAnterior()const{return anterior_;};
			
			/**
			@brief Metodo constante que devuelve la direccion de memoria del nodo siguiente
				Metodo constante que devuelve la direccion de memoria que contiene el nodo siguiente
			*/
			inline NodoDonante* getSiguiente()const{return siguiente_;};

			/**
			@brief Metodo constante que devuelve un true si el nodo es cabeza
			Metodo que devuelve el un valor booleano segun si el nodo es el primero, es decir el puntero al nodo anterior es nulo
			*/
			inline bool isFirst()const{if(getAnterior()==NULL){return true;}else{return false;}};

			/**
			@brief Metodo constante que devuelve un true si el nodo es el ultimo
			Metodo que devuelve el un valor booleano segun si el nodo es el ultimo, es decir el puntero al nodo siguiente es nulo
			*/
			inline bool isLast()const{if(getSiguiente()==NULL){return true;}else{return false;}};
		
			///Modificadores

			/**
			@brief Metodo que permite modifica el valor del Donante por otro
				Metodo que no devuelve nada y recibe una referencia a un Donante que sustituye al donante del nodo que teniamos
			*/
			inline void setDonante(Donante &d){donante_=d;};

			/**
			@brief Metodo que permite modifica la direccion de memoria del nodo siguiente
				Metodo que no devuelve nada y recibe una direccion de memoria que será el nuevo nodo siguiente
			*/
			inline void setSiguiente( NodoDonante * s){siguiente_=s;};

			/**
			@brief Metodo que permite modifica la direccion de memoria del nodo anterior
				Metodo que no devuelve nada y recibe una direccion de memoria que será el nuevo nodo siguiente
			*/
			inline void setAnterior( NodoDonante* a){anterior_=a;};
	};





}







#endif
