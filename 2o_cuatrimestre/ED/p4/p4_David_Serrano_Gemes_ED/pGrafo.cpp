#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <string>

#include "Grafo.hpp"
#include "Vertice.hpp"
#include "funciones.hpp"
/*!
    \mainpage
    \brief   Práctica sobre el uso de un grafo
    \author  David Serrano Gemes
    \date     2016/05/22
    \version 1.0

*/


using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){

	ed::Grafo g;
	int opcion;
	char opcionFloyd;

	string auxString;
	ed::Vertice Origen, Destino;
	bool FloydDone=false;
	bool Leido=false;
	
	double infinite= std::numeric_limits<double>::infinity();

	vector< vector <double> > MatrizDistancias;
	vector< vector <int> > Predecesores;
	system("clear");
do{//Menu
		do{



			cout<<"Elija una opcion: "<<endl;
			cout<<"0. Salir del programa. "<<endl;
			cout<<"1. Cargar un grafo desde un fichero."<<endl;
			cout<<"2. Mostrar el grafo por pantalla."<<endl;
			cout<<"3. Aplicar el algoritmo de Floyd y:"<<endl<<"(a) Mostrar el vertice que tiene la menor suma de distancias a los demas vertices y la suma de distancias cuando cada vertice es usado como origen"<<endl<<"(b) Mostrar la distancia y el camino minimo dentre dos vertices indicados por el usuario"<<endl;

			cin>>opcion;
			
		}while((opcion<0)||(opcion>3));
			switch(opcion){
				case 0:
					system("clear");
					cout<<"Apagando programa...."<<endl;
					sleep(2);
					system("clear");
					break;
				case 1:
					system("clear");
					if(!Leido){
						g.leerFichero();
						Leido=true;
					}else{
						cout<<"Reinicie el programa para introducir otro Grafo"<<endl;
					}
					break;
				case 2:
					system("clear");
					if(!Leido){
						cout<<"No se ha leido todavia ningun grafo. Lea primero uno."<<endl;
					}else{

						cout<<"Vertices:"<<endl;
						for(int i=0;i<g.numVertices();i++){
							cout<<(g.getVertice(i).getData())<<endl;
						}
						cout<<endl;

						cout<<"Lados:"<<endl;
						for(int i=0;i<g.numVertices();i++){
							for(int j=0;j<g.numVertices();j++){
								if(g.adyacente(i,j)!=infinite){
									if(!g.esDirigido()and(i>j)){							
										cout<<"De: "<<(g.getVertice(i).getData())<<" a "<<(g.getVertice(j).getData())<<". Coste: "<<g.adyacente(i,j)<<endl;
									}else{if(i!=j){
										cout<<"De: "<<(g.getVertice(i).getData())<<" a "<<(g.getVertice(j).getData())<<". Coste: "<<g.adyacente(i,j)<<endl;
										}
									}
								}
							}
						}
						cout<<endl;
						if(g.numVertices()<=15){
							//Visualizacion de las matrices
							cout<<endl;
							for(int i=0;i<g.numVertices();i++){
								for(int j=0;j<g.numVertices();j++){
								cout<<"["<<g.adyacente(i,j)<<"]";
								}								
								cout<<endl;
							}
							cout<<endl<<endl;		
						}
					}
					

					break;
				case 3:
					system("clear");
					
					if(!Leido){
						cout<<"No se ha leido todavia ningun grafo. Lea primero uno."<<endl;
					}else{
						if(!FloydDone){
							Floyd(g,MatrizDistancias,Predecesores);
							FloydDone=true;
						}
						do{
							system("clear");
							cout<<"Introduce a para:"<<endl<<"\tMostrar el vertice que tiene la menor suma de distancias a los demas vertices y"<<endl<<"\t la suma de distancias cuando cada vertice es usado como origen."<<endl<<endl<<"Introduce b para:"<<endl<<"\tMostrar la distancia y el camino minimo dentre dos vertices indicados por el usuario."<<endl;
							cin>>opcionFloyd;
						}while((opcionFloyd!='a')and(opcionFloyd!='b'));

							if(opcionFloyd=='a'){

								int minId;
								double min=infinite;
								double total=0,acumulado=0;
								for(int i=0;i<g.numVertices();i++){
									for(int j=0;j<g.numVertices();j++){
										if(MatrizDistancias[i][j]!=infinite){
											acumulado+=MatrizDistancias[i][j];
											//cout<<"["<<MatrizDistancias[i][j]<<"]";
										}
									}
									cout<<"El nodo "<<g.getVertice(i).getData()<<" tiene un coste acumulado de: "<<acumulado<<" kilometros."<<endl;;
									//cout<<endl;
									if(acumulado<min){
										minId=i;
										min=acumulado;
									}
									total+=acumulado;
									acumulado=0;
								}
								cout<<"El nodo mas centrico es: "<<g.getVertice(minId).getData()<<endl<<"La suma de sus distancias es: "<<min<<" kilometros."<<endl;
								cout<<"La suma de todas las distancias es: "<<(int)total<<" kilometros."<<endl; 
		
							}else{
								cout<<"Introduce el dato del vertice origen:"<<endl;
								cin>>auxString;
								Origen.setData(auxString);
	
								cout<<"Introduce el dato del vertice destino:"<<endl;
								cin>>auxString;
								Destino.setData(auxString);

								system("clear");

								Camino(g,MatrizDistancias,Predecesores,Origen,Destino);
								cout<<endl;
							}
					}
					break;
			
			}
	}while(opcion!=0);//Menu
	return 0;
	



}
