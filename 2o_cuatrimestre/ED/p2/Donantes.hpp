/*!
	@brief Fichero .hpp de la clase Donantes

	Implementa la clase donante, heredada de DonantesInterfaz y requiere una clase Donante
*/

#ifndef DONANTES_HPP_
#define DONANTES_HPP_
#include <string>
#include <iostream>
#include <cassert>

#include "NodoDonante.hpp"
#include "Donante.hpp"
#include "DonantesInterfaz.hpp"
#include "ListaOrdenadaDonantes.hpp"

/*!
@brief namespace de la asignatura Estructura de Datos
*/
namespace ed{

	class Donantes : public DonantesInterfaz{
		private:
			int size_;///Parametro de tipo entero que contiene el tamaño de la lista
			ListaOrdenadaDonantes lista_;///Parametro de ListaOrdenadaDonantes que contiene los donantes
			
			
		public:	

			/**
			@brief Constructor de la clase Donantes
			@param size Indica el numero de elementos que tendra la lista al inicio. Debe ser un valor entero no negativo

			Inicializa el valor size_ al valor que deba tener segun el tamaño de la lista. Obliga a que se le introduzcan los elementos por teclado si se introduce un valor para size distinto de 0
			*/
			Donantes(int size=0){
				assert(size>=0);				
				Donante d;				
				size_=size;
				while(size){
					d.leerDonante();
					lista_.insert(d);
					size--;
					if(size)
						std::cout<<"Pulse enter para continuar introduciendo elementos"<<std::endl;
				}
					
			}

			/**
			@brief Constructor de copia
			@param d Referencia a un tipo Donantes que aporta todos los datos del nuevo elemento construido

			Copia los elementos de la lista pasada como referencia en el nuevo elemento y actualiza el valor de size_
			*/
			Donantes(const Donantes &d){
				for(int i=0;i<d.getSize();i++){
					lista_.insert(d.getDonante(i));
					size_=lista_.getSize();
				}
			}	
			///Observadores		

			/**
			@brief Observador que devuelve el tamaño de la lista
			Funcion constante que devuelve un entero con el tamaño de la lista
			*/
			inline int getSize()const{return size_;};

			/**
			@brief Observador que devuelve un valor booleano segun si la lista esta vacia o no
			Si la lista esta vacia devuelve true y si la lista no esta vacia devuelve false
			*/
			inline bool isEmpty()const{return lista_.isEmpty();};

			/**
			@brief Funcion que busca en la lista el donante que se pasa como referencia
			@param d Donante que se quiere encontrar en la lista de Donantes
			Devuelve el Donante que se encuentra en la lista con mismos nombres y apellidos si existe el donante pasado por referencia. Devuelve el donante por defecto si no existe
			*/
			inline Donante searchDonante(Donante &d)const{
					int pos=lista_.findItem(d,0);
					return lista_.item(pos);
			}

			/**
			@brief Funcion que busca un donante por su posicion
			@param pos posicion en la que se encuentra un donante

			Busca una posicion y devuelve el Donante asignado, si no existe la posicion devuelve el donante por defecto
			*/
			inline	Donante getDonante(int pos)const{
					return lista_.item(pos);
			}


			/**
			@brief Funcion que inserta un donante en la lista ordenadamente
			@param d Referencia a un Donante que se introduce en una lista

				Funcion que introduce un donante en la lista de forma ordenada, en eeste caso alfabeticamente. Se debe mantener el formato en los nombres y apellidos			
			*/
			void insertDonante(Donante &d){//
				lista_.insert(d);
				size_++;;
			}

			/**
			@brief Funcion que permite modificar los datos de un Donante
			@brief d Referencia a un donante que se busca en la lista y se modifica

				La funcion busca si el donante existe, si existe pregunta  campo por campo si se desea modificar. En caso de que se modifiquen los nombres o los apellidos lo reordena en la lista
			*/
			void ModificarDonante(Donante &d);
				
			/**
			@brief Funcion que permite eliminar un Donante
			@param d Referencia a un donante que se busca en la lista y se elimina

				La funcion busca el donante pasado como referencia y lo elimina si existe, devolviendo true. Si no existe se devuelve false
			*/
			bool deleteDonante(Donante &d);//
			

			/**
			@brief Funcion que lee los donantes por teclado

				Pide campo a campo que se introduzcan los datos, hasta que se introduzca un numero distinto de 1
				Los nombres y apellidos pueden contener espacios.
			*/
			void leerDonantes();

			/**
			@brief Funcion que escribe los Donantes por pantalla
			Escribe los datos de todos los donantes por pantalla:
				Nombre:
				Apellidos:
				Grupo sanguineo:
				RH:
			*/
			void escribirDonantes()const;


			/*!
			@brief Sobrecarga del operador >> mediante una funcion friend
			@param stream Referencia a un tipo istream del cual se leen los datos que se introducen en d
			@param d Referencia a un tipo Donantes en el que se introducen los datos que recibe de stream
			@return stream Tipo istream

				Sobrecarga del operador >> lo que permite leer directamente desde un fichero el tipo Donante, funcion de tipo friend
				Para leer requiere que cada campo se separe con / y cada Donante con '\n'
				En el ultimo donante se debe añadir el campo EOF
				nombre/apellidos/grupoSanguineo/positivo/EOF
			*/
			friend istream &operator>>(istream &stream, Donantes &d);

			/*!
			@brief Sobrecarga del operador << mediante una funcion friend
			@param stream Referencia a un tipo ostream en el que se escriben los datos del parametro d
			@param d Referencia a un tipo Donantes en el que se leen los datos para que los use stream 
			@return stream Tipo ostream

				Sobrecarga del operador << lo que permite escribir directamente a un fichero la informacion de un Donante, funcion de tipo friend
				Cada campo se separa con / y cada donante con '\n'
				En el ultimo donante se añade el campo EOF como fin de fichero
				nombre/apellidos/grupoSanguineo/positivo/EOF
			*/
			friend ostream &operator<<(ostream &stream, Donantes const &d);






	};




};









#endif
