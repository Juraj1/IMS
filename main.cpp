
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {

    int years = 1;
    int iterations = years * 365 / 42;
    int chickenCount = 50000;

    factory *factory1 = new factory();

    for(int i = 0; i < iterations; i++){
        vector<chicken> chick;

        /* create chicks */
        for (int i = 0; i < chickenCount; i++) {
            chick.push_back(chicken());
        }


        /* start simulation time */
        for (int i = 0; i < 42; i++) {
            factory1->nextDay(&chick);
        }

        factory1->statistics();

        /* clean up chickens */
        vector<chicken>().swap(chick);

    }
    /* clean up factory */
    delete factory1;

    return 0;
}