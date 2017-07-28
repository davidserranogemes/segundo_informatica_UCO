#include <iostream>
#include "dados.h"
#include <cstdlib>

main(){
Dados d;
int random;
d.lanzamiento();
std::cout<<"El valor del dado 1 es: "<<d.getDado1()<<"\n";
std::cout<<"El valor del dado 2 es: "<<d.getDado2()<<"\n";
}
