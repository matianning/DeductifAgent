#include "joueur.h"

//Constructeur
Joueur::Joueur(int x, int y,bool b, bool dir)
    :coordX(x), coordY(y), balle(b), direction(dir){
    srand(time(NULL));
    competence = 5+rand()%100;
}

//Accesseurs
int Joueur::getX() { return coordX;}
int Joueur::getY() { return coordY;}
bool Joueur::alaBalle() { return balle;}

//Methodes
void Joueur::avancer() {
    srand(time(NULL));
    int n1 = rand()%100;
    int n2 = rand()%10;

    //if(n1 < 66){
        if(direction){
            if(coordY <= 10-1){ coordY++; }
        }
        else{
            if(coordY > 0){ coordY--;}
        }
        /*
    }
    else{
        if(n2 < 5){
            if(coordX > 0){
                coordX--;
            }
            else{
                coordX++;
            }
        }
        else{
            if(coordX < 11){
                coordX++;
            }
            else{
                coordX--;
            }
        }
    }
*/

}		

void Joueur::avancer(int x, int y){
	coordX = x;
	coordY = y;
}

void Joueur::eviter(){
	srand(time(NULL));
    int n = rand()%10;
    if(coordX == 0){
        coordX++; return;
    }
    if(coordX == 8){
        coordX--; return;
    }
    if(n < 6 && coordX > 0){ coordX--;}
    if(n >=6 && coordX < 11){ coordX++;}
}
