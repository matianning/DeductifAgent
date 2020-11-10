#pragma once 
#include <vector>
#include <iostream>
class Rule{

	public : 
		Rule() = default;
		Rule(std::vector<int> r) : atomes(r){}
		void afficher();
		void addAtome(int atome);



		std::vector<int> atomes;


};