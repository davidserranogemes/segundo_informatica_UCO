/*!
	@brief Fichero .hpp de la clase Donante

	Implementa la clase donante, heredada de DonanteInterfaz
*/


#ifndef DONANTE_HPP_
#define DONANTE_HPP_

#include <string>
#include <cassert>
#include <iostream>
#include "DonanteInterfaz.hpp"
/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/

using std::istream;
using std::ostream;
namespace ed{
	/**
	@brief Clase donante, permite crear objetos de tipo Donante
		Hereda de forma publica de DonanteInterfaz
	*/

	class Donante:public DonanteInterfaz{
		private:

			//! Nombre_ parametro de tipo string  que refleja en nombre del donante
			string Nombre_; 
			//! Apellidos_ parametro de tipo string que refleja los apellidos del donante
			string Apellidos_;
			
			//! GrupoSanguineo_ parametro de tipo string que refleja el grupo sanguineo del donante,	que solo puede tomar un conjunto limitado de valores: A, B, AB, 0.
			string GrupoSanguineo_; 
			
			//! RH_ parametro de tipo bool que refleja el valor RH del donante. -El valor true significa RH+ El valor false significa RH-
			bool RH_;
			
			//!donaciones_ parametro de tipo int que refleja el numero de donaciones realizadas
			int Donaciones_;

			/**
			@brief Metodo privado que permite modificar las donaciones de un individuo.
			Dado que las donaciones solo deberian aumentar, se expone como publico un metoo que las incrementa, no se expone como publico, para evitar que se incremente el numero de donaciones si no es con una donacion.
			*/
			void setDonaciones(int donaciones){Donaciones_=donaciones;};
		public:

			/*!
			@brief Constructor por defecto de Donante
			@param nombre Tipo string, define el primer nombre del donante. Valor por defecto: "John"
			@param apellidos Tipo string, define los apellidos del donante. Valor por defecto: "Doe"
			@param GrupoSanguineo Tipo string, define el grupo sanguineo del donante.Valor por defecto "A" Ver la funcion setGrupoSanguineo
			@see setGrupoSanguineo
			@param	RH Tipo bool, define el RH del donante, true signidica RH+ y false RH-. Valor por defecto true
			@param donaciones tipo int, define el numero de donaciones que ha realizado el donante

			Constructor de un donante con valores por defecto para cada variable, utiliza los modificadores para alterar los cambios del objeto creado.
				Valores por defecto:
					Nombre: "John"
					Apellidos: "Doe"
					Grupo Sanguineo= "A"
					RH: true
			*/
			Donante(string nombre="John",string apellidos="Doe",string GrupoSanguineo="A",bool RH=true, int donaciones=0){
					setNombre(nombre);
					setApellidos(apellidos);
					setGrupoSanguineo(GrupoSanguineo);
					setRH(RH);
					setDonaciones(donaciones);
			}

			/*! 
			@brief Constructor de copia de la clase Donante
			@param d Referencia constante a un objeto Donante ya creado
	
			Constructor de copia de la clase Donante que recibe uno ya creado del que copia la informacion y la introduce en el nuevo objeto			
			*/
			Donante(const Donante &d){
					setNombre(d.getNombre());
					setApellidos(d.getApellidos());
					setGrupoSanguineo(d.getGrupoSanguineo());
					setRH(d.getRH());
					setDonaciones(d.getDonaciones());
			}
	///Observadores de la clase Donante
			/*!
			@brief Observador del parametro Nombre_
			@return Nombre_ Devuelve el parametro privado Nombre_ de tipo string					
			Devuelve un string que contiene el valor de nombre_
			*/
			inline string getNombre()const{return Nombre_;};
			
			/*!
			@brief Observador del parametro Apellidos_
			@return Apellidos_ Devuelve el parametro privado Apellidos_ de tipo string
				Devuelve un string que contiene el valor de Apellidos_
			*/
			inline string getApellidos()const{return Apellidos_;};

			/*!
			@brief Observador del parametro GrupoSanguineo_
			@return GrupoSanguineo_ Devuelve el parametro privado GrupoSanguineo_ de tipo string
				Devuelve un string que contiene el valor de GrupoSanguineo_
			*/
			inline string getGrupoSanguineo()const{return GrupoSanguineo_;};

			/*!
			@brief Observador del parametro RH_
			@return RH_ Devuelve el parametro privado RH_ de tipo string
				Devuelve un bool que contiene el valor de RH_
			*/
			inline bool getRH()const{return RH_;};

			/**
			@brief Observador del parametro Donaciones_
			@return Donaciones_ Devuelve el parametro privado donaciones_
				Devuelve el numero de donaciones realizadas
			*/
			inline int getDonaciones()const{return Donaciones_;};


	///Modificadores
			
