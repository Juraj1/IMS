
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {


    factory *factory1 = new factory();

    /* chick price modificator */
    factory1->pricePerYoungChick  = 8;        /* czech crowns per 1 1 day chick */
    factory1->chickPricePerKg     = 65;       /* 65kc/kg */

    /* average pay modificator */
    factory1->averagePayPerIteration = 20000 / 30; /* conversion for pay per iteration */

    /* count of employees modificator */
    factory1->employeeCount = 30;

    /* food price modificator */
    factory1->BR1PricePerKg = 13;       /* 12kc/kg */
    factory1->BR2PricePerKg = 13;
    factory1->BR3PricePerKg = 10;

    /* water price modificator */
    factory1->waterCostPerL = 0.08104;   /* price per liter */

    /* chicken count modificator */
    int chickenCount = 20000;


    vector<chicken> chick;

    /* create chicks */
    for (int i = 0; i < chickenCount; i++) {
        chick.push_back(chicken());
    }


    /* start simulation time */
    for (int i = 0; i < 42; i++) {
        factory1->nextDay(&chick);
    }

    /* print statistics and financial report */
    factory1->statistics(&chick);

    /* clean up chickens */
    vector<chicken>().swap(chick);


    /* clean up factory */
    delete factory1;

    return 0;
}