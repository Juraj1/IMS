/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: source file for factory class
 */
#include "factory.h"

using namespace std;

void factory::factoryInit() {
    /* conversion from tonnes to kilos to tonnes */
    this->foodAmountGrams    = 1000*1000*this->INITIAL_FOOD_AMOUNT_TONNES;
}

void factory::substractFood(float amount) {
    this->foodAmountGrams   -= amount;
}

void factory::addFood(int amount) {
    /* conversion from kilos to grams */
    this->foodAmountGrams   += 1000*amount;
}

void factory::nextDay(vector<chicken> chickVector) {
    for(vector<chicken>::iterator it = chickVector.begin(); it != chickVector.end(); it++){
        it->nextDay(nullptr);
    }
}