
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {

    factory *factory1 = new factory();

    vector<chicken> chick;

    /* create chicks */
    for(int i = 0; i < 2; i++){
        chick.push_back(chicken());
    }

    /* start simulation time */
    for(int i = 0; i < 42; i++){
        factory1->nextDay(&chick);
    }

    factory1->statistics();

    /* clean up chickens */
    vector<chicken>().swap(chick);

    /* clean up factory */
    delete factory1;

    return 0;
}