			/*!
			@brief Modificador del parametro Nombre_
			@param nombre nuevo nombre del donante, de tipo string
			
				Modificador del atributo nombre de la clase donante. Requiere el paso de un tipo string 				
			*/
			inline void setNombre(string nombre){Nombre_=nombre;};
	
			/*!
			@brief Modificador del parametro Apellidos_
			@param apellidos nuevo nombre del donante, de tipo string
			
				Modificador del atributo apellidos de la clase donante. Requiere el paso de un tipo string 				
			*/
			inline void setApellidos(string apellidos){Apellidos_=apellidos;};

			/*!
			@brief Modificador del parametro GrupoSanguineo_
			@param GrupoSanguineo nuevo GrupoSanguineo del donante del donante, de tipo string
			
				Modificador del atributo GrupoSanguineo de la clase donante. Requiere el paso de un tipo string con unos valores posibles determinados:
					"A","B", "AB" o "0"				
			*/
			inline void setGrupoSanguineo(string GrupoSanguineo){

						assert((GrupoSanguineo=="A")or(GrupoSanguineo=="B")or(GrupoSanguineo=="AB")or(GrupoSanguineo=="0"));
						GrupoSanguineo_=GrupoSanguineo;
						};

			/*!
			@brief Modificador del parametro RH_
			@param RH nuevo RH del donante, de tipo bool
			
				Modificador del atributo RH de la clase donante. Requiere el paso de un tipo booleano. True significa RH+ y false RH-				
			*/
			inline void setRH(bool RH){RH_=RH;};

			/*!
			@brief Modificador del parametro Donaciones_, mediante un incremento en uno
					
			Modificador de las donaciones, unicamente permite aumentar las donaciones, limitando el tratamiento del Donante, pues no tiene sntido disminuir el numero de donaciones realizadas
			*/

			inline void DonacionesInc(){Donaciones_++;};

			/*!
			@brief Metodo para la escritura de los datos de un donante
				Metodo que permite escribir todos los datos de un donante utilizando la entrada por teclado
				Utiliza la sobrecarga del operador <<
			*/
			void leerDonante();
			
			/*!
			@brief Metodo para la lectura de los datos de un donante
				Metodo que permite leer todos los datos de un donante utilizando la salida por pantalla
				Utiliza la sobrecarga del operador <<		
			*/
			void escribirDonante();

			/*!
			@brief Metodo para la modificacion de los datos de un donante
				Metodo que permite leer los datos de un donante de forma selectiva,pudiendo modificar o no sus datos utilizando la salida por pantalla

			*/
			void modificarDonante();			
			
			/*!
			@brief Sobrecarga del operador = para Donante
			@param d referencia constante al Donante al que se iguala el donante de la izquierda de la expresion
				Sobrecarga del operador = para permitir asignar directamente los datos de un Donante a otro

			*/
			Donante &operator=(const Donante &d);

			/*!
			@brief Sobrecarga del operador == para Donante
			@param d referencia constante al Donante con el que se compara el donate de la izquierda de la expresion
			@return boolValor Devuelve un tipo booleano segun el valor de Donaciones_
				Sobrecarga del operador == para poder comprobar si dos donantes tienen el mismo numero de donaciones. En ese caso devuelve true, en caso contrario devuelve false

			*/
			bool operator==(const Donante &d);

			/*!
			@brief Sobrecarga del operador <= para Donante
			@param d referencia constante al Donante con el que se compara el donate de la izquierda de la expresion
			@return boolValor Devuelve un tipo booleano segun el valor de Donaciones
				Sobrecarga del operador <= para poder comparar el numero de donaciones realizadas por un donante. Devuelve true si el Donante que llama tiene un numero menor o igual de donaciones que el pasado como referencia. Devuelve false en el caso contrario

			*/
			bool operator<=(const Donante &d);


			/*!
			@brief Sobrecarga del operador >> mediante una funcion friend
			@param stream Referencia a un tipo istream del cual se leen los datos que se introducen en d
			@param d Referencia a un tipo Donante en el que se introducen lso datos que recibe de stream
			@return stream Tipo istream

				Sobrecarga del operador >> lo que permite leer directamente desde un fichero el tipo Donante, funcion de tipo friend
			*/
			friend istream &operator>>(istream &stream, Donante &d);
			
			/*!
			@brief Sobrecarga del operador << mediante una funcion friend
			@param stream Referencia a un tipo ostream en el que se escriben los datos del parametro d
			@param d Referencia a un tipo Donante en el que se leen los datos para que los use stream 
			@return stream Tipo ostream

				Sobrecarga del operador << lo que permite escribir directamente a un fichero la informacion de un Donante, funcion de tipo friend
			*/			 
			friend ostream &operator<<(ostream &stream, Donante const &d);

	};



}






#endif





















