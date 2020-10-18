#include "ruleBase.h"

void RuleBase::afficher(){
	std::cout<<"************Affichage de la base de Règle************"<<std::endl;
	for(size_t i = 0; i < rules.size(); i++){
		std::cout<<"R"<<i<<" : ";
		rules[i].afficher();
	}
	
}

void RuleBase::addRule(Rule r){
	rules.push_back(r);
}

