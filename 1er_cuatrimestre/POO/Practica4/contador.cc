#include <iostream>
#include "contador.h"
Contador Contador::operator=(int aux){
	ultValor(entero_);

	entero_=aux;
	if(entero_<min_){
		entero_=0;
	}
	if(entero_>max_){
		entero_=0;
		}
	
	return *this;
}

Contador Contador::operator=(Contador aux){
	ultValor(entero_);

	entero_=aux.get();
	if(entero_<min_){
		entero_=0;
	}	
	if(entero_>max_){
		entero_=0;
		}
	
	return *this;
}

Contador Contador::operator++(void){
	ultValor(entero_);

	entero_++;
	if(entero_>max_){
		entero_=max_;
	}
	return *this;
}
Contador Contador::operator++(int){
	ultValor(entero_);

	entero_++;
	if(entero_>max_){
		entero_=max_;
	}
	return *this;
}

Contador Contador::operator--(void){
	ultValor(entero_);

	entero_--;
	if(entero_<min_){
		entero_=min_;
	}
	return *this;
}
Contador Contador::operator--(int){
	ultValor(entero_);

	entero_--;
	if(entero_<min_){
		entero_=min_;
	}
	return *this;
	}


bool Contador::undo(int n){
	if(n<=0){
		return false;
	}
	if(n>previo_.size()){
		return false;
	}
	list<int>::iterator i;
	i=previo_.begin();

	n--;
	for(int j=0;j<n;j++){
		i++;
	}
	entero_=*i;
	return true;
}
void Contador::ultValor(int last){
	previo_.push_front(last);
	
	}

Contador operator+(Contador c, int i){
	int aux;
	aux=c.get()+i;	
	if(aux>c.getMax()){
		c=c.getMax();
	}else{
		c=aux;
	}
	return c;
}
Contador operator+(int i, Contador c){
	int aux;
	aux=i+c.get();	
	if(aux>c.getMax()){
		c=c.getMax();
	}else{
		c=aux;
	}
	return c;	
}

Contador operator-(Contador c, int i){
	int aux;
	aux=c.get()-i;	
	if(aux<c.getMin()){
		c=c.getMin();
	}else{
		c=aux;
	}
	return c;
}
Contador operator-(int i, Contador c){
	int aux;
	aux=i-c.get();	
	if(aux<c.getMin()){
		c=c.getMin();
	}else{
		c=aux;
	}
	return c;
}























