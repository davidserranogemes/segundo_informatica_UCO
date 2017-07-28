/*!
	@brief Fichero .hpp de la clase Monomio

	Implementa la clase monomio, heredada de MonomioInterfaz
*/


#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include "MonomioInterfaz.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
/*!
	@namespace ed 
	@brief Espacio de nombres de la asignatura Estructuras de datos

*/
namespace ed{
	class Monomio:public MonomioInterfaz{
		private:
			float _Coeficiente;
			int _Grado;
		public:

				/*!
					@brief Constructor por defecto de la clase Monomio.
					@param Coeficiente Valor del coeficiente del monomio. Valor por defecto 1.
					@param Grado Valor del grado del monomio. Valor por defecto 0.
					@pre Grado>=0

					Crea el monomio a partir de los valores pasados al constructor o usando los que ya vienen por defecto en  el caso de que no se pasen.
						

				*/
				inline Monomio(const float Coeficiente=1, const int Grado=0){
					assert(Grado>=0);
					_Coeficiente=Coeficiente;
					_Grado=Grado;
				}
					/*!
					@brief Constructor de copia
					@param Coeficiente Valor del coeficiente del monomio. Valor por defecto 1.
					@pre Grado del Monomio referenciado >=0

					Copia los valores del monomio referenciado para crear el nuevo Monomio
				*/
				inline Monomio(const Monomio &M){
					assert(M.getGrado()>=0);
					_Grado=M.getGrado();
					_Coeficiente=M.getCoeficiente();
				}
				

				float getCoeficiente()const;
				int getGrado()const;
				void setCoeficiente(const float Coeficiente);
				void setGrado(const int Grado);

				void leerMonomio();
				void escribirMonomio()const;

				Monomio operator=(const Monomio &m);
				Monomio operator*(const Monomio &m)const;
				
				int resultadoMonomio(const int &xValor);

				friend istream &operator>>(istream &stream, Monomio &m);
				friend ostream &operator<<(ostream &stream, Monomio const &m);
	};

}



#endif
