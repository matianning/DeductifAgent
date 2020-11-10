#include "joueur.h"
#include "terrain.h"
#include "ruleBase.h"
#include "rule.h"

int main()
{

    RuleBase RB;
    /*
        Rule r1(std::vector<int>{0, 3, 4}); // si j'ai la balle et peronne devant, alors j'avance
        Rule r2(std::vector<int>{0, 2, 5}); //si j'ai la balle et adversaire devant, alors je passe la balle
        Rule r3(std::vector<int>{1, 4}); //si j'ai pas de balle, alors j'avance aléatoirement

        std::cout<< "Fait : "<<std::endl;
        std::cout<< "0 : avoir la balle"<<std::endl;
        std::cout<< "1 : pas de balle"<<std::endl;
        std::cout<< "2 : adversaire devant"<<std::endl;
        std::cout<< "3 : personne devant"<<std::endl;
        std::cout<< "4 : avancer (aleatoirement)"<<std::endl;
        std::cout<< "5 : passer la balle"<<std::endl;

        RB.addRule(r1); RB.addRule(r2); RB.addRule(r3); RB.afficher();
    */

    Joueur j10(0,0,false,true), j11(2,1,false,true), j12(4,2,true, true), j13(6,1,false,true), j14(8,0,false,true);
    Joueur j20(0,10,false,false), j21(2,9,false,false), j22(4,8,false,false),j23(6,9,false,false),j24(8,10,false,false);
    std::vector<Joueur> equipe1, equipe2;
    equipe1.push_back(j10);equipe1.push_back(j11);equipe1.push_back(j12);equipe1.push_back(j13);equipe1.push_back(j14);
    equipe2.push_back(j20);equipe2.push_back(j21);equipe2.push_back(j22);equipe2.push_back(j23);equipe2.push_back(j24);
    Terrain t(equipe1,equipe2);

    t.afficher();
    bool quitter = false;
    do {
        std::string input("");

        std::cout<<"-------------Veuillez saisir une commande : ----------"<<std::endl;
        std::cout<<"\t-p : passer a l'etape suivante"<<std::endl;
        std::cout<<"\t-q : quitter "<<std::endl;
        std::cin>>input;

        std::cout<<input<<std::endl;
        if(input == "q") quitter = true;
        else{
            t.update();
        }

        if(t.fin){
            std::cout<< "-----------------FIN DE PARTIE--------------------"<<std::endl;
            break;
        }

    }while(quitter != true);


    return 0;
}
