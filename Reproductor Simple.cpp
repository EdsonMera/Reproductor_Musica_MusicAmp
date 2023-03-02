//REPRODUCTOR DE MUSICA (Sin Audios)
//Edson Guadalupe Mera Orozco - 3CM25
//Julián Fonseca Chan - 3CM25

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "console.h"

using namespace std;

//ESTRUCTURA
struct pista{
	int num;
	string cancion;
	string interprete;
	string genero;
	struct pista *sig, *ant;
};

int main(){
//ARREGLOS
	string Cancion[30] = {"All_You_Need_To_Know","Atmosphere","Better","Be_Fine","Boomerang","Children","Do_It_For_You",
	"Escape","Falling","Feel_The_Light","Feeling_Good","Hear_Me_Now","Heart","Higher_Ground","I_Need_You",
	"I_Wanna_Know","In_The_Studio","Into_You","Like_It_Is","Lose_My_Mind","Mind_Control","Never_Letting_Go",
	"Okay","Paradise","Ready_To_Rave","Sad_Songs","Something_Comforting","Superstar","The_One","You"};
	string Interprete[30] = {"Gryffin","Licious","Breathe_Carolina","Ekali","GRX","Keanu_Silva","Lucas_Steve",
	"Dante_Klein","Nicky_Romero","BEAUZ","Mariana_BO","Alok","Meduza","Pharien","Armin_Van_Buuren","NOTD",
	"Trobi","Dubvision","Kygo","Sophie_Francis","NWYR","Audien","Halder","Rompasso","W&W","Illenium",
	"Porter","Joe_Stone","Kim_Kaey","Matisse"};
	string Genero[30] = {"Dance","Future_House","Dance","Midtempo","Progressive_House","Future_Bounce","Future_House",
	"Dance","Progressive_House","Dance","MidTechno","Deep_House","Brazilian_Bass","Future_House","Deep_House",
	"Deep","House","Progressive_House","Tropical_House","Future_House","Trance","Progressive_House","Midtempo",
	"Deep_House","Trance","Midtempo","Midtempo","Future_House","Deep_House","Deep"};
	int Aleatorios[30];
	//string Genero[2][50] = {"Dance","Pop"};
	
	//VARIABLES
	int i, opc, resp, repr, opc2, cont, comp, opc3, perm, band, reprbusq;
	string busqueda;
	pista *p=NULL, *f, *aux;
	
	//Paso de datos de Arreglos a Lista Enlazada Circular
	for(i=0; i<=29; i++){
		if(p == NULL){
			p = new(pista);
			p->num=i+1;
			p->cancion=Cancion[i];
			p->interprete=Interprete[i];
			p->genero=Genero[i];
			p->sig=p;
			p->ant=p;
			f=p;
		}else{
			aux = new(pista);
			aux->num=i+1;
			aux->cancion=Cancion[i];
			aux->interprete=Interprete[i];
			aux->genero=Genero[i];
			aux->sig=p;
			aux->ant=f;
			f->sig=aux;
			f=aux;
		}
		p->ant=f;
	}
	
	//INTERFAZ
	resp=1;
	system("mode con: cols=50 lines=25");
	while(resp==1){
	Color(9,0); //uso de Color(int TextColor, int Backcolor)
	cout<<"MUSICAMP"<<endl<<endl;
	Color(14,0); //uso de Color(int TextColor, int Backcolor)
	cout<<"MENU PRINCIPAL"<<endl;
	Color(15,0); //uso de Color(int TextColor, int Backcolor)
	cout<<"1. Todas las Canciones"<<endl;
	cout<<"2. Reproduccion Aleatoria"<<endl;
	cout<<"3. Reproduccion secuencial"<<endl;
	cout<<"4. Busqueda"<<endl;
	cout<<"5. Acerca de"<<endl;
	cout<<"6. Detener Reproduccion"<<endl;
	cout<<"Opcion: ";
	cin>>opc;
	
	system("cls");
	switch(opc){
			case 1:	//Ver Pistas
				Color(12,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"MOSTRAR TODAS LAS CANCIONES"<<endl<<endl;
				aux=p;
				do{
					Color(6,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"["<<aux->num<<"]"<<endl;
					Color(11,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Nombre: "<<aux->cancion<<endl;
					Color(15,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Interprete: "<<aux->interprete<<endl;
					Color(10,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Genero: "<<aux->genero<<endl;
					cout<<endl;
					system("pause");
					cout<<endl;
					aux=aux->sig;
				}while(aux != p);
				system("pause>nul");
			break;
			case 2: //Reproduccion Aleatoria
				srand(time(NULL));
				//Aleatorios sin repetir
				for(i=0; i < 30; i++){
					comp = 1+ rand()%30;
					int comp2 = 0;
					while(comp2 < i){
						if(comp != Aleatorios[comp2])
							comp2++;
						else{
							comp = 1 + rand()%30;
							comp2=0;
						}
					}
					Aleatorios[i]=comp;
					//cout<<Aleatorios[i]<<endl;
				}
					
				aux=p;
				cont=0;
				opc2=1;
				
				do{
				if(Aleatorios[cont] == aux->num){
					Color(5,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"REPRODUCCION ALEATORIA"<<endl<<endl;
					Color(4,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"( "<<cont+1<<" / 30 )"<<endl;
					Color(6,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"["<<aux->num<<"]"<<endl;
					Color(11,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Nombre: "<<aux->cancion<<endl;
					Color(15,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Interprete: "<<aux->interprete<<endl;
					Color(10,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Genero: "<<aux->genero<<endl;
					cout<<endl<<endl;
					Color(14,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Acciones"<<endl;
					Color(15,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"1. Anterior"<<endl;
					cout<<"2. Siguiente"<<endl;
					cout<<"0. Salir"<<endl;
					cout<<"Opcion: ";
					cin>>opc2;
					switch(opc2){
						case 0:
							opc2=0;
						break;
						case 1:
							cont--;
						break;
						case 2:
							cont++;
						break;
					}
					system("cls");
					
					//Contador de Tracks
					if(cont > 29){
						cont = 0;
					}else if(cont < 0){
						cont = 29;
					}
				}
				aux=aux->sig;
			}while(opc2 != 0);
				
			break;
			case 3: //Reproduccion secuencial
				aux=p;
				do{
				Color(2,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"REPRODUCCION SECUENCIAL"<<endl<<endl;
				Color(4,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"( "<<aux->num<<" / 30 )"<<endl;
				Color(6,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"["<<aux->num<<"]"<<endl;
				Color(11,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"Nombre: "<<aux->cancion<<endl;
				Color(15,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"Interprete: "<<aux->interprete<<endl;
				Color(10,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"Genero: "<<aux->genero<<endl;
				cout<<endl<<endl;
				Color(14,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"Acciones"<<endl;
				Color(15,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"1. Anterior"<<endl;
				cout<<"2. Siguiente"<<endl;
				cout<<"0. Salir"<<endl;
				cout<<"Opcion: ";
				cin>>opc2;
					switch(opc2){
						case 0:
							opc2=0;
						break;
						case 1:
							aux=aux->ant;
						break;
						case 2:
							aux=aux->sig;
						break;
					}
				system("cls");
				}while(opc2 != 0);
			break;
			case 4: //Busqueda
					Color(5,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"BUSQUEDA"<<endl<<endl;
					Color(15,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"1. Busqueda por Titulo"<<endl;
					cout<<"2. Busqueda por Interprete"<<endl;
					Color(8,0); //uso de Color(int TextColor, int Backcolor)
					cout<<"Opcion: ";
					cin>>opc3;
					system("cls");
					switch(opc3){
						case 1:
							Color(4,0); //uso de Color(int TextColor, int Backcolor)
							cout<<"REPRODUCCION POR TITULO"<<endl<<endl;
							Color(15,0); //uso de Color(int TextColor, int Backcolor)
							cout<<"-> Titulo de la Cancion: ";
							cin>>busqueda;
							band=0;
							aux=p;
							do{
								if(busqueda == aux->cancion){
									reprbusq=aux->num;
									band=1;
								}
								aux=aux->sig;
							}while(aux != p);
							
							cout<<endl;
							
							if(band==0){
								Color(12,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Cancion No Encontrada..."<<endl;
								system("pause");
							}else if(band==1){
								Color(10,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Cancion Encontrada... "<<endl<<endl;
								
								aux=p;
							do{
								if(reprbusq == aux->num){
								Color(4,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"EN REPRODUCCION..."<<endl<<endl;
								Color(6,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"["<<aux->num<<"]"<<endl;
								Color(11,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Nombre: "<<aux->cancion<<endl;
								Color(15,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Interprete: "<<aux->interprete<<endl;
								Color(10,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Genero: "<<aux->genero<<endl;
								cout<<endl;
								}
									aux=aux->sig;
								}while(aux != p);
								system("pause");
							}
						break;
						case 2:
							Color(14,0); //uso de Color(int TextColor, int Backcolor)
							cout<<"REPRODUCCION POR INTERPRETE"<<endl<<endl;
							Color(15,0); //uso de Color(int TextColor, int Backcolor)
							cout<<"-> Nombre del Interprete: ";
							cin>>busqueda;
							band=0;
							aux=p;
							do{
								if(busqueda == aux->interprete){
									reprbusq=aux->num;
									band=1;
								}
								aux=aux->sig;
							}while(aux != p);
							
							cout<<endl;
						
							if(band==0){
								Color(12,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Interprete No Encontrado..."<<endl;
								system("pause");
							}else if(band==1){
								Color(10,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Interprete Encontrado... "<<endl<<endl;
								aux=p;
							do{
								if(reprbusq == aux->num){
								Color(14,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"EN REPRODUCCION..."<<endl<<endl;
								Color(6,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"["<<aux->num<<"]"<<endl;
								Color(11,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Nombre: "<<aux->cancion<<endl;
								Color(15,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Interprete: "<<aux->interprete<<endl;
								Color(10,0); //uso de Color(int TextColor, int Backcolor)
								cout<<"Genero: "<<aux->genero<<endl;
								cout<<endl;
								}
									aux=aux->sig;
								}while(aux != p);
								system("pause");
							}
						break;
						default:
							cout<<"Opcion Invalida... Intenta otra vez..."<<endl;
							system("pause");	
						break;
					}
			break;
			case 5: //Acerca de
				Color(3,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"ACERCA DE"<<endl<<endl;
				Color(10,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"---REPRODUCTOR MUSICAMP---"<<endl;
				Color(15,0); //uso de Color(int TextColor, int Backcolor)
				cout<<"El mejor reproductor que se compromete con la \ncalidad de sonido y con la mejor interfaz \npara nuestros usuarios."<<endl<<endl;
				cout<<"* Creado por:"<<endl;
				cout<<"Edson Guadalupe Mera Orozco"<<endl;
				cout<<"Julian Fonseca Chan"<<endl<<endl;
				cout<<"*Contacto"<<endl;
				cout<<"WhatsApp:  +52 1 7721454667 \nFacebook:  Edson Mera Orozco \nInstagram: edj$ound_963"<<endl<<endl;
				cout<<"WhatsApp:  +52 1 5511557050 \nFacebook:  Juls F Chan"<<endl;
				cout<<endl<<endl;
				system("pause");
			break;
			case 6:	//Detener Reproducción
				resp=0;
			break;
			default:
				cout<<"Elige otra opcion..."<<endl;
				system("pause");
			break;
		}
		system("cls");
	}

return 0;
}
