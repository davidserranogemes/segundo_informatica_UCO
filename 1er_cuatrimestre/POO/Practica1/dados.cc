//dados.cc
//Cuerpo de los métodos de la clase Dados
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados(){
	d1_=1;
	d2_=1;
	lanzamiento1_=0;
	lanzamiento2_=0;
	Media1_=0;
	Media2_=0;
	srand(time(NULL));
	for(int i=1;i<6;i++){
		last1_[i]=0;
		last2_[i]=0;
	}
	
}

int Dados::lanzamiento(){
	int random;

	random=rand()%6+1;
	setDado1(random);

	random=rand()%6+1;	
	setDado2(random);
	
	
return(random);
}



bool Dados::setDado1(int random){
	
	if((random<1)||(random>6)){
		return(false);
	}
	else{	lanzamiento1_++;
		d1_=random;
		Media1_=Media1_+d1_;
		last1_[0]=last1_[1];
		last1_[1]=last1_[2];
		last1_[2]=last1_[3];
		last1_[3]=last1_[4];
		last1_[4]=d1_;

		return(true);
	
	}

}
bool Dados::setDado2(int random){
	if((random<1)||(random>6)){
		return(false);
	}
	else{	lanzamiento2_++;
		d2_=random;
		Media2_=Media2_+d2_;
		last2_[0]=last2_[1];
		last2_[1]=last2_[2];
		last2_[2]=last2_[3];
		last2_[3]=last2_[4];
		last2_[4]=d2_;

		return(true);
	
	}

}

int Dados::getDado1(){
	return (d1_);
}


int Dados::getDado2(){
	return (d2_);
}
int Dados::getSuma(){
	return(d1_+d2_);
}
int Dados::getDiferencia(){
	if(d1_>=d2_){
		return(d1_-d2_);
	}
	else{
		return(d2_-d1_);
	}
}



int Dados::getLanzamientos1(){
	return(lanzamiento1_);
}

int Dados::getLanzamientos2(){
	return(lanzamiento2_);
}
float Dados::getMedia1(){
	if(lanzamiento1_==0){
		return(0);
	}else{
		return(Media1_/lanzamiento1_);
}
}


float Dados::getMedia2(){
	if(lanzamiento2_==0){
		return(0);
	}else{
		return(Media2_/lanzamiento2_);
	}
}

void Dados::getUltimos1(int *ultimos1){
	
	for(int i=0;i<5;i++){
		ultimos1[i]=last1_[i];
	}
}

void Dados::getUltimos2(int *ultimos2){
	for(int i=0;i<5;i++){
		ultimos2[i]=last2_[i];
	}
}

