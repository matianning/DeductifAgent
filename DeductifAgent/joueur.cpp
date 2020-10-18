#include "joueur.h"
#include <time.h>
//Constructeur
Joueur::Joueur(int x, int y,bool b, bool dir)
	:coordX(x), coordY(y), balle(b), direction(dir){}

//Accesseurs
int Joueur::getX() { return coordX;}
int Joueur::getY() { return coordY;}
bool Joueur::alaBalle() { return balle;}

//Methodes
void Joueur::avancer() {
	
	//R1 avancer
	if(direction){
		if(coordY < 6){ coordY++; }
	}
	else{
		if(coordY > 0){ coordY--;}
	}

}		

void Joueur::avancer(int x, int y){
	coordX = x;
	coordY = y;
}

void Joueur::eviter(){
	srand(time(NULL));

	int n = rand()%10;
	
	if(n < 6 && coordX > 0){
		coordX--;
	}
	if(n >=6 && coordX < 3){
		coordX++;
	}
}
