/*
 * Muhammed YILMAZ
 * 150150149
 * 10.04.2018
 */

#include <iostream>
#include "Grayling.h"
#include "Grayling1.h"
#include "Grayling2.h"
#include "Grayling3.h"

using namespace std;

void show(Grayling *g);
void reproduce(Grayling *g);
void aging(Grayling *g);
void toKill(Grayling *g);

int main() {

    Grayling1 G1_1('f',"G1_1");                 //Create a Grayling1 with gender and name attributes
    Grayling1 G1_2(G1_1,'f',"G1_2_CC");       // Copy Constructor *_CC
    Grayling2 G2_1('m',"G2_1");
    Grayling3 G3_1('f',"G3_1");

    cout << endl;

    show(&G1_1);
    show(&G1_2);
    show(&G2_1);
    show(&G3_1);

    cout << endl;

    aging(&G1_2);

    cout << endl;

    aging(&G1_1);
    aging(&G1_1);
    aging(&G1_1);
    reproduce(&G1_1);
    aging(&G1_1);

    cout << endl;

    aging(&G2_1);
    aging(&G2_1);
    aging(&G2_1);
    reproduce(&G2_1);
    aging(&G2_1);

    cout << endl;

    aging(&G3_1);
    aging(&G3_1);
    aging(&G3_1);
    reproduce(&G3_1);
    aging(&G3_1);

    cout << endl;
    getchar();

    /*
    Grayling1 G1_F1('f',"G1_F1");
    toKill(&G1_F1);

    Grayling1 G1_M1('m',"G1_M1");
    toKill(&G1_M1);

    Grayling2 G2_F1('f',"G2_F1");
    toKill(&G2_F1);

    Grayling2 G2_M1('m',"G2_M1");
    toKill(&G2_M1);

    Grayling3 G3_F1('f',"G3_F1");
    toKill(&G3_F1);

    Grayling3 G3_M1('m',"G3_M1");
    toKill(&G3_M1);

    Grayling a;
    toKill(&a);
    */

    return 0;
}

void aging(Grayling *g) {
    g->aging();
}

void reproduce(Grayling *g) {
    g->givebirth();
}

void show(Grayling *g) {
    g->print();
}

void toKill(Grayling *g){
    for (int i = 0; i < 5; ++i) {
        show(g);
        reproduce(g);
        aging(g);
        cout << endl;
    }
    cout << endl << endl << endl;
}