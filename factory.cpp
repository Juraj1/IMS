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
    /* conversion from tonnes to kilos*/
    this->BR1FoodAmount = this->INITIAL_FOOD_AMOUNT;
    this->BR2FoodAmount = this->INITIAL_FOOD_AMOUNT;
    this->BR3FoodAmount = this->INITIAL_FOOD_AMOUNT;

    this->BR1foodAmountUsed = 0;
    this->BR2foodAmountUsed = 0;
    this->BR3foodAmountUsed = 0;

    this->totalWaterUsed    = 0;
    this->totalFoodUsed     = 0;

    this->dayOfWork         = 0;
#ifdef DEBUG
    cout << "Factory: Object initialised" << endl;
    cout << "Factory: Food delivery of BR1 " << this->BR1FoodAmount << " kg" << endl;
    cout << "Factory: Food delivery of BR2 " << this->BR2FoodAmount << " kg" << endl;
    cout << "Factory: Food delivery of BR3 " << this->BR3FoodAmount << " kg" << endl;
#endif

}


/**
 * @brief substract food from food pile
 * @param amount amount of food to substract in kilos
 */
void factory::substractFood(float amount, int type) {
    switch(type){
        case 1: /* BR1 */
            this->BR1FoodAmount -= amount;
            break;
        case 2: /* BR2 */
            this->BR2FoodAmount -= amount;
            break;
        case 3: /* BR3 */
            this->BR3FoodAmount -= amount;
            break;
        default:
            return;
    }
#ifdef DEBUG
    cout << "Factory: " << amount << " grams of food substracted." << endl;
    cout << "Factory: " << this->BR1FoodAmount << " kilos of BR1 left" << endl;
    cout << "Factory: " << this->BR2FoodAmount << " kilos of BR2 left" << endl;
    cout << "Factory: " << this->BR3FoodAmount << " kilos of BR3 left" << endl;

#endif
}

/**
 * @brief adds food in kilograms
 * @param amount adds number of kilograms specified
 */
void factory::addFood(int amount, int type) {
    /* conversion from kilos to grams */
    switch(type){
        case 1: /* BR1 */
            this->BR1FoodAmount += 1000*amount;
            break;
        case 2: /* BR2 */
            this->BR1FoodAmount += 1000*amount;
            break;
        case 3: /* BR3 */
            this->BR1FoodAmount += 1000*amount;
            break;
        default:
            return;
    }
#ifdef DEBUG
    cout << "Factory: Food added." << endl;
#endif
}

/**
 * @brief swaps all chicken to the next day
 * @param chickVector vector of chicks that we want to transform to the next day
 */
void factory::nextDay(vector<chicken> *chickVector) {
    this->dayOfWork++;
#ifdef DEBUG
    cout    << "####################### Factory day: " << this->dayOfWork << " ########################"<< endl
            << endl;
#endif
    for(vector<chicken>::iterator it = chickVector->begin(); it != chickVector->end(); it++){
        it->nextDay(this);
#ifdef DEBUG
        cout << "Chick's day of life: " << it->getDay() << endl << endl;
#endif
    }
}

/**
 * @brief man harvests chicks after certain day count
 */
void factory::harvestChick(chicken *chick) {
#ifdef DEBUG
    cout << "Harvesting chicken" << endl;
#endif
    this->harvestedChicken++;

    /* food used */
    this->BR1foodAmountUsed += chick->BR1usedFood;
    this->BR2foodAmountUsed += chick->BR2usedFood;
    this->BR3foodAmountUsed += chick->BR3usedFood;

    this->totalFoodUsed += chick->totalFoodUsed;
    /* water used */
    this->totalWaterUsed += chick->usedWater;
}


/**
 * @brief man destroys chicks after it's death from disease
 */
void factory::destroyChick(chicken *chick) {
    /* chicken is useless, just delete him */
#ifdef DEBUG
    cout << "Destroying chicken" << endl;
#endif
    this->destroyedChicken++;
}

/**
 * @brief print statistics
 */
void factory::statistics() {
    cout    << "########## TOTAL STATISTICS ##########"                                     << endl;
    cout    << "Chicken delivered:    " << this->harvestedChicken + this->destroyedChicken  << endl;
    cout    << "Chicken infected:     " << this->destroyedChicken                           << endl;
    cout    << "Chicken harvested     " << this->harvestedChicken                           << endl;
    cout    << "BR1 food delivered:   " << this->INITIAL_FOOD_AMOUNT << " kilograms"        << endl;
    cout    << "BR1 food used:        " << this->BR1foodAmountUsed << " kilograms"          << endl;
    cout    << "BR2 food delivered:   " << this->INITIAL_FOOD_AMOUNT<< " kilograms"         << endl;
    cout    << "BR2 food used:        " << this->BR2foodAmountUsed << " kilograms"          << endl;
    cout    << "BR3 food delivered:   " << this->INITIAL_FOOD_AMOUNT<< " kilograms"         << endl;
    cout    << "BR3 food used:        " << this->BR3foodAmountUsed << " kilograms"          << endl;
    cout    << "Total food used:      " << this->totalFoodUsed << " kilograms"              << endl;
    cout    << "Total water used      " << this->totalWaterUsed << " liters"                << endl;
}