/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: source file for chicken class
 */

#include "chicken.h"
#include <iostream>

/**
 * @brief Constructor initialises values of chicken
 */
chicken::chicken() {
    this->dayOfLife         = 0;
    this->weight            = this->starting_weight;
    this->currentWaterUsage = this->WATER_DAY_7;
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
}

/**
 * @brief based on parameter 'man' the chicken dies by hand of man or from disease
 * @param man defines whether chicken dies by hand of man(True) or from disease(False)
 */
void chicken::die(bool man, factory *factory1) {
    /* chick can be eaten */
    if(man){
        factory1->harvestChick(nullptr);
    }
    /* chick must be destroyed */
    else{
        factory1->destroyChick(nullptr);
    }
}

/**
 * @brief feeds chicken
 */
void chicken::feed(factory *factory1) {
    factory1->substractFood(CHICKEN_COUNT*this->AVG_DAILY_FOOD_INCOME);
}

/**
 * @brief adds a day to the age if chicken
 */
void chicken::nextDay(factory *factory1) {
    this->dayOfLife++;
#ifdef DEBUG
    std::cout << this->dayOfLife << std::endl;
#endif

    this->feed(factory1);

    /* water usage modification */
    if(this->DAY_7 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_7;
    }
    else if(this->DAY_14 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_14;
    }
    else if(this->DAY_21 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_21;
    }
    else if(this->DAY_28 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_28;
    }
    else if(this->DAY_35 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_35;
    }
    else if(this->DAY_42 > this->dayOfLife){
        this->currentWaterUsage = this->WATER_DAY_42;
    }
    /* chick is ready for death */
    else if(this->DAY_42 <= this->dayOfLife){
        this->readyForDeath = true;
    }
}

/**
 * @brief returns status of chicks death flag
 */
bool chicken::checkDeathMark() {
    return this->readyForDeath;
}

/*
 * @brief returns chick's dayOfLife
 */
int chicken::getDay(){
    return this->dayOfLife;
}