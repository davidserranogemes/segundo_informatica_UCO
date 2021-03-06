#include <cstdlib>
#include "Donantes.hpp"	

namespace ed{
	

			void Donantes::ModificarDonante(Donante &d){	
				int marca=lista_.findItem(d,0);
				Donante prevDonante=d;
				if(marca==-1){
					std::cout<<"El donante no existe."<<std::endl;
				}else{
					d.modificarDonante();
					if(!(d==prevDonante)){
						lista_.deletePosition(marca);
						lista_.insert(d);
					}
				}
			}
				
			bool Donantes::deleteDonante(Donante &d){
				int marca=lista_.findItem(d,0);
				if(marca==-1){
					std::cout<<"El donante no existe."<<std::endl;
					return false;
				}else{
					lista_.deletePosition(marca);	
				}
				size_=lista_.getSize();
				return true;
			}	
	
			void Donantes::leerDonantes(){
				Donante * auxDonante=new Donante;
				int insertar;
				std::cout<<"Introduce un 1 si quiere insertar un donante. Otro numero si quiere detenerse."<<std::endl;			
				std::cin>>insertar;
				while(insertar==1){
					auxDonante->leerDonante();
					lista_.insert(*auxDonante);
					size_++;
					std::cout<<"Introduce un 1 si quiere insertar un donante. Otro numero si quiere detenerse."<<std::endl;			
					std::cin>>insertar;
				}
			}

			void Donantes::escribirDonantes()const{
				Donante aux;
				for(int i=0;i<getSize();i++){
					aux=lista_.item(i);
					aux.escribirDonante();
				}
			}

			istream &operator>>(istream &stream, Donantes &d){
					char * aux=new char[100];
					string NombreFich, control;
					Donante dAux;

					while(control!="EOF"){
						stream>>dAux;
						//system("clear");
						d.insertDonante(dAux);
						stream.getline(aux,100,'\n');
						control=aux;
					}
			return stream;			
			}

			ostream &operator<<(ostream &stream, Donantes const &d){
					Donante dAux;

					for(int i=0;i<d.getSize();i++){
						dAux=d.getDonante(i);
						stream<<dAux;
						if(i==(d.getSize()-1))
							stream<<"EOF"<<std::endl;
						else
							stream<<std::endl;
					}
					return stream;
					
			}


};






























