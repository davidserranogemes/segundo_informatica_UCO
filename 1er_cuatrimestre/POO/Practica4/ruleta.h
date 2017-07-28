#ifndef RULETA_CC
#define RULETA_CC

#include <list>
#include "crupier.h"
#include "jugador.h"
#include <cstdlib>

namespace ruleta{



class Ruleta{
	private:
		int bola_;
		int banca_;
		list<Jugador> jugadores_;
		Crupier crupier_;
		int lanzamientos_;

		string getColor_(int numero);
		inline string getParidad_(int numero){if(numero==0){return("cero");}else{if(numero%2==0){return("par");}else{return("impar");}}};
		string getAltura_(int numero);
		inline int getLanzamientos_(){return (lanzamientos_);};
		int getdineroEnJuego_();
	public:
		inline	Ruleta(Crupier c):crupier_(c){bola_=-1;banca_=1000000;lanzamientos_=0;srand(time(NULL));};//Constructor de la clase ruleta. Inicializa un crupier creado
		
		inline bool setBanca(int banca){if(banca<0){return(false);}else{banca_=banca;return(true);}};//Comprueba que el dinero dela banca sea mayor que 0 y sustituye el valor de la banca	
		inline int getBanca(){return(banca_);};
	
		inline bool setBola(int bola){if((bola<0)||(bola>36)){return(false);}else{bola_=bola;return(true);}};//Comprueba que el valor de la bola este entre 0 y 36
		inline int getBola(){return(bola_);};
	
		inline bool setCrupier(Crupier c){crupier_=c;return(true);};
		inline Crupier getCrupier(){return(crupier_);};

		inline list<Jugador> getJugadores(){return(jugadores_);};
		
		bool addJugador(Jugador jugadorNuevo);
		int deleteJugador(Jugador jugadorEliminar);
		int deleteJugador(string DNIEliminar);
		
		void escribeJugadores();
		void leeJugadores();
		
		void giraRuleta(){setBola(rand()%37);lanzamientos_++;};
		void getPremios();

		void getEstadoRuleta(int &numJugadores,int &dineroEnJuego,int &lanzamientos, int &beneficio); 
};
}
#endif
