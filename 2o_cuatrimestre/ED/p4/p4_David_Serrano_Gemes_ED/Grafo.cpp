#include "Grafo.hpp"
#include <fstream>
#include <cstdlib>

namespace ed{
void Grafo::leerFichero(){

	std::ifstream ficheroLectura;

	string nombreFich;
	string aux;

	Vertice verticeAux;	

	int elementos;
	
	double infinite= std::numeric_limits<double>::infinity();


	cout<<"Introduce el nombre de un fichero que contenga un grafo valido."<<endl;
	cin>>nombreFich;

	ficheroLectura.open(nombreFich.c_str());
	cin.ignore(); //Elimina caracteres residuales que puedan afectar a la lectura
	if(ficheroLectura.is_open()){

		cout<<"El fichero se ha abierto"<<endl;
		
		//Lee el numero de elementos
		getline(ficheroLectura,aux);
		elementos=atoi(aux.c_str());
		cout<<"Hay "<<aux<<" elementos "<<endl;

		//Lee si es dirigido o no
		getline(ficheroLectura,aux);
		if(atoi(aux.c_str())==1){//Es dirigido
			cout<<"Es dirigido."<<endl;
			Dirigido_=true;
		}else{
			cout<<"No es dirigido."<<endl;
			Dirigido_=false;
		}
		//Prepara el vector de nodos
		Nodos_.resize(elementos);

		//Leer Nodos
		for(int i=0;i<elementos;i++){
			getline(ficheroLectura,aux,'\n');

			verticeAux.setData(aux);
			verticeAux.setLabel(i);
			Nodos_[i]=verticeAux;
			tam_++;
		}

		//Matriz inicializada con los tamaños correctos y a infinito
		matriz_.resize(elementos);
		for(int i=0;i<elementos;i++){
			matriz_[i].resize(elementos,infinite);
		}
		//Diagonal principal iniciada a 0
		for(int i=0;i<elementos;i++){
			matriz_[i][i]=0;
		}

		//Leer matriz adyacencias
		int origen;
		int destino;
		cout<<"Leyendo matriz adyacencias."<<endl;
		while(getline(ficheroLectura,aux,' ')){

			origen=buscarVertice(aux);
		
			getline(ficheroLectura,aux,' ');
			destino=buscarVertice(aux);

			getline(ficheroLectura,aux);

			matriz_[origen][destino]=atoi(aux.c_str());
			if(!esDirigido()){
				matriz_[destino][origen]=atoi(aux.c_str());
			}
		}
		cout<<endl;
		ficheroLectura.close();
	}else{
		cout<<"El fichero introducido no existe."<<endl;
	}
}

void Grafo::addVertice(Vertice v){
	Vertice *real=new Vertice;
	real->setLabel(v.getLabel());
	real->setData(v.getData());

	Nodos_.push_back(*real);
	tam_++;
}

int Grafo::buscarVertice(string data){
	int encontrado=-1;	
	for(int i=0;i<numVertices();i++){
		if(Nodos_[i].getData()==data){
			encontrado=i;
		}
	}

	return encontrado;
}
		



}	
