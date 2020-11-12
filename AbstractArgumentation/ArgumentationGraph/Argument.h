#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <iostream>
#include <string>


class Argument{

public :
        Argument() = default;
        Argument(const std::string & a);
        Argument(const Argument & argument){name = argument.getName();}

        std::string getName() const{return name;}


private :
        std::string name;


};











#endif // ARGUMENT_H
