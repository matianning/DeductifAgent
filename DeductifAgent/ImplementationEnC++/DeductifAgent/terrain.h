#pragma once

#include "joueur.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Terrain{

public : 
		Terrain() = default;
        Terrain(std::vector<Joueur> equipe1, std::vector<Joueur> equipe2);
		int getWidth(){return width;}
		int getHeight(){return height;}
		void afficher();
        void update();
        bool isOver();
		bool fin;
private : 
		int width;
		int height;

		std::vector<std::vector<std::string>> terrain;
        std::vector<Joueur> _e1;
        std::vector<Joueur> _e2;
        std::vector<bool> move1;
        std::vector<bool> move2;

};
