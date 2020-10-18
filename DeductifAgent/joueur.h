#pragma once

#include <stdlib.h>
#include <iostream>


using namespace std;

class Joueur {

	private:
		int coordX; //Abscisse dans la grille
		int coordY; //Ordonnée dans la grille
		bool balle; //Vrai si le joueur a la balle, faux sinon
		bool direction;

	public:
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