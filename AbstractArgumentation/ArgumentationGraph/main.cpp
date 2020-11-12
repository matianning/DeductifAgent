#include <iostream>
#include "ArgumentationGraph.h"

using namespace std;

int main()
{
    /*
    Exemple utilisé :
    X = {P1, P2, P3, C1, C2, C3}
    A = {(P1, C0), (P0, C0), (C1, P1), (P2, C1), (C2, P0), (C3, P0), (P3, C2), (P3, C3)}
    */

    ArgumentationGraph initialFramework;
    Argument C0("C0"), C1("C1"), C2("C2"), C3("C3"),
             P0("P0"), P1("P1"), P2("P2"), P3("P3");

    initialFramework.addArgument(C0);
    initialFramework.addArgument(C1);
    initialFramework.addArgument(C2);
    initialFramework.addArgument(C3);
    initialFramework.addArgument(P0);
    initialFramework.addArgument(P1);
    initialFramework.addArgument(P2);
    initialFramework.addArgument(P3);

    initialFramework.addAttaque(P1, C0);
    initialFramework.addAttaque(P0, C0);
    initialFramework.addAttaque(C1, P1);
    initialFramework.addAttaque(P2, C1);
    initialFramework.addAttaque(C2, P0);
    initialFramework.addAttaque(C3, P0);
    initialFramework.addAttaque(P3, C2);
    initialFramework.addAttaque(P3, C3);

    initialFramework.showGraph();   //Affichage des relations
    initialFramework.resolve();     //Affichage des résultats






    return 0;
}
