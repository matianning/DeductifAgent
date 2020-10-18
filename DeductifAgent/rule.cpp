#include "rule.h"

void Rule::afficher(){
	for(size_t i = 0; i < atomes.size(); i++){
		
		if(i == atomes.size() - 1){
			std::cout<<" => "<<atomes[i];
		}
		else if (i == atomes.size() - 2){
			std::cout<<atomes[i];
		}
		else{
			std::cout<<atomes[i]<<",";
		}
	}
	std::cout<<std::endl;
}

void Rule::addAtome(int atome){
	atomes.push_back(atome);
}