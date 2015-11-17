
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {
    factory *factory1 = new factory();

    int years = 3;
    int iterations = years * 365 / 42;

    for(int i = 0; i < iterations; i++){
        vector<chicken> chick;

        /* create chicks */
        for (int i = 0; i < 50000; i++) {
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