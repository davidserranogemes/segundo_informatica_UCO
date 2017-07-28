/*!
	@brief Fichero .hpp de la clase Vertice

	Implementa la clase Vertice, heredada de VerticeInterfaz
*/


#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>

#include "VerticeInterfaz.hpp"


/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/
namespace ed{


	/**
	@brief Clase Vertice, permite crear objetos de tipo Vertice
		Hereda de forma publica de VerticeInterfaz
	*/
	class Vertice:public VerticeInterfaz{
		private:
			//! label_ parametro de tipo entero  que refleja la etiqueta de un nodo
			int label_;

			//! data_ parametro de tipo string  que refleja el nombre de un nodo
			string data_;
		public:

			/**
			@brief Constructor parametrizado de la clase Vertice
			@param label tipo entero que da valora ala etiqueta. Valor por defecto -1
			@param data tipo string que da nombre al vertice. Valor por defecto ""
			
			Contructor de la clase vertice, inicializando a unos valores por defecto para facilitar su suo con memoria dinamica
		
			*/

			Vertice(int label=-1, string data=""){
				label_=label;
				data_=data;
			}
			
			/**
			@brief Observador del termino data.
			@return devuelve un string con el valor del dato del vertice

			Funcion inline constante que devuelve el valor de data_

			*/


			inline string getData()const{
				return data_;
			}

			/**
			@brief Observador del termino label
			@return devuelve un entero con el valor de la etiqueta del vertice

			Funcion inline constante que devuelve el valor de label_

			*/

			inline int getLabel()const{
				return label_;
			}


			/**
			@brief Modificador del termino data.
			@param data tipo string que sustituye el valor actual de data_


			Funcion inline que recibe un string y modifica el valor de data_

			*/
			inline void setData(const string data){
				data_=data;
			}


			/**
			@brief Modificador del termino label.
			@param label tipo intque sustituye el valor actual de label_


			Funcion inline que recibe un entero y modifica el valor de label_

			*/
			inline void setLabel(const int label){
				label_=label;
			}


			/**
			@brief Sobrecarga del operador = para dos vertices.
			@param v Referencia constante a un elementode tipo vertice
			@return tipo referencia a vertice que sustituye el valor del vertice que llama
		
			Sobrecarga del operador Vertice para facilitar el trabajo con el este TAD

			*/


			Vertice &operator=(const Vertice &v);
	};


}


#endif
