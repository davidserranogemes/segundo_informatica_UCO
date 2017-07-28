#include "ListaOrdenadaDonantes.hpp"

namespace ed{
			bool ListaOrdenadaDonantes::isValid(int pos)const{//La primera es 0
				if(pos<0){
					return false;
				}
				if((pos+1)<=getSize()){
					return true;
				}else{
					return false;
				}
			}
					
			
			
			bool ListaOrdenadaDonantes::isLast(int pos)const{
				assert(isValid(pos));
				if((pos+1)==getSize()){
					return true;
				}else{
					return false;
				}
			}
		
			Donante ListaOrdenadaDonantes::item(int pos)const{
				NodoDonante * aux=getCabeza();
				int i=0;			
				bool encontrado=false;
				while((aux!=NULL)and(!encontrado)){
					if(i==pos){
						encontrado=true;
					}else{
						aux=aux->getSiguiente();
						i++;
					}
				}
				if(!encontrado){
					Donante d;
					return d;
				}else{
					return aux->getDonante();
				}
			}
		
			int ListaOrdenadaDonantes::findItem(Donante d, int from)const{
				int i;
				NodoDonante * aux=getCabeza();
				Donante auxDonante;
			
				for(i=0;i<from;i++){
					aux=aux->getSiguiente();
				}
				while(aux!=NULL){
					auxDonante=aux->getDonante();
					if(auxDonante==d){
						return i;
					}else{
						aux=aux->getSiguiente();
						i++;
					}
				}
				return -1;
			}
	
				
			void ListaOrdenadaDonantes::insert(Donante d){
				NodoDonante *ptr;
				NodoDonante *ptrAnt;
				NodoDonante *ptrLast;
		
				Donante auxDonante;
				bool iflag=true;
	

				if(isEmpty()){
					NodoDonante *n=new NodoDonante (d,NULL,NULL); //No declarar el nodo con memoria dinamica provoca que el nodo se pierda cuando abandonamos la funcion.
					setCabeza(n);
					sizePlus();
				}else{
					sizePlus();
					ptr=getCabeza();
					ptrAnt=NULL;
					NodoDonante *n=new NodoDonante (d,ptrAnt,ptr);//No declarar el nodo con memoria dinamica provoca que el nodo se pierda cuando abandonamos la funcion.
					while(iflag){			
						auxDonante=ptr->getDonante();
						if(d<=auxDonante){
							if(ptr==getCabeza()){//INSERTO nueva cabeza caso A
								ptr->setAnterior(n);
								n->setSiguiente(ptr);
								setCabeza(n);
								iflag=false;
							}else{//Inserto en el medio caso B
								ptrAnt=ptr->getAnterior();
								n->setAnterior(ptrAnt);
								n->setSiguiente(ptr);
								ptrAnt->setSiguiente(n);
								ptr->setAnterior(n);
								iflag=false;
							}
						}else{
							ptrLast=ptr->getSiguiente();
							if(ptrLast==NULL){
								//INSERTA FINAL caso C
								n->setAnterior(ptr);
								n->setSiguiente(ptrLast);
								ptr->setSiguiente(n);
								iflag=false;
								}else{
								ptr=ptrLast;
								}
						}
					}
				}
			}	
			bool ListaOrdenadaDonantes::deletePosition(int pos){	
				assert(isValid(pos));
				NodoDonante *ptr=getCabeza();
				NodoDonante *ptrAux;
				Donante auxDonante;
				bool retValue;
				ptrAux=NULL;
				int i;
				for(i=0;i<pos;i++){
					ptr=ptr->getSiguiente();
				}
//				std::cout<<"FinFOR"<<std::endl;
//				std::cout<<"POS="<<pos<<"i="<<i<<std::endl;
				if(ptr==getCabeza()){//Elimina cabeza caso A
				//		std::cout<<"CASO A"<<std::endl;
						setCabeza(ptr->getSiguiente());
						ptrAux=getCabeza();
						if(ptrAux!=NULL){
							ptrAux->setAnterior(NULL);
						}
						delete (ptr);
						sizeMinus();
						retValue=true;
					}else{
						ptrAux=ptr->getSiguiente();
						if(ptrAux==NULL){//ELIMINA FINAL caso C
				//		std::cout<<"CASO C"<<std::endl;
							ptrAux=ptr->getAnterior();
							ptrAux->setSiguiente(NULL);
							delete(ptr);
							sizeMinus();							
							retValue=true;
						}else{//elimina en el medio caso B
				//		std::cout<<"CASO B"<<std::endl;
							ptrAux=ptr->getAnterior();
							ptrAux->setSiguiente(ptr->getSiguiente());
							ptrAux=ptr->getSiguiente();
							ptrAux->setAnterior(ptr->getAnterior());
							delete (ptr);
							sizeMinus();

							retValue=true;
						}
					}
				return retValue;
				}
			
			









}
