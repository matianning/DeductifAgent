#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>


using namespace std;

class Joueur {

	private:
		int coordX; //Abscisse dans la grille
		int coordY; //Ordonnée dans la grille

		bool direction;

	public:
        bool balle; //Vrai si le joueur a la balle, faux sinon
        int competence;
		//Constructeur
		Joueur(int x, int y,bool b, bool dir);
		
		//Accesseur
		int getX();
		int getY();
		bool alaBalle();
		
		//Méthodes
		void avancer(); 
		void avancer(int x, int y);
		void eviter();
		
};
