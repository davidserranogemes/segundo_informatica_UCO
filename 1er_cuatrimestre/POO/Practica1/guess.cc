//guess.cc
//Juego de la patata caliente entre 1 y 10

#include <cstdlib>
#include <ctime>
#include <iostream>

main(){
int random,R,i=0;
bool b=true;

srand(time(NULL));
random=rand();
random=(random%10)+1;

while(b){
	do{
		std::cout<<"Introduzca un valor entre 1 y 10\n";
		std::cin>>R;
	}while((R<1)||(R>10));
	
	if(R==random){
		b=false;
	}
	else{
		if(R<random){
			std::cout<<"El numero buscado es mayor que "<<R<<"\n";
		}else{
			std::cout<<"El numero buscado es menor que "<<R<<"\n";
		}
	}
i++;
}
std::cout<<"Correcto, el numero buscado era: "<<random<<" y usted ha introducido: "<<R<<" tras "<<i<<" intentos.\n";

}
