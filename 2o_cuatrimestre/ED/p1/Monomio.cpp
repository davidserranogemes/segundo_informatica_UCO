/*!
	@brief Fichero .cpp de la clase monomio
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Monomio	
*/

#include "Monomio.hpp"

/*!
	@namespace ed 
	@brief Espacio de nombres de la asignatura Estructuras de datos

*/
namespace ed{
	/*!
	@brief Observador del coeficiente del monomio
	@return _Coeficiente Valor del coeficiente del monomo como float
	*/

	inline float Monomio::getCoeficiente()const{
		return _Coeficiente;
	}
	/*!
	@brief Observador del grado del monomio
	@return _Grado Valor del grado del monomio como int
	*/
	inline int Monomio::getGrado()const{
		return _Grado;
	}
	/*!
	@brief Modificador del coeficiente del monomio
	*/

	inline void Monomio::setCoeficiente(const float Coeficiente){
		_Coeficiente=Coeficiente;
	}
	/*!
	@brief Modificador del grado del monomio
	@pre Grado>=0
	*/
	inline void Monomio::setGrado(const int Grado){
		assert(Grado>=0);
		_Grado=Grado;
	}
	/*!
	@brief Lee por pantalla los datos del monomio
		Muestra por pantalla mensajes que guian al usuario para que introduzca el grado y el coeficiente de un monomio. Luego utiliza los modificadores para introducir esos datos en el objeto
	*/
	void Monomio::leerMonomio(){
		int auxGrado;
		float auxCoeficiente;
		
		cout<<endl<<"Introduzca el grado del monomio. No debe ser negativo: ";
		cin>>auxGrado;
		
		cout<<endl<<"Introduzca el coeficiente del monomio: ";
		cin>>auxCoeficiente;

		setGrado(auxGrado);
		setCoeficiente(auxCoeficiente);
	}
	/*!
	@brief Escribe en la pantalla los datos del Monomio de forma adecuada
		Escribe el monomio por pantalla segun los valores del mismo monomio, para mantener la uniformidad de la realidad
			Si el grado es 0 no muestra la variable x
			Si el grado es 1 no muestra el grado 
			Si el coeficiente es -1 muestra solo -x y el grado
			Si el coeficiente es +1 muestra solo x y el grado
			Si el coeficiente es 0 muestra 0
			Si el coeficiente es positivo pone un + delante del monomio
	*/

	void Monomio::escribirMonomio()const{
		bool zgflag=false;	///Indica si el grado es 0	
		bool ogflag=false;	///Indica si el grado es 1
		bool zcflag=false;	///Indica si el coeficiente es 0
		bool opcflag=false;	///Indica si el coeficiente es +1
		bool oncflag=false;	///Indica si el coeficiente es -1
		bool posflag=false;	///Indica si el coeficiente es positivo

		if(getGrado()==0){
			zgflag=true;
		}else{
			if(getGrado()==1){
				ogflag=true;
			}
		}
		if(getCoeficiente()>=0){
			posflag=true;
		}
		if(getCoeficiente()==0){
			zcflag=true;
		}else{
			if(getCoeficiente()==1){
				opcflag=true;
			}else{
				if(getCoeficiente()==-1){
					oncflag=true;
				}
			}
		}
		if(posflag){
			cout<<"+";
		}
		if(zcflag){///Coeficiente=0, el monomio es 0
			cout<<"0 ";
		}else{
			if(zgflag){///Grado=0 simplemente es el numero
				cout<<getCoeficiente()<<" ";
			}else{
				if(opcflag){///Grado distinto 0, coeficiente +1
					cout<<"x^"<<getGrado()<<" ";
				}else{
					if(oncflag){///Grado distinto de 0, coeficiente -1
						cout<<"-x^"<<getGrado()<<" ";
					}else{if(ogflag){
						cout<<getCoeficiente()<<"x";
						}else{///Expresion standard
							cout<<getCoeficiente()<<"x^"<<getGrado();
						}
					}
				}
			}
		}
	}
	/*!
	@brief Sobrecarga del operador =
	@param m recibe la referencia de un Monomio constante
	@return *this Delvuelve el objeto que invoca la funcion
		
		Modifica los datos del objeto que invoca introduciendo los del objeto que se le asigna con el operador =
	*/

	Monomio Monomio::operator=(const Monomio &m){
		setGrado(m.getGrado());
		setCoeficiente(m.getCoeficiente());
		return *this;
		}

	/*!
	@brief Sobrecarga del operador *
	@param m recibe la referencia de un Monomio constante
	@return auxMonomio Devuelve un Monomio que contiene los datos del producto del monomio que invoca y del monomio referenciado
		
		Realiza el producto del monomio que invoca y del referenciado sin modificar los datos de ninguno de ellos
	*/
	Monomio Monomio::operator*(const Monomio &m)const{
		Monomio auxMonomio;
		auxMonomio.setGrado(getGrado()+m.getGrado());
		auxMonomio.setCoeficiente(getCoeficiente()*m.getCoeficiente());
		
		return auxMonomio;
	}

	/*!
	@brief Calcula el valor del monomio para un valor x
	@param xValor recibe la referencia de un int constante
	@return auxInt devuelve un entero que es el resultado de la evaluacion del polinomio
		
		Eleva xValor a el grado y multiplica el resultado por el coeficiente. Devuelve dicho entero.
		Requiere la libreria compilacion con -lm
	*/
	int Monomio::resultadoMonomio(const int &xValor){
		int auxInt;
		auxInt=getCoeficiente()*pow(xValor,getGrado());
		return (auxInt);
	}
	
	/*!
	@brief Sobrecarga del operador >>
	@param stream recibe una referencia a un flujo de datos
	@param m recibe una referencia a un monomio que se va a modificar
	@return stream devuelve el flujo de datos referenciado
	@see leerMonomio
		Sobrecarga del operador >> lo que permite leer directamente con cin>> un monomio, facilitando dicha tarea. Invoca a la funcion leerMonomio
	*/
	istream &operator>>(istream &stream, Monomio &m){
		m.leerMonomio();
		return stream;
	}
	
	/*!
	@brief Sobrecarga del operador <<
	@param stream recibe una referencia a un flujo de datos
	@param m recibe una referencia a un monomio que se va a mostrar
	@return stream devuelve el flujo de datos referenciado
	@see escribirMonomio
		Sobrecarga del operador << lo que permite escribir directamente con cout<< un monomio, facilitando dicha tarea. Invoca a la funcion escribirMonomio
	*/	
	ostream &operator<<(ostream &stream, Monomio const &m){
		m.escribirMonomio();
		return stream;
	}

}














