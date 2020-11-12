#ifndef ARGUMENTATIONGRAPH_H
#define ARGUMENTATIONGRAPH_H

#include <vector>
#include <iostream>
#include "Argument.h"



class ArgumentationGraph{
public :
        ArgumentationGraph() = default;

        void addArgument(const Argument & argument);
        void addAttaque(const Argument & a, const Argument & b);
        void resolve();
        void showGraph();

private :
        std::vector<std::vector<Argument>> arguments;
        /*
        Argument0               |Argument1              |Argument2  ...
        ArgumentAttaquant0       ArgumentAttaquant0      ArgumentAttaquant0
        ArgumentAttaquant1       ArgumentAttaquant1      ArgumentAttaquant1
        ArgumentAttaquant2       ArgumentAttaquant2      ArgumentAttaquant2
        ...                      ...                     ...
        */
        std::vector<Argument> In;
        std::vector<Argument> Out;
        int maxIter = 5;
};













#endif // ARGUMENTATIONGRAPH_H
