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

    this->iterationCount    = 1;

    this->dayOfWork         = 0;

    this->harvestedChicken  = 0;
    this->destroyedChicken  = 0;

    this->BR1foodAmountUsed = 0;
    this->BR2foodAmountUsed = 0;
    this->BR3foodAmountUsed = 0;

    this->totalFoodUsed     = 0;

    this->totalWaterUsed    = 0;

    this->totalChickWeight  = 0;

    this->BR1foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT);
    this->BR2foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT);
    this->BR3foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT);

    /* default values */
    this->pricePerYoungChick  = 8;        /* czech crowns per 1 1 day chick */
    this->chickPricePerKg     = 65;       /* 65kc/kg */
    this->BR1PricePerKg       = 15;       /* 15kc/kg */
    this->BR2PricePerKg       = 14;
    this->BR3PricePerKg       = 10;
    this->employeeCount       = 30;
    this->averagePayPerIteration = 566.66;

    srand(time(0));

#ifdef DEBUG
    cout << "Factory: Object initialised" << endl;
    cout << "Factory: Food delivery of BR1 " << this->BR1FoodAmount << " kg" << endl;
    cout << "Factory: Food delivery of BR2 " << this->BR2FoodAmount << " kg" << endl;
    cout << "Factory: Food delivery of BR3 " << this->BR3FoodAmount << " kg" << endl;
#endif

}

/**
 * @brief adds food in kilograms
 * @param amount adds number of kilograms specified
 */
void factory::addFood(int amount, int type) {
    switch(type){
        case 1: /* BR1 */
            this->BR1FoodAmount += amount;
            this->BR1foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT); /* add record about delivery */
            break;
        case 2: /* BR2 */
            this->BR2FoodAmount += amount;
            this->BR2foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT); /* add record about delivery */
            break;
        case 3: /* BR3 */
            this->BR3FoodAmount += amount;
            this->BR3foodDelivery.push_back(this->INITIAL_FOOD_AMOUNT); /* add record about delivery */
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
        /* if the chicken is dead, just skip it */
        if(it->isDead()){
            continue;
        }
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
    this->totalChickWeight += chick->getWeight();

}


/**
 * @brief man destroys chicks after it's death from disease
 */
void factory::destroyChick() {
    /* chicken is useless, just delete him */
#ifdef DEBUG
    cout << "Destroying chicken" << endl;
#endif
    this->destroyedChicken++;
}

/**
 * @brief print statistics
 */
void factory::statistics(std::vector<chicken> *chick) {

    double ChickSoldFor     = this->totalChickWeight/1000 * this->chickPricePerKg;
    double ChickBoughtFor   = chick->size() * this->pricePerYoungChick;
    double BR1Cost          = this->BR1foodAmountUsed * this->BR1PricePerKg;
    double BR2Cost          = this->BR2foodAmountUsed * this->BR2PricePerKg;
    double BR3Cost          = this->BR3foodAmountUsed * this->BR3PricePerKg;
    double TotalFoodCost    = BR1Cost + BR2Cost + BR3Cost;
    double TotalWaterCost   = this->waterCostPerL * this->totalWaterUsed;
    int salaries            = this->ITER_LENGTH * this->employeeCount * this->averagePayPerIteration;

    cout << fixed;

    cout    << "########## TOTAL STATISTICS NO."    << this->iterationCount << " ##########"                   << endl;
    cout    << "Chicken delivered:       " << this->harvestedChicken + this->destroyedChicken                  << endl;
    cout    << "Chicken infected:        " << this->destroyedChicken                                           << endl;
    cout    << "Chicken harvested:       " << this->harvestedChicken                                           << endl;
    cout    << "Total marketable weight: " << this->totalChickWeight / 1000 << " kilograms"                    << endl;
    cout    << "BR1 food used:           " << this->BR1foodAmountUsed << " kilograms"                          << endl;
    cout    << "BR2 food used:           " << this->BR2foodAmountUsed << " kilograms"                          << endl;
    cout    << "BR3 food used:           " << this->BR3foodAmountUsed << " kilograms"                          << endl;
    cout    << "Total food used:         " << this->totalFoodUsed << " kilograms"                              << endl;
    cout    << "Total water used:        " << this->totalWaterUsed << " liters\n"                              << endl;
    cout    << "### Financial report NO. " << this->iterationCount << "###"                                    << endl;

    cout    << "Employee count:                        " << this->employeeCount                                             << endl;
    cout    << "Total employee salaries per iteration: " << salaries            << " Kc"                                    << endl;
    cout    << "Chicken bought:                        " << chick->size()                                                   << endl;
    cout    << "Chickens bought for:                   " << ChickBoughtFor << " Kc"                                         << endl;
    cout    << "Chickens sold for:                     " << ChickSoldFor  << " Kc"                                          << endl;
    cout    << "Chicken profit:                        " << ChickSoldFor - ChickBoughtFor   << " Kc"                        << endl;
    cout    << "BR1 food cost:                         " << BR1Cost << " Kc"                                                << endl;
    cout    << "BR2 food cost:                         " << BR2Cost << " Kc"                                                << endl;
    cout    << "BR3 food cost:                         " << BR3Cost << " Kc"                                                << endl;
    cout    << "Total food cost:                       " << TotalFoodCost << " Kc"                                          << endl;
    cout    << "Used water cost:                       " << TotalWaterCost << " Kc"                                         << endl;
    cout    << "Total balance per iteration:           " << ChickSoldFor    - ChickBoughtFor - TotalFoodCost - TotalWaterCost
                                                                            - salaries << " Kc"                             << endl;
    this->iterationCount++;
}