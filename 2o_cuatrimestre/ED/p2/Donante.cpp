#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "Donante.hpp"
namespace ed{			

		void Donante::leerDonante(){
			char * aux=new char[100];
			string auxString;
			std::cin.ignore();
			std::cout<<"Introduce el nombre"<<std::endl;			
			std::cin.getline(aux,100,'\n');
			auxString=aux;
			setNombre(auxString);
		
			std::cout<<"Introduce los apellidos"<<std::endl;
			std::cin.getline(aux,100,'\n');
			auxString=aux;
			setApellidos(auxString);			

			std::cout<<"Introduce el grupo sanguineo"<<std::endl;
			std::cin.getline(aux,100,'\n');
			auxString=aux;
			setGrupoSanguineo(auxString);

			std::cout<<"Introduce el RH, para indicar RH+ escriba \"positivo\", para indicar RH- escriba \"negativo\""<<std::endl;
			std::cin.getline(aux,100,'\n');
			auxString=aux;
			if(auxString=="positivo"){
				setRH(true);
			}else{if(auxString=="negativo"){
					setRH(false);
				}else{
					std::cout<<"ERROR, se debe introducir positivo o negativo"<<std::endl;
					exit(-1);
				}
			}

		}

		void Donante::escribirDonante(){
			std::cout<<"Nombre: "<<getNombre()<<std::endl;		
			std::cout<<"Apellidos: "<<getApellidos()<<std::endl;
			std::cout<<"Grupo sanguineo: "<<getGrupoSanguineo()<<std::endl;
			if(getRH()){
				std::cout<<"RH+"<<std::endl;
			}else{
				std::cout<<"RH-"<<std::endl;
			}
		
		}

		


		void Donante::modificarDonante(){
			string mod;	
			char * aux=new char[100];
			string auxString;
			std::cin.ignore();		

			std::cout<<"Se muestra el estado actual del donante: "<<std::endl;
			escribirDonante();

			std::cout<<"¿Quiere modificar su nombre?    S/N"<<std::endl;
			std::cin>>mod;
			if((mod=="S")or(mod=="s")){
				std::cin.ignore();
				std::cout<<"Introduce el nuevo nombre:"<<std::endl;
				std::cin.getline(aux,100,'\n');
				auxString=aux;
				setNombre(auxString);

			}else{if((mod=="N")or(mod=="n")){
				}else{
					std::cout<<"ERROR debe decir S o N"<<std::endl;
				}
			}

			std::cout<<"¿Quiere modificar sus apellidos?    S/N"<<std::endl;
			std::cin>>mod;


			if((mod=="S")or(mod=="s")){
				std::cin.ignore();
				std::cout<<"Introduce los nuevo apellidos:"<<std::endl;
				std::cin.getline(aux,100,'\n');
				auxString=aux;
				setApellidos(auxString);
			}else{if((mod=="N")or(mod=="n")){
				}else{
					std::cout<<"ERROR debe decir S o N"<<std::endl;
				}
			}	

			std::cout<<"¿Quiere modificar su grupo sanguineo?    S/N"<<std::endl;
			std::cin>>mod;	

			if((mod=="S")or(mod=="s")){
				std::cin.ignore();
				std::cout<<"Introduce el nuevo grupo sanguineo (Solo es valido A, B, AB o 0):"<<std::endl;
				std::cin.getline(aux,100,'\n');
				auxString=aux;
				setGrupoSanguineo(auxString);
			}else{if((mod=="N")or(mod=="n")){
				}else{
					std::cout<<"ERROR debe decir S o N"<<std::endl;
				}
			}
			

			std::cout<<"¿Quiere modificar su RH?    S/N"<<std::endl;
			std::cin>>mod;

			if((mod=="S")or(mod=="s")){

				std::cout<<"Introduce el nuevo RH (positivo para RH+, negativo para RH-)"<<std::endl;
				std::cin>>mod;
				if(mod=="positivo"){
					setRH(true);
					}else{if(mod=="negativo"){
						setRH(false);
						}else{
							std::cout<<"ERROR, se debe introducir positivo o negativo"<<std::endl;
							exit(-1);
						}
					}
			}else{if((mod=="N")or(mod=="n")){
				}else{
					std::cout<<"ERROR debe decir S o N"<<std::endl;
				}
			}
		}

		Donante & Donante::operator=(const Donante &d){
			setNombre(d.getNombre());
			setApellidos(d.getApellidos());
			setGrupoSanguineo(d.getGrupoSanguineo());
			setRH(d.getRH());
			return *this;
		}

		bool Donante::operator==(const Donante &d){
			if((getNombre()==d.getNombre())and(getApellidos()==d.getApellidos())){
				return true;
			}else{
				return false;
			}
		}

		bool Donante::operator<=(const Donante &d){
			std::string stringThis, stringD;
			char * charThis, *charD;
			if((*this)==d){
				return true;
			}else{
				stringThis=this->getApellidos();
				stringD=d.getApellidos();

				charThis=new char [stringThis.length()+1];
				charD=new char [stringD.length()+1];

				strcpy(charD,stringD.c_str());				
				strcpy(charThis,stringThis.c_str());
	
				int option=strcmp(charThis,charD);
				
				if(option<0){///El apellido del donante que llama es menor(antes alfabeticamente) que el de d
					return true;
				}else{if(option>0){///El apellido del donante que llama es mayor(despues alfabeticamente) que el de d
					return false;
					}else{///Los apellidos son iguales, comprobamos el nombre
						stringThis=this->getNombre();
						stringD=d.getNombre();
						
						std::strcpy(charD,stringD.c_str());				
						std::strcpy(charThis,stringThis.c_str());	
						
						int option=strcmp(charThis,charD);
				
						if(option<0){///El nombre del donante que llama es menor(antes alfabeticamente) que el de d
							return true;
						}else{if(option>0){///El nombre del donante que llama es mayor(despues alfabeticamente) que el de d
							return false;
							}else{
								std::cout<<"ERROR INDEFINIDO"<<std::endl;
								exit (-1);
																
							}
						}
					}
				}
			}
		}

		istream & operator>>(istream &stream, Donante &d){
			char * aux=new char[100];
			string auxString;

			stream.getline(aux,100,'/');
			auxString=aux;
			d.setNombre(auxString);
		
			stream.getline(aux,100,'/');
			auxString=aux;
			d.setApellidos(auxString);			

			stream.getline(aux,100,'/');
			auxString=aux;
			d.setGrupoSanguineo(auxString);

			stream.getline(aux,100,'/');
			auxString=aux;
			if(auxString=="positivo"){
				d.setRH(true);
			}else{if(auxString=="negativo"){
					d.setRH(false);
				}else{
					std::cout<<"ERROR, se debe introducir positivo o negativo"<<std::endl;
					exit(-1);
				}
			}
			return stream;
		 }

		ostream &operator<<(ostream &stream, Donante const &d){
			stream<<d.getNombre()<<"/";		
			stream<<d.getApellidos()<<"/";
			stream<<d.getGrupoSanguineo()<<"/";
			if(d.getRH()){
				stream<<"positivo"<<"/";
			}else{
				stream<<"negativo"<<"/";
			}
			return stream;
		}


};
















