#include <iostream>
#include "ArgumentationGraph.h"
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
    /*
    Exemple utilisé :
    X = {P1, P2, P3, C1, C2, C3}
    A = {(P1, C0), (P0, C0), (C1, P1), (P2, C1), (C2, P0), (C3, P0), (P3, C2), (P3, C3)}
    */

    float temps;
    clock_t t1, t2;
    t1 = clock();


    ArgumentationGraph initialFramework;
    int nb_noeud = 10000;
 /*
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
*/


    for(int i = 0; i < nb_noeud; i++){
        char str[10];
        itoa(i, str, 10);
        Argument Tmp(str);
        initialFramework.addArgument(Tmp);
    }

    for(int i = 0; i < nb_noeud; i++){
        char str1[10], str2[10], str3[10];
        int n = rand()%nb_noeud;
        itoa(i, str1, 10);itoa(n, str2, 10);itoa(i+1, str3, 10);
        Argument Tmp1(str1), Tmp2(str2), Tmp3(str3);
        initialFramework.addAttaque(Tmp1,Tmp2);
        initialFramework.addAttaque(Tmp1,Tmp3);
    }

    initialFramework.showGraph();   //Affichage des relations
    initialFramework.resolve();     //Affichage des résultats

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);



    return 0;
}
