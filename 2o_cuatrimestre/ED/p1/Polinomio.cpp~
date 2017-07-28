/*!
	@brief .cpp de la clase Polinomio
		
	Especifica que observadores y modificadores son obligatorios en cualquier clase Monomio	
*/

#include "Polinomio.hpp"
#include "Monomio.hpp"

/*!
	@namespace ed 
	@brief Espacio de nombres de la asignatura Estructuras de datos

*/
namespace ed{

	/*!
	@brief UnirPolinomio uniforma el polinomio
		Uniforma el polinomio evitando que haya varios monomios con el mismo grado separados, reduciendo el numero de terminos que tiene el polinomio si es necesario
	*/
	void Polinomio::unirPolinomio(){
			list<Monomio>::iterator j;	
			list<Monomio>::iterator i;
			bool control;
			for(i=monomio_.begin();i!=monomio_.end();i++){
				for(j=i,control=false;j!=monomio_.end();j++){
					if(!control){
						control=true;//la primera iteracion es sobre el mismo elemento, no interesa.
					}else{
						if(i->getGrado()==j->getGrado()){
							i->setCoeficiente(i->getCoeficiente()+j->getCoeficiente());
							monomio_.erase(j);
							j--;
						}
					}
				}
			}
			setNumMonomio(monomio_.size());
	}

	/*!
	@brief Modificador de la lista de monomios.
	@param Monomios Lista de monomios que se pasa por valor
	
		Modificador de la lista de monomios, cambiando la del polinomio por el valor de la lista que se pasa por valor. Modifica tambien el numero de monomios y el grado si es necesario.
	*/
	void Polinomio::setMonomios(list<Monomio> Monomios){
		list<Monomio>::iterator i;
		monomio_=Monomios;
		setNumMonomio(monomio_.size());
		setGrado(0);	
		for(i=monomio_.begin();i!=monomio_.end();i++){
			if(i->getGrado()>getGrado()){
				setGrado(i->getGrado());
			}
		}
	}

	/*!
	@brief Lee por pantalla los datos del polinomio
		Muestra por pantalla mensajes que guian al usuario para que introduzca el grado y el coeficiente de un monomio. Luego utiliza los modificadores para introducir esos datos en la lista de monomios. Lee un numero de monomios igual al numero de monomios del polinomio
	*/
	void Polinomio::leerPolinomio(){
		int aux;
		list<Monomio>::iterator j;	
		Monomio auxMon;
		int max;
		cout<<"Introduce el numero de elementos del polinomio."<<endl;
		cin>>aux;
		setNumMonomio(aux);
		while(monomio_.size()!=0){
			monomio_.erase(monomio_.begin());
		}
		for(int i=0;i<aux;i++){
			cin>>auxMon;
			monomio_.push_back(auxMon);
			if(max<auxMon.getGrado()){
				max=auxMon.getGrado();
			}
		}
		unirPolinomio();
	}

	/*!
	@brief Escribe por pantalla los datos del polinomio usando para ello la funcion escribirMonomio en cada monomio de la lista
	*/
	void Polinomio::escribirPolinomio(){
		list<Monomio>::iterator i;
		for(i=monomio_.begin();i!=monomio_.end();i++){
			cout<<(*i);
		}
		cout<<endl;

	}
	
	/*!
	@brief Sobrecarga del operador +
	@param p recibe la referencia de un Polinomio constante
	@return aux Devuelve un Polinomio que contiene los datos de la suma  del polinomio que invoca y del polinomio referenciado
		
		Realiza la suma del polinomio que invoca y del referenciado sin modificar los datos de ninguno de ellos
	*/
	Polinomio Polinomio::operator+(const Polinomio &p)const{
		Polinomio aux;
		list<Monomio> auxParam;
		list<Monomio> auxRes;
		list<Monomio>::iterator i;
		list<Monomio>::iterator j;
		bool sflag=false;//Avisa de que se realiza una suma en esa iteracion
	

		auxRes=getMonomios();
		auxParam=p.getMonomios();

		for(i=auxParam.begin();i!=auxParam.end();i++){
			sflag=false;

			for(j=auxRes.begin();j!=auxRes.end();j++){
				if(i->getGrado()==j->getGrado()){
					sflag=true;
					j->setCoeficiente(j->getCoeficiente()+i->getCoeficiente());
					break;///impide que el mismo monomio se sume dos veces
				}
			}
			if(!sflag){
				auxRes.push_back(*i);///Si no se ha sumado con otro monomio significa que es un monomio de grado nuevo, por lo que se añade
			}	
			
		}

		aux.setNumMonomio(auxRes.size());
		if(getGrado()>p.getGrado())
			aux.setGrado(getGrado());
		else
			aux.setGrado(p.getGrado());
		aux.setMonomios(auxRes);
		return aux;
	}

