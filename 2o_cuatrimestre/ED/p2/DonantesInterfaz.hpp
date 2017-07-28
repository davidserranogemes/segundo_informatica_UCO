/*!
	@brief Fichero .hpp de la clase DonantesInterfaz

	Especifica cualquier clase Donantes con los metodos que deben tener de forma obligatoria
*/


#ifndef DONANTESINTERFAZ_
#define DONANTESINTERFAZ_
#include "Donante.hpp"
/*!
@brief namespace de la asignatura Estructura de Datos
*/
namespace ed{

	/*!
	@brief Clase interfaz de Donantes
		Incluye los metodos virtuales puros de los observadores y de los modificadores
	*/
	class DonantesInterfaz{

		///Observadores puros
		
		/*!
		@brief Comprueba si la lista está vacia.
			Metodo constante. Funcion virtual pùra que debe ser redefinida
		*/
		virtual bool isEmpty()const=0;
		
		/*!
		@brief Comprueba si existe un Donante en la lista
			Método constante. Funcion virtual pura que debe ser redefinida
		*/
		virtual Donante searchDonante(Donante &d)const=0;

		///Modificadores
			
		/*!
		@brief Función que inserta un nuevo donante en la lista
			Funcion virtual pura que debe ser redefinida
		*/
		virtual void insertDonante(Donante &d)=0;


		/*!
		@bried Funcion que elimina un donante de la lista
			Funcion virtual pura quedebe ser redefiniiiidddda
		*/
		virtual bool deleteDonante(Donante &d)=0;

	};
}
#endif
