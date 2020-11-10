#pragma once
#include <iostream>
#include <vector>
#include "rule.h"

class RuleBase{
	public : 
	RuleBase() = default;
	RuleBase(std::vector<Rule> rs) : rules(rs){}

	void addRule(Rule r);
	void afficher();

	std::vector<Rule> rules;


};