	/*!
	@brief Sobrecarga del operador *
	@param p recibe la referencia de un Polinomio constante
	@return aux Devuelve un Polinomio que contiene los datos del producto  del polinomio que invoca y del polinomio referenciado
	@see unirPolinomio	
		Realiza el producto el polinomio que invoca y del referenciado sin modificar los datos de ninguno de ellos
	*/
	Polinomio Polinomio::operator*(const Polinomio &p)const{
		Polinomio aux;
		Monomio sumator;
		list<Monomio> auxParam;
		list<Monomio> auxRes;
		list<Monomio> auxList;
		list<Monomio>::iterator i;
		list<Monomio>::iterator j;		
		int max=0;		
		int elem;


		auxRes=getMonomios();
		auxParam=p.getMonomios();

		for(i=auxParam.begin();i!=auxParam.end();i++){
			for(j=auxRes.begin();j!=auxRes.end();j++){
				sumator.setGrado(i->getGrado()+j->getGrado());
				sumator.setCoeficiente(i->getCoeficiente()*j->getCoeficiente());
				auxList.push_back(sumator);

			}
		}
		aux.setMonomios(auxList);
		aux.unirPolinomio();

		return aux;
}

	/*!
	@brief Sobrecarga del operador =
	@param p recibe la referencia de un polinomio constante
	@return *this Delvuelve el objeto que invoca la funcion
		
		Modifica los datos del objeto que invoca introduciendo los del objeto que se le asigna con el operador =
	*/

	Polinomio Polinomio::operator=(const Polinomio &p){
			setMonomios(p.getMonomios());
			setGrado(p.getGrado());
			setNumMonomio(p.getNumMonomio());
			return *this;
	}


	/*!
	@brief Calcula el valor del polinomio para un valor x
	@param i recibe la referencia de un int constante
	@return valie devuelve un entero que es el resultado de la evaluacion del polinomio
	@see resultadoMonomio
		Utiliza el valor i como parametro de resultadoMonomio
	*/
	int Polinomio::obtenerResultados(const int &i){
		list<Monomio>::iterator j;
		int value=0;

		for(j=monomio_.begin();j!=monomio_.end();j++){
			value=value+j->resultadoMonomio(i);
		}
		return value;
}

	/*!
	@brief Sobrecarga del operador >>
	@param stream recibe una referencia a un flujo de datos
	@param p recibe una referencia a un polinomio que se va a modificar
	@return stream devuelve el flujo de datos referenciado
	@see leerPolinomio
		Sobrecarga del operador >> lo que permite leer directamente con cin>> un polinomio, facilitando dicha tarea. Invoca a la funcion leerPolinomio
	*/
	istream &operator>>(istream &stream, Polinomio &p){
		p.leerPolinomio();
		return stream;
	}

	/*!
	@brief Sobrecarga del operador <<
	@param stream recibe una referencia a un flujo de datos
	@param p recibe una referencia a un polinomio que se va a mostrar
	@return stream devuelve el flujo de datos referenciado
	@see escribirPolinomio
		Sobrecarga del operador << lo que permite leer directamente con cout<< un polinomio, facilitando dicha tarea. Invoca a la funcion escribirPolinomio
	*/
	ostream &operator<<(ostream &stream, Polinomio &p){
			p.escribirPolinomio();
			return stream;
	}

}		
		

















