/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: source file for chicken class
 */

#include "chicken.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Constructor initialises values of chicken
 */
chicken::chicken() {
    /* private variables */
    this->dayOfLife = 0;
    this->weight    = this->STARTING_WEIGHT;
    this->dead = false;

    this->currentWaterUsage = this->WATER_DAY_7;

    /* public variables */
    this->usedWater     = 0;
    this->BR1usedFood   = 0;
    this->BR2usedFood   = 0;
    this->BR3usedFood   = 0;
    this->totalFoodUsed = 0;

#ifdef DEBUG
    cout << "Chicken object initialised" << endl;
#endif
}

/**
 * @brief adds certain amount of weight to current weight each day
 */
void chicken::addWeight() {
    /* if chicken is younger than 7 days, add constant */
    if(this->DAY_7 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_7;
    }
    /* chicken is older than 7 days, but younger than 14 days */
    else if(this->DAY_14 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_14;
    }
    /* chicken is older than 14 days, but younger than 21 days */
    else if(this->DAY_21 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_21;
    }
    /* chicken is older than 21 days, but younger than 28 days */
    else if(this->DAY_28 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_28;
    }
    /* chicken is older than 28 days, but younger than 35 days */
    else if(this->DAY_35 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_35;
    }
    /* chicken is older than 35 days, but younger than 42 days */
    else if(this->DAY_42 > this->dayOfLife){
        this->weight += this->WEIGHT_GAIN_DAY_42;
    }
#ifdef DEBUG
    cout << "Chicken's weight is: " << this->weight << " grams" << endl;
#endif
}

/**
 * @brief based on parameter 'man' the chicken dies by hand of man or from disease
 * @param man defines whether chicken dies by hand of man(True) or from disease(False)
 */
void chicken::die(bool man, factory *factory1) {
    this->dead = true;
    /* chick can be eaten */
    if(man){
        factory1->harvestChick(this);
    }
    /* chick must be destroyed */
    else{
        factory1->destroyChick();
    }
}

/**
 * @brief feeds chicken
 */
void chicken::feed() {
    if(this->dayOfLife < BR1_END){
        this->BR1usedFood   += this->AVG_DAILY_FOOD_INCOME;
        this->totalFoodUsed += this->AVG_DAILY_FOOD_INCOME;
    }
    else if(this->dayOfLife < BR2_END){
        this->BR2usedFood   += this->AVG_DAILY_FOOD_INCOME;
        this->totalFoodUsed += this->AVG_DAILY_FOOD_INCOME;
    }
    else if(this->dayOfLife <= this->DAY_42){
        this->BR3usedFood   += this->AVG_DAILY_FOOD_INCOME;
        this->totalFoodUsed += this->AVG_DAILY_FOOD_INCOME;
    }
}

/**
 * @brief chicken drinks
 */
void chicken::drink(){
    /* water usage modification */
    if(this->DAY_7 > this->dayOfLife){
#ifdef DEBUG
        cout << "Water usage day 0 - 7" << endl;
#endif
        this->currentWaterUsage = this->WATER_DAY_7;
    }
    else if(this->DAY_14 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_14;
#ifdef DEBUG
        cout << "Water usage day 7 - 14" << endl;
#endif
    }
    else if(this->DAY_21 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_21;
#ifdef DEBUG
        cout << "Water usage day 14 - 21" << endl;
#endif
    }
    else if(this->DAY_28 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_28;
#ifdef DEBUG
        cout << "Water usage day 21 - 28" << endl;
#endif
    }
    else if(this->DAY_35 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_35;
#ifdef DEBUG
        cout << "Water usage day 28 - 35" << endl;
#endif
    }
    else if(this->DAY_42 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_42;
#ifdef DEBUG
        cout << "Water usage day 35 - 42" << endl;
#endif
    }

    this->usedWater += this->currentWaterUsage;


}

/**
 * @brief adds a day to the age if chicken
 */
void chicken::nextDay(factory *factory1) {
    this->dayOfLife++;
#ifdef DEBUG
    cout << "Chicken moved to next day" << endl;
#endif

    this->feed();
    this->drink();
    this->addWeight();


    /*
     * death here
     */


    /* die from infection */
    bool TrueFalse = (rand() % 10000) <= this->deathProbability;
    if(TrueFalse){
#ifdef DEBUG
        cout << "Chicken infected" << endl;
#endif
        this->die(false, factory1);
        return;
    }


    if(this->dayOfLife >= this->DAY_42){
#ifdef DEBUG
        cout << "Chicken killed by human" << endl;
#endif
        this->die(true, factory1);
    }

}

/*
 * @brief returns chick's dayOfLife
 */
int chicken::getDay(){
    return this->dayOfLife;
}

/*
 * @brief returns whether chick is dead or alive
 */
bool chicken::isDead(){
    return this->dead;
}

/*
 * @brief returns chick's weight
 */
int chicken::getWeight(){
    return this->weight;
}