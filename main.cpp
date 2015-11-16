
#include <iostream>
#include "chicken.h"

using namespace std;

int main() {
    factory *factory1 = new factory();

    vector<chicken> chick;

    /* create chicks */
    for(int i = 0; i < 100; i++){
        chick.push_back(chicken());
    }

    for(int i = 0; i < 42; i++){
        factory1->nextDay(&chick);
    }

    return 0;
}