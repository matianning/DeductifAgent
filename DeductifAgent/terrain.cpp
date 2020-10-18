#include "terrain.h"
/*
Terrain::Terrain()
	:width(5),height(3){
		std::vector<string> a(width, "- ");
		std::vector<std::vector<string>> b(height, a);
		terrain = b;
}
*/

Terrain::Terrain(std::vector<Joueur> e1, std::vector<Joueur> e2)
    :width(11), height(9), _e1(e1), _e2(e2), fin(false){
    std::vector<string> a(width, "-  "); std::vector<std::vector<string>> b(height, a);
    terrain = b;
    for(size_t i = 0; i < height ; i++){
        for(size_t j = 0; j < width; j++){
            for(size_t k = 0; k < _e1.size(); k++){
                if(i==_e1[k].getX() && j==_e1[k].getY()) {
                    if(_e1[k].alaBalle()){
                        terrain[i][j] = "A*  ";
                    }
                    else{
                        terrain[i][j] = "A  ";
                    }
                }
                if(i==_e2[k].getX() && j==_e2[k].getY()) {
                    if(_e2[k].alaBalle()){
                        terrain[i][j] = "B*  ";
                    }
                    else{
                        terrain[i][j] = "B  ";
                    }
                }
            }

        }
    }

    for(size_t i = 0; i < _e1.size(); i++){
        move1.push_back(false);
        move2.push_back(false);
    }
}


void Terrain::afficher(){
    std::cout<<"*****************************************************"<<std::endl;
    std::cout<<"*****************Affichage du terrain****************"<<std::endl;
    std::cout<<"*****************************************************"<<std::endl;
    std::vector<string> a(width, "-  ");
    std::vector<std::vector<string>> b(height, a);
    terrain = b;

    for(size_t i = 0; i < height ; i++){
        for(size_t j = 0; j < width; j++){
            for(size_t k = 0; k < _e1.size(); k++){
                if(i==_e1[k].getX() && j==_e1[k].getY()) {
                    if(_e1[k].alaBalle()){
                        terrain[i][j] = "A*  ";
                    }
                    else{
                        terrain[i][j] = "A  ";
                    }
                }
                if(i==_e2[k].getX() && j==_e2[k].getY()) {
                    if(_e2[k].alaBalle()){
                        terrain[i][j] = "B*  ";
                    }
                    else{
                        terrain[i][j] = "B  ";
                    }
                }
                for(size_t w = 0; w < _e1.size(); w++){

                        if(i==_e2[k].getX() && j==_e2[k].getY() && i==_e1[w].getX() && j==_e1[w].getY()) {
                            if(_e2[k].alaBalle()){
                                terrain[i][j] = "AB*  ";
                            }
                            else if (_e1[k].alaBalle()){
                                terrain[i][j] = "A*B  ";
                            }
                            else{
                                terrain[i][j] = "AB  ";
                            }
                        }
                        if(k!=w){
                            if(i==_e2[k].getX() && j==_e2[k].getY() && i==_e2[w].getX() && j==_e2[w].getY()) {
                                if(_e2[k].alaBalle()){
                                    terrain[i][j] = "BB*  ";
                                }
                                else if (_e2[w].alaBalle()){
                                    terrain[i][j] = "B*B  ";
                                }
                                else{
                                    terrain[i][j] = "BB  ";
                                }
                            }
                            if(i==_e1[k].getX() && j==_e1[k].getY() && i==_e1[w].getX() && j==_e1[w].getY()) {
                                if(_e1[k].alaBalle()){
                                    terrain[i][j] = "A*  ";
                                }
                                else if (_e1[w].alaBalle()){
                                    terrain[i][j] = "A*A  ";
                                }
                                else{
                                    terrain[i][j] = "AA  ";
                                }
                            }
                        }



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

bool Terrain::isOver(){
    for(size_t i = 0; i < _e1.size(); i++){
        if(_e1[i].alaBalle() && _e1[i].getY() >= width-1){
            return true;
        }
    }
    for(size_t i = 0; i < _e2.size(); i++){
        if(_e2[i].alaBalle() && _e2[i].getY() <= 1){
            return true;
        }
    }
    return false;
}

void Terrain::update(){

    for(size_t i = 0; i < move1.size(); i++){
        move1[i] = false;
        move2[i] = false;
    }


    //Tester si la partie est finie
    if(isOver()) {
        fin = true;
        return;
    }
    //-----------------------------------APPLICATION DES REGLES--------------------------------------

    for(size_t i = 0; i < _e2.size(); i++){
        if(!_e2[i].alaBalle()){ //pas de balle , chercher la balle
            //============================Voisinage - 0 capturer=====================================
            for(size_t j = 0; j < _e1.size(); j++){
                if((_e1[j].getX() == _e2[i].getX()) && (_e1[j].getY() == _e2[i].getY())){
                    srand(time(NULL)); int n = rand()%100;
                    if(n < _e2[i].competence && _e1[j].alaBalle()){ // competence% de chance pour capturer la balle
                        //std::cout<<"capture!"<<std::endl;
                        _e1[j].balle = false;
                        _e2[i].balle = true;
                    }

                }
            }

            //============================Voisinage - 1 suivre=====================================
            //R3 : si je n'ai pas de balle, alors j'avance et cherche la balle
            //R4 : si je n'ai pas de balle, et un adversaire avec la balle, alors je le suis
            if((_e2[i].getY() - 1 >= 0) && ((terrain[_e2[i].getX()][_e2[i].getY() - 1] == "A*  ") ||
                            (_e2[i].getX()-1 >=0 && terrain[_e2[i].getX()-1][_e2[i].getY() - 1] == "A*  ") ||
                            (_e2[i].getX()+1 <=height-1 && terrain[_e2[i].getX()+1][_e2[i].getY() - 1] == "A*  ")
                                           ))  {
                if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX(),_e2[i].getY() - 1);
                    move2[i] = true;
                }
            }
            else if ((_e2[i].getY()+1 <= width-1) && ((terrain[_e2[i].getX()][_e2[i].getY()+1] == "A*  ")||
                          (_e2[i].getX()-1 >=0 && terrain[_e2[i].getX()-1][_e2[i].getY() + 1] == "A*  ") ||
                          (_e2[i].getX()+1 <=height-1 && terrain[_e2[i].getX()+1][_e2[i].getY() + 1] == "A*  ")
                                                      )){
                if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX(),_e2[i].getY() + 1);
                    move2[i] = true;
                }
            }
            else if ((_e2[i].getX()-1 >=0) && terrain[_e2[i].getX()-1][_e2[i].getY()] == "A*  "){
                if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX()-1,_e2[i].getY());
                    move2[i] = true;
                }
            }
            else if ((_e2[i].getX()+1 <=height -1) && terrain[_e2[i].getX()+1][_e2[i].getY()] == "A*  "){
                if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX()+1,_e2[i].getY());
                    move2[i] = true;
                }

            }
            else{

            //============================Voisinage - 2 courir vers la direction======================

                if((_e2[i].getY() - 2 >= 0) && (terrain[_e2[i].getX()][_e2[i].getY() - 2] == "A*  "
                                                || (_e2[i].getX()-1>=0 && terrain[_e2[i].getX()-1][_e2[i].getY() - 2] == "A*  " )
                                                || (_e2[i].getX()+1<=height-1 && terrain[_e2[i].getX()+1][_e2[i].getY() - 2] == "A*  " )
                                                ||(_e2[i].getX()-2>=0 && terrain[_e2[i].getX()-2][_e2[i].getY() - 2] == "A*  " )
                                                ||(_e2[i].getX()+2<=height-1 && terrain[_e2[i].getX()+2][_e2[i].getY() - 2] == "A*  " )
                                                )) {
                    if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX(),_e2[i].getY() - 1);
                    move2[i] = true;
                    }
                }
                else if ((_e2[i].getY() + 2 <= width-1) && (terrain[_e2[i].getX()][_e2[i].getY()+2] == "A*  "
                                                || (_e2[i].getX()-1>=0 && terrain[_e2[i].getX()-1][_e2[i].getY() + 2] == "A*  " )
                                                || (_e2[i].getX()+1<=height-1 && terrain[_e2[i].getX()+1][_e2[i].getY() + 2] == "A*  " )
                                                ||(_e2[i].getX()-2>=0 && terrain[_e2[i].getX()-2][_e2[i].getY() + 2] == "A*  " )
                                                ||(_e2[i].getX()+2<=height-1 && terrain[_e2[i].getX()+2][_e2[i].getY() + 2] == "A*  " )
                                                            )){
                    if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX(),_e2[i].getY() + 1);
                    move2[i] = true;
                    }
                }
                else if ((_e2[i].getX() - 2 >=0) && (terrain[_e2[i].getX()-2][_e2[i].getY()] == "A*  "
                                                     || (_e2[i].getY()-1>=0 && terrain[_e2[i].getX()-1][_e2[i].getY() -1] == "A*  " )
                                                     || (_e2[i].getY()+1<=width-1 && terrain[_e2[i].getX()-1][_e2[i].getY() + 1] == "A*  " )
                                                     || (_e2[i].getY()-2>=0 && terrain[_e2[i].getX()-1][_e2[i].getY() -2] == "A*  " )
                                                     || (_e2[i].getY()+2<=width-1 && terrain[_e2[i].getX()-1][_e2[i].getY() + 2] == "A*  " )
                                                     )){

                    if(!move2[i]){
                    _e2[i].avancer(_e2[i].getX()-1,_e2[i].getY());
                    move2[i] = true;
                    }
                }
                else if ((_e2[i].getX() + 2 <=height -1) && (terrain[_e2[i].getX()+2][_e2[i].getY()] == "A*  "
                                                             || (_e2[i].getY()-1>=0 && terrain[_e2[i].getX()+1][_e2[i].getY() -1] == "A*  " )
                                                             || (_e2[i].getY()+1<=width-1 && terrain[_e2[i].getX()+1][_e2[i].getY() + 1] == "A*  " )
                                                             || (_e2[i].getY()-2>=0 && terrain[_e2[i].getX()+1][_e2[i].getY() -2] == "A*  " )
                                                             || (_e2[i].getY()+2<=width-1 && terrain[_e2[i].getX()+1][_e2[i].getY() + 2] == "A*  " )
                                                             )){
                    if(!move2[i]){
                        _e2[i].avancer(_e2[i].getX()+1,_e2[i].getY());
                        move2[i] = true;
                        }
                }
                else{   //pas d'adversaire dans ce voisinage
                    int avan = rand()%100;
                    if(avan < 80 && !move2[i]){
                        _e2[i].avancer();
                        move2[i] = true;
                    }
                }
            }




        }
        else{ //si _e2[i] a la balle

        }
    }

	//R1 : si j'ai la balle et personne devant, alors j'avance
	//R2 : si j'ai la balle et un adversaire devant, alors je l'évite
    for(size_t i = 0; i < _e1.size(); i++){

        if(!_e1[i].alaBalle()){
            int avan = rand()%100;
            if(avan < 80 && !move1[i]){
                move1[i] = true;
                _e1[i].avancer();
            }
        }
        else{
            if((_e1[i].getY() + 1 <= width) && terrain[_e1[i].getX()][_e1[i].getY() + 1] == "-  "){
                int avan = rand()%100;
                if(avan < 80-20 && !move1[i]){
                    move1[i] = true;
                    _e1[i].avancer();
                }
            }
            else{
                if(!move1[i]){
                    _e1[i].eviter();
                    move1[i] = true;
                }
            }
        }

        if(!_e2[i].alaBalle()){
            int avan = rand()%100;
            if(avan < 80 && !move2[i]){
                _e2[i].avancer();
                move2[i] = true;
            }
        }
        else{
            if((_e2[i].getY() + 1 <= width) && terrain[_e2[i].getX()][_e2[i].getY() + 1] == "-  "){
                int avan = rand()%100;
                if(avan < 80 && !move2[i]){
                    move2[i] = true;
                    _e2[i].avancer();
                }
            }
            else{
                if(!move2[i]){
                    _e2[i].eviter();
                    move2[i] = true;
                }
            }
        }

    }

	





    //------------MAJ l'affichage du terrain---------------
    afficher();

}
