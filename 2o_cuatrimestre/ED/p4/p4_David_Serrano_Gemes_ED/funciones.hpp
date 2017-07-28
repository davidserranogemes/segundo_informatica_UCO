#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <limits>
#include <vector>
#include <string>

#include "Grafo.hpp"
#include "Vertice.hpp"
using std::vector;


/*!
@brief Namespace de la asignatura
@namespace ed Namespace e la asignatura Estructuras de Datos
*/
namespace ed{


/**
@brief Funcion que aplica el algoritmo de Floyd
@param origen Grafo sobre el que se aplica
@param MatrizDistancias Matriz en la que se guardaran las distancias calculadas. Es una referencia a otra matriz
@param Predecesores Matriz en la que se guardaran los antecesores si lo hay. Es una referencia a otra matriz

Funcion que aplica el algoritmo de floyd sobre origen guarda las distancias en MatrizDistancias y los antecesores en Predecesores
*/
void Floyd(Grafo origen, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores);

/**
@brief Funcion que devuelve el camino mas corto entre dos Vertices
@param grafoCompleto Grafo sobre el que se aplica
@param MatrizDistancias Matriz en la que se guardaran las distancias calculadas. Es una referencia a otra matriz
@param Predecesores Matriz en la que se guardaran los antecesores si lo hay. Es una referencia a otra matriz
@param Origen tipo vertice desde el que salimos
@param Destino tipo vertice al que llegamos

Funcion que devuelve el camino mas corto entre los vertices  Origen y Destino


*/

void Camino(Grafo &grafoCompleto, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores, Vertice Origen, Vertice Destino);
 /**
@brief Funcion que devuelve el camino mas corto entre dos Vertices sin incluir los extremos, devuelve la distancia tambien
@param grafoCompleto Grafo sobre el que se aplica
@param MatrizDistancias Matriz en la que se guardaran las distancias calculadas. Es una referencia a otra matriz
@param Predecesores Matriz en la que se guardaran los antecesores si lo hay. Es una referencia a otra matriz
@param Origen tipo vertice desde el que salimos
@param Destino tipo vertice al que llegamos
@return Tipo entero que indica la distancia en kilometros entre los nodos

Funcionque devuelve el camnio intermedio entre los nodos origen y destino, ademas de su distancia
*/
int CaminoIntermedio(Grafo &grafoCompleto, vector< vector < double > > &MatrizDistancias, vector< vector < int  > > &Predecesores, Vertice Origen, Vertice Destino);
}
#endif
