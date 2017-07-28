#include "funciones.hpp"

using std::cout;
using std::endl;

namespace ed{

void Floyd(Grafo origen, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores){

	int i,j,k;
	
	//Preparando los tamaños
	MatrizDistancias.resize(origen.numVertices());
	for(int i=0;i<origen.numVertices();i++){
		MatrizDistancias[i].resize(origen.numVertices(),0);
	}

	Predecesores.resize(origen.numVertices());
	for(int i=0;i<origen.numVertices();i++){
		Predecesores[i].resize(origen.numVertices(),-1);
	}

	//Inicializando los valores
	for(int i=0;i<origen.numVertices();i++){
		for(int j=0;j<origen.numVertices();j++){
			MatrizDistancias[i][j]=origen.adyacente(i,j);
		}
	}
	//Visualizacion de las matrices
	/*
	for(int i=0;i<origen.numVertices();i++){
			for(int j=0;j<origen.numVertices();j++){
				cout<<'\t'<<"["<<MatrizDistancias[i][j]<<"]";
			}		
			
		cout<<endl;
	}

	for(int i=0;i<origen.numVertices();i++){
			for(int j=0;j<origen.numVertices();j++){
				cout<<'\t'<<"["<<Predecesores[i][j]<<"]";
			}		
			
		cout<<endl;
	}
	*/
	for(k=0;k<origen.numVertices();k++){
		for(i=0;i<origen.numVertices();i++){
			for(j=0;j<origen.numVertices();j++){
				if(MatrizDistancias[i][j]>(MatrizDistancias[i][k]+MatrizDistancias[k][j])){
					Predecesores[i][j]=k;
					MatrizDistancias[i][j]=(MatrizDistancias[i][k]+MatrizDistancias[k][j]);
				}
			}
		}
	}

	
}
void Camino(Grafo &grafoCompleto, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores, Vertice Origen, Vertice Destino){
	int Distancia;
	int i=grafoCompleto.buscarVertice(Origen.getData());
	int j=grafoCompleto.buscarVertice(Destino.getData());
	if((i==-1)or((j==-1))){
		cout<<"Los vertices que ha pasado no existen en el grafo."<<endl;
	}else{//Empieza el algoritmo
		cout<<"El camino de "<<Origen.getData()<<" a "<<Destino.getData()<<" es:"<<endl;
		cout<<Origen.getData();
		Distancia=CaminoIntermedio(grafoCompleto,MatrizDistancias,Predecesores,Origen,Destino);
		cout<<">"<<Destino.getData()<<endl;
		if(Distancia>0){
			cout<<"El camino de "<<Origen.getData()<<" a "<<Destino.getData()<<" tiene una logitud de:"<<Distancia<<" kilometros."<<endl;
		}else{
			cout<<"No hay camino de "<<Origen.getData()<<" a "<<Destino.getData()<<endl;
		}
	}
}

int CaminoIntermedio(Grafo &grafoCompleto, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores, Vertice Origen, Vertice Destino){
	int i=grafoCompleto.buscarVertice(Origen.getData());
	int j=grafoCompleto.buscarVertice(Destino.getData());
	Vertice auxOrigen, auxIntermedio, auxDestino;

	int k=Predecesores[i][j];//intermedio
	int DistanciaPos=0;
	int DistanciaAnt=0;

	if(k!=-1){//Si k!=-1 es que hay un intermedio entre i y j
		auxOrigen=grafoCompleto.getVertice(i);
		auxIntermedio=grafoCompleto.getVertice(k);
		auxDestino=grafoCompleto.getVertice(j);

		DistanciaAnt=CaminoIntermedio(grafoCompleto, MatrizDistancias, Predecesores, auxOrigen, auxIntermedio);
		
		cout<<">"<<grafoCompleto.getVertice(k).getData();

		DistanciaPos=CaminoIntermedio(grafoCompleto, MatrizDistancias, Predecesores, auxIntermedio, auxDestino);
		//cout<<grafoCompleto.getVertice(i).getData();
		return (DistanciaPos+DistanciaAnt);
	}else{
		return MatrizDistancias[i][j];
	}
	
}
		
	

	





}







