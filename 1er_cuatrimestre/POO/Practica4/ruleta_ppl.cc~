#include <cstdio>
#include <iostream>
#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h" 
#include <string>
#include <list>

using namespace std;
using namespace ruleta;
main(){
	Crupier crupier1("32731725B","7777");//DNI Y CODIGO
	Ruleta ruleta1(crupier1);
	Jugador jugadorAuxiliar("3333","XXX");
	int select=-1;
	bool control=false;

	string DNIAux;
	string codigoAux;

//AUXILIARES 
	list<Jugador>::iterator i;
	list<Jugador> auxJugadores;
	list<Jugador> auxJugadores2;
	int numJugadores;
	int dineroEnJuego;
	int lanzamientos;
	int beneficio;	
	list<Jugador>::iterator j;
	int auxBanca,auxBeneficio;	
	string auxElim;
	int status;
	
	while(select!=0){
		do{	
			cout<<"Bienvenidos al casino de POO"<<'\n';
			cout<<"Elija una accion:"<<'\n'<<"1. Cargar los jugadores del fichero jugadores.txt."<<'\n'<<"2. Guardar los jugadores en jugadores.txt."<<'\n'<<"3. Ver estado de la ruleta, el dinero de la banca y el de cada jugador."<<'\n'<<"4. Girar la ruleta. Muestra la bola y el movimiento de  dinero."<<'\n'<<"5. Eliminar jugador de la ruleta."<<'\n'<<"6. Aniadir jugador a la ruleta."<<'\n'<<"7. Salir del programa"<<'\n';
			cin>>select;
		}while(select<0||select>7);
			switch(select){
				case 1:
					system("clear");
					ruleta1.leeJugadores();
					cout<<"Jugadores leidos."<<'\n';
					cout<<'\n'<<'\n'<<'\n';
					control=true;
				break;
			
				case 2:
					system("clear");
					
					if(control){
						ruleta1.escribeJugadores();
						cout<<"Jugadores escritos en jugadores.txt ."<<'\n';
						cout<<'\n'<<'\n'<<'\n';						

					}else{
						cout<<"No se han cargado jugadores todavia. Carge alguna vez jugadores para realizar esta funcion."<< endl;
					
					}
				break;

				case 3:
					system("clear");

					
					ruleta1.getEstadoRuleta(numJugadores,dineroEnJuego,lanzamientos,beneficio);
					cout<<"Hay "<<numJugadores<<" jugadores."<<'\n'<<"Hay "<<dineroEnJuego<<" euros en juego."<<'\n'<<"Se han hecho "<<lanzamientos<<" lanzamientos."<<'\n';
					if(beneficio>0){
						cout<<"La banca ha ganado "<<beneficio<<" euros."<<'\n';
					}else{
						cout<<"La banca ha perdido "<<beneficio<<" euros."<<'\n';
					}
					cout<<"La banca tiene "<<ruleta1.getBanca()<<" euros."<<'\n';						
					
					auxJugadores=ruleta1.getJugadores();
					for(i=auxJugadores.begin();i!=auxJugadores.end();i++){
						cout<<"El jugador con DNI "<<i->getDNI()<<" de nombre "<<i->getNombre()<<" tiene "<<i->getDinero()<<" euros."<<'\n';
					}
					cout<<'\n'<<'\n'<<'\n';
				break;
		
				case 4:
					system("clear");
					auxJugadores=ruleta1.getJugadores();
					
					ruleta1.giraRuleta();
					
					cout<<"BOLA: "<<ruleta1.getBola()<<'\n';
					
					auxBanca=ruleta1.getBanca();			
					ruleta1.getPremios();
					auxJugadores2=ruleta1.getJugadores();

					for(i=auxJugadores2.begin(),j=auxJugadores.begin();i!=auxJugadores2.end();i++,j++){
						auxBeneficio=i->getDinero()-j->getDinero();
						cout<<"El jugador:"<<i->getCodigo()<<" ha ganado "<<auxBeneficio<<'\n';
					}
					cout<<"Banca:"<<ruleta1.getBanca()-auxBanca<<'\n'<<endl;
	
				break;
				case 5:
					system("clear");
					cout<<"Introduzca el DNI del jugador a eliminar."<<'\n'<<endl;
					cin>>auxElim;
					status=ruleta1.deleteJugador(auxElim);
					if(status==-1){
						cout<<"No hay jugadores."<<endl;
						control=false;
					}else{	if(status==-2){
							cout<<"El jugador no existe."<<endl;
						}else{	if(status==1){
								cout<<"Jugador con DNI "<<auxElim<<" eliminado."<<endl;
								auxJugadores=ruleta1.getJugadores();
								if(!(auxJugadores.size())){
									control=false;
								}
								}else{
									cout<<"ERROR SIN DETERMINAR"<<endl;
								}
						}
					}
					
	
				break;
				case 6:
					system("clear");
					cout<<"Introduce el DNI del jugador: "<<endl;
					cin>>DNIAux;
					jugadorAuxiliar.setDNI(DNIAux);
					cout<<"Introduce el codigo del jugador: "<<endl;
					cin>>codigoAux;
					jugadorAuxiliar.setCodigo(codigoAux);

					control=ruleta1.addJugador(jugadorAuxiliar);
					if(control){
						cout<<"Jugador añadido correctamente."<<endl;
					}else{
						cout<<"El Jugador ya existe."<<endl;
						control=true;
					}
				break;

				case 7:
					select=0;
					cout<<"Saliendo del programa."<<endl;
				break;
			}
	}
}





























