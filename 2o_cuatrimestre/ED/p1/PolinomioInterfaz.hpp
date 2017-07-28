/*!
	@brief Interfaz de la clase Polinomio
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Polinomio
*/

#ifndef POLINOMIO_INTERFAZ_HPP_
#define POLINOMIO_INTERFAZ_HPP_

#include "Monomio.hpp"
#include <list>
using std::list;

/*!
	@namespace ed 
	@brief Espacio de nombres de la asignatura Estructuras de datos

*/
namespace ed{

	class PolinomioInterfaz{
		public:
			virtual int getGrado()const=0;
			virtual int getNumMonomio()const=0;
			virtual list<Monomio> getMonomios()const=0;
	
			virtual void setGrado(int grado)=0;
			virtual void setNumMonomio(int NumMonomio)=0;
			virtual void setMonomios(list<Monomio> Monomios)=0;
			
			virtual bool isEmpty()=0;
	};
}

#endif
