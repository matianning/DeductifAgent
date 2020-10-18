#include "joueur.h"
#include "terrain.h"
#include "ruleBase.h"
#include "rule.h"

int main()
{

    RuleBase RB;
    Joueur j1(1,0,true,true), j2(1,5,false,false);
    Terrain t(j1,j2);

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
    t.afficher();
    bool quitter = false;
    do {
        std::string input("");

        std::cout<<"-------------Veuillez saisir une commande : ----------"<<std::endl;
        std::cout<<"\t-p : passer a l'etape suivante"<<std::endl;
        std::cout<<"\t-q : quitter "<<std::endl;
        std::cin>>input;
        if(input == "q") quitter = true;
        else{
            t.update(j1,j2);
        }

        if(t.fin){
            std::cout<< "-----------------FIN DE PARTIE--------------------"<<std::endl;
            break;
        }

    }while(quitter != true);


    return 0;
}
