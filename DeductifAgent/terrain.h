#pragma once

#include "joueur.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Terrain{

public : 
		Terrain() = default;
		Terrain(Joueur j1, Joueur j2);
		int getWidth(){return width;}
		int getHeight(){return height;}
		void afficher();
		void update(Joueur & j1, Joueur & j2);
		bool fin;
private : 
		int width;
		int height;

		std::vector<std::vector<std::string>> terrain;
		Joueur _j1;
		Joueur _j2;

};