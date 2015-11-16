
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {
    factory *factory1 = new factory();

    vector<chicken> chick;

    /* create chicks */
    for(int i = 0; i < 20000; i++){
        chick.push_back(chicken());
    }

    factory1->nextDay(&chick);
    factory1->nextDay(&chick);

    return 0;
}