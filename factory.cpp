/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: source file for factory class
 */
#include "factory.h"

using namespace std;

/**
 * @brief constructor
 */
factory::factory(){
    /* conversion from tonnes to kilos to tonnes */
    this->foodAmountGrams   = 1000*1000*this->INITIAL_FOOD_AMOUNT_TONNES;
    this->dayOfLife         = 0;
}


/**
 * @brief substract food from food pile
 * @param amount amount of food to substract in grams
 */
void factory::substractFood(float amount) {
    this->foodAmountGrams   -= amount;
}

/**
 * @brief adds food in kilograms
 * @param amount adds number of kilograms specified
 */
void factory::addFood(int amount) {
    /* conversion from kilos to grams */
    this->foodAmountGrams   += 1000*amount;
}

/**
 * @brief swaps all chicken to the next day
 * @param chickVector vector of chicks that we want to transform to the next day
 */
void factory::nextDay(vector<chicken> *chickVector) {
    this->dayOfLife++;
    for(vector<chicken>::iterator it = chickVector->begin(); it != chickVector->end(); it++){
        it->nextDay(this);
#ifdef DEBUG
        cout << "Day of Life: " << it->getDay() << endl;
#endif
    }
#ifdef DEBUG
    cout << "Factory day: " << this->dayOfLife << endl;
#endif


}

/**
 * @brief man harvests chicks after certain day count
 */
void factory::harvestChick(chicken *chick) {

}


/**
 * @brief man destroys chicks after it's death from disease
 */
void factory::destroyChick(chicken *chick) {
    /* chicken is useless, just delete him */
    delete chick;
}