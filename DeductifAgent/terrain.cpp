#include "terrain.h"
/*
Terrain::Terrain()
	:width(5),height(3){
		std::vector<string> a(width, "- ");
		std::vector<std::vector<string>> b(height, a);
		terrain = b;
}
*/

Terrain::Terrain(Joueur j1, Joueur j2)
	:width(6), height(3),_j1(j1), _j2(j2), fin(false){
		std::vector<string> a(width, "-  ");
		std::vector<std::vector<string>> b(height, a);
		terrain = b;
		for(size_t i = 0; i < height ; i++){
			for(size_t j = 0; j < width; j++){
				if(i==j1.getX() && j==j1.getY()) {
					if(j1.alaBalle()){
						terrain[i][j] = "A*  ";
					}
					else{
						terrain[i][j] = "A  ";
					}
				}
				if(i==j2.getX() && j==j2.getY()) {
					if(j2.alaBalle()){
						terrain[i][j] = "B*  ";
					}
					else{
						terrain[i][j] = "B  ";
					}
				}
			}
		}
}

void Terrain::afficher(){
	std::cout<<"*****************Affichage du terrain****************"<<std::endl;
	for(size_t i = 0; i < height; i++){
		for(size_t j = 0; j < width; j++){
			if(j == 0) std::cout<<"\t\t";
			std::cout << terrain[i][j];
		}
		std::cout<<std::endl;
	}
}

void Terrain::update(Joueur & j1, Joueur & j2){
	
	//------------APPLICATION DES REGLES--------
	//R1 : si j'ai la balle et personne devant, alors j'avance
	//R2 : si j'ai la balle et un adversaire devant, alors je l'évite
	if(j1.getY() == 5) {
			fin = true;
	}
	if(j1.alaBalle() && (j1.getY() + 1 <=5) && terrain[j1.getX()][j1.getY() + 1] == "-  "){
			j1.avancer();
	}
	else{
		j1.eviter();
	}
	
	//R3 : si je n'ai pas de balle, alors j'avance et cherche la balle
	//R4 : si je n'ai pas de balle, et un adversaire avec la balle, alors je le suis
	if(!j2.alaBalle()){
		if((j2.getY() - 1 >= 0) && terrain[j2.getX()][j2.getY() - 1] == "A*  ") {
			j2.avancer(j2.getX(),j2.getY() - 1);
		}
		
		else if ((j2.getY()+1 <= 5) && terrain[j2.getX()][j2.getY()+1] == "A*  "){
			j2.avancer(j2.getX(),j2.getY() + 1);
		}
		else if ((j2.getX()-1 >=0) && terrain[j2.getX()-1][j2.getY()] == "A*  "){
			j2.avancer(j2.getX()-1,j2.getY());
		}
		else if ((j2.getX()+1 <=2) && terrain[j2.getX()+1][j2.getY()] == "A*  "){
			j2.avancer(j2.getX()+1,j2.getY());
		}
		else{
			j2.avancer();
		}
	}


	//------------MAJ du terrain---------------
	std::vector<string> a(width, "-  ");
	std::vector<std::vector<string>> b(height, a);
	terrain = b;

	for(size_t i = 0; i < height ; i++){
			for(size_t j = 0; j < width; j++){
				if(i==j1.getX() && j==j1.getY()){
					if(j1.alaBalle()){
						terrain[i][j] = "A*  ";
					}
					else{
						terrain[i][j] = "A  ";
					}
				} 
				if(i==j2.getX() && j==j2.getY()) {
					if(j2.alaBalle()){
						terrain[i][j] = "B*  ";
					}
					else{
						terrain[i][j] = "B  ";
					}
				}
				if(i==j2.getX() && j==j2.getY() && i==j1.getX() && j==j1.getY()) {
					if(j2.alaBalle()){
						terrain[i][j] = "AB*  ";
					}
					else{
						terrain[i][j] = "A*B  ";
					}
				}
			}
		}

	for(size_t i = 0; i < height; i++){
		for(size_t j = 0; j < width; j++){
			if(j == 0) 
				std::cout<<"\t\t";

			std::cout << terrain[i][j];
		}
		std::cout<<std::endl;
	}
}