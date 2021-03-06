/*!
	@brief Interfaz de la clase Monomio
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Monomio	
*/

#ifndef MONOMIOINTERFAZ_HPP
#define MONOMIOINTERFAZ_HPP

/*!
	@namespace ed 
	@brief Espacio de nombres de la asignatura Estructuras de datos

*/
namespace ed{

	class MonomioInterfaz{
		public:
			virtual float getCoeficiente()const=0;
			virtual int getGrado()const=0;

			virtual void setCoeficiente(const float Coeficiente)=0;
			virtual void setGrado(const int Grado)=0;

	};
}

#endif

