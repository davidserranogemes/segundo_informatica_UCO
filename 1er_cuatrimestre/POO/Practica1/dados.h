#ifndef DADOS_H
#define DADOS_H
//dados.h
//clase de datos de un lanzamiento de dos dados

class Dados{
private:
	int d1_;
	int d2_;
	int lanzamiento1_;
	int lanzamiento2_;
	float Media1_;
	float Media2_;
	int last1_[5];
	int last2_[5];
public:
	Dados(); //constructor
	int lanzamiento();//asigna un valor aleatorio
	int getDado1();	//devuelve el valor del 1er dado
	int getDado2(); //devuelve el valor del 2o dado
	bool setDado1(int random); //asigna un valor al 1er dado, devuelve true si esta entre 1 y 6, false si da error
	bool setDado2(int random); //asigna un valor al 2o dado, devuelve true si esta entre 1 y 6, false si da error
	int getSuma(); //suma ambos dados y devuelve un valor
	int getDiferencia();//Resta ambos valores y devuelve el valor
	int getLanzamientos1();//Devuelve el numero de lanzamientos del dado 1
	int getLanzamientos2();//Devuelve el numero de lanzamientos del dado 2
	float getMedia1();//Devuelve la media de lanzamientos del dado 1
	float getMedia2();//Devuelve la media de lanzamientos del dado 2
	void getUltimos1(int *ultimos1);//Recibe los ultimos cinco resultados del dado 1.
	void getUltimos2(int *ultimos2);//Recibe los ultimos cinco resultados del dado 2.
};
#endif 
