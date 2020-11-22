#include "ArgumentationGraph.h"

void ArgumentationGraph::addArgument(const Argument & argument){
    std::vector<Argument> a;
    a.push_back(argument);
    arguments.push_back(a);
}


void ArgumentationGraph::addAttaque(const Argument &a, const Argument &b){
    for(size_t i = 0; i < arguments.size(); i++){
        if(arguments[i][0].getName() == b.getName()){
            bool doublon = false;
            for(size_t j = 0; j < arguments[i].size(); j++){
                if(arguments[i][j].getName() == a.getName()){
                    doublon = true;
                }
            }
            if(!doublon){
                arguments[i].push_back(Argument(a));
            }
        }
    }
}

void ArgumentationGraph::showGraph(){
    std::cout<<"***********Le Graphe d'Argumentation***********"<<std::endl;
    for(size_t i = 0; i < arguments.size(); i++){
        for(size_t j = 0; j < arguments[i].size(); j++){
            if( j == 0){
                std::cout<<arguments[i][j].getName()<<" : ";
            }
            else{
                std::cout<<arguments[i][j].getName()<<" ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"*******************************************"<<std::endl;
}

void ArgumentationGraph::resolve(){
    std::cout<<"Resolve Arguments ..."<<std::endl;
    //Pour exemple : Selon AA agree, P2 et P3 n'ont pas d'arguments attaquants, ils sont IN.
    //On va résoudre ce graphe à partir de cela.
    In.push_back(Argument("P2"));
    In.push_back(Argument("P3"));

    for(int iter = 0; iter < 50; iter++){
    //**********Chercher les arguments OUT***************
    //An argument is Out if at least one of its attackers is IN
        for(size_t i = 0; i < arguments.size(); i++){
            bool out = false;
            for(size_t j = 1; j < arguments[i].size(); j++){
                   for(size_t k = 0; k < In.size(); k++){
                        if(arguments[i][j].getName() == In[k].getName()){
                            out = true;
                            break;
                        }
                    }
                if(out) break;
            }

            if(out){
                bool doublon = false;
                for(size_t w = 0; w < Out.size(); w++){
                    if(Out[w].getName() == arguments[i][0].getName()){
                        doublon = true;
                        break;
                    }
                }
                if(!doublon){
                    Out.push_back(Argument(arguments[i][0]));
                }

            }
        }

    //**********Chercher les arguments IN**************
    for(size_t i = 0; i < arguments.size(); i++){

        bool undec = true;
        for(size_t j = 0; j < Out.size(); j++){
            if(arguments[i][0].getName() == Out[j].getName()) undec = false;
        }

        if(undec){
            bool in = true;
            for(size_t k = 1; k < arguments[i].size(); k++){
                if(in){
                    for(size_t w = 0; w < Out.size(); w++){
                        if(arguments[i][k].getName() == Out[w].getName()) break;
                        else{
                            if(w!=Out.size()-1) continue;
                            else{
                                 in = false;
                                 break;
                            }
                        }
                    }
                }
                else  break;
            }
            if(in){
                bool doublon = false;
                for(size_t ii = 0; ii < In.size(); ii++)
                    if(arguments[i][0].getName() == In[ii].getName()) doublon = true;
                if(!doublon)
                    In.push_back(Argument(arguments[i][0]));
            }
        }
    }
  }

    std::cout<<"IN Arguments : ";
    for(size_t i = 0; i < In.size(); i++){
        std::cout << In[i].getName()<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"OUT Arguments : ";
    for(size_t i = 0; i < Out.size(); i++){
        std::cout << Out[i].getName()<< " ";
    }
    std::cout<<std::endl;



}
