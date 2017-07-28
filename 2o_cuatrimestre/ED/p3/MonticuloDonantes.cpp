#include "MonticuloDonantes.hpp"
#include "Donante.hpp"

#include <iostream>
#include <list>

namespace ed{

	void MonticuloDonantes::insert(Donante d){
		int pos;	

		tamPlus();
		heap_.resize(getTam());
		pos=(getTam()-1);
		heap_[pos]=d;

		flotar();
		}
			
	void MonticuloDonantes::remove(){
		assert(!isEmpty());

		heap_[0]=heap_[getTam()-1];
		tamMinus();
		heap_.resize(getTam());
		hundir();
	}	

	void MonticuloDonantes::donar(){
		assert(!isEmpty());
		heap_[0].DonacionesInc();
		hundir();
	}
	
	istream &operator>>(istream &stream, MonticuloDonantes &m){
		char * aux=new char[100];
		string NombreFich, control;
		Donante dAux;

		while(control!="EOF"){
			stream>>dAux;
			//system("clear");
			m.insert(dAux);
			stream.getline(aux,100,'\n');
			control=aux;
		}
		return stream;			
	}

	ostream &operator<<(ostream &stream, MonticuloDonantes &m){
		Donante dAux;
		std::list<Donante> listDon;

		while(m.getTam()>0){
			dAux=m.Top();
			stream<<dAux;
			listDon.push_back(dAux);
			if(m.getTam()==1)
				stream<<"EOF"<<std::endl;
			else
				stream<<std::endl;
			m.remove();
		}
		while(!listDon.empty())
		{
			dAux=listDon.back();
			listDon.pop_back();
			m.insert(dAux);
		
		}
		
		return stream;
					
	}
	void MonticuloDonantes::hundir(){
		int posPadre=0;
		int pos;
		Donante auxSwap;
		bool NEED=true;
		bool SWAP=false;
		
		while(NEED){//DEBES COMPROBAR EL CASO DE QUE SOLO HAYA UN HIJO
			if(posPadre*2+3<=getTam()){//Esto significa que el hijo derecho  existe
			//std::cout<<"PADRE: "<<heap_[posPadre].getDonaciones()<<std::endl;			
			//std::cout<<"Hijo izq: "<<heap_[2*posPadre+1].getDonaciones()<<std::endl;
			//std::cout<<"Hijo der: "<<heap_[2*posPadre+2].getDonaciones()<<std::endl;
				if((heap_[posPadre]<=heap_[2*posPadre+1])&&(heap_[posPadre]<=heap_[2*posPadre+2])){
					NEED=false;									
				}else{
					SWAP=true;		
					if(heap_[2*posPadre+1]<=heap_[2*posPadre+2]){
						//hijo izq debe subir
						pos=2*posPadre+1;

					}else{
						//hijo der debe subir
						pos=2*posPadre+2;

					}
				}
			}else{//No existe el nodo hijo derecho
				if(2*posPadre+1>getTam()){
				NEED=false;
				}else{
					//std::cout<<"PADRE: "<<heap_[posPadre].getDonaciones()<<std::endl;			
					//std::cout<<"Hijo izq: "<<heap_[2*posPadre+1].getDonaciones()<<std::endl;
					if((heap_[posPadre]<=heap_[2*posPadre+1])){
						NEED=false;			
					}else{
						pos=posPadre+1;
						SWAP=true;
						NEED=false;		
					}
				}
			}
			if(SWAP){
				//Hay que swapear y seguir
				auxSwap=heap_[posPadre];
				heap_[posPadre]=heap_[pos];
				heap_[pos]=auxSwap;	
				posPadre=pos;
				SWAP=false;
				if(posPadre*2+2>getTam()){//Esto significa que el hijo derecho 
					NEED=false;
				}
			}
			
		}
	}

	void MonticuloDonantes::flotar(){
		int pos=(getTam()-1);	
		int posPadre;

		Donante auxSwap;

		bool NEED=true;	
		bool hijo;//True hijo izquierdo, false hijo derecho
	
	

		if(getTam()!=1){//Se ha realizado la primera insercion, no tiene sentido intentar hundir el donante
			while(NEED){//Comprueba si es hijo izquierdo o hijo derecho
				if(((pos-1)%2)==0){
					hijo=true;
				}else{
					hijo=false;
				}
				if(hijo){//Es hijo izquierdo
					posPadre=(pos-1)/2;
				}else{
					posPadre=(pos-2)/2;
				}
	
				if(heap_[pos]<=heap_[posPadre]){
					//Hay que swapear y seguir
					auxSwap=heap_[posPadre];
					heap_[posPadre]=heap_[pos];
					heap_[pos]=auxSwap;
			
					if(posPadre==0){
						NEED=false;//Ya hemos hecho cabeza
					}else{
						pos=posPadre;
					}
				}else{
					NEED=false;
				}
					
			}	
		}


	}

}







