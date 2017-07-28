#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>
#include <cmath>
#include <list>
#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::list;

namespace ed{

	class Polinomio:PolinomioInterfaz{
		private:
			int grado_;					
			int numMonomio_;
			list<Monomio> monomio_;
			
		public:

			/*!
			@brief Constructor por defecto de la clase Polinomio
			@param numMonomio Numero de monomios que tendra el polinomio. Valor por defecto =0
			@pre numMonomio>=0
			@see unirPolinomio
			Crea el polinomio a partir del numero de monomios que va a tener. Pide los datos de cada monomio individualmente y rellena el grado
			Invoca a unirPolinomio para ajustar el polinomio
			*/
			Polinomio(int numMonomio=0){
				assert(numMonomio>=0);
				Monomio auxMon;
				int auxGrado=0;
				for(int i=0;i<numMonomio;i++){
					cin>>auxMon;
					monomio_.push_back(auxMon);
					if(auxGrado<auxMon.getGrado()){
						auxGrado=auxMon.getGrado();
					}
					
				}
				grado_=auxGrado;
				unirPolinomio();

			}

			/*!
			@brief Constructor por defecto de la clase Polinomio
			@param p referencia constante a un Polinomio

			Crea el polinomio a partir de otro polinomio del que recibe los datos.
			*/
			Polinomio(const Polinomio &p){
				grado_=p.getGrado();
				numMonomio_=p.getNumMonomio();
				monomio_=p.getMonomios();
			}


			/*!
			@brief Observador del grado
			@return grado_ Devuelve el grado del polinomio
			*/
			inline int getGrado()const{return grado_;};
			
			/*!
			@brief Observador del numero de monomios
			@return numeroMonomios Devuelve el numero de monomios del polinomio
			*/			
			inline int getNumMonomio()const{return monomio_.size();};

			/*!
			@brief Observador de monomios_
			@return monomios_ Devuelve la lista de monomios del polinomio
			*/
			inline list<Monomio> getMonomios()const{return monomio_;};
	

			
			void setMonomios(list<Monomio> Monomios);

			/*!
			@brief Modificador del grado del polinomio
			@param grado Grado que va a terner el polinomio
			@pre grado>=0
			*/
			inline void setGrado(int grado){assert(grado>=0);grado_=grado;};

			/*!
			@brief Modificador del numero de monomios
			@param NumMonomio cantidad de monomios que va a tener el monomio
			@pre NumMonomio>=0
			*/
			inline void setNumMonomio(int NumMonomio){assert(NumMonomio>=0);numMonomio_=NumMonomio;};			

			void unirPolinomio();

			/*!
			@brief Comprueba si hay monomios en la lista
			@return true si esta vacia
			@return false si no esta vacia
			*/
			inline bool isEmpty(){
				if(monomio_.size()==0){
					return true;
				}else{
					return false;
				}
			}

			void leerPolinomio();
			void escribirPolinomio();
			
			Polinomio operator+(const Polinomio &p)const;
			Polinomio operator*(const Polinomio &p)const;
			Polinomio operator=(const Polinomio &p);

			friend istream &operator>>(istream &stream, Polinomio &p);
			friend ostream &operator<<(ostream &stream, Polinomio &p);
			

			
			int obtenerResultados(const int &i);


	};

}



#endif















