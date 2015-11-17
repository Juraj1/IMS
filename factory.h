/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: header file for factory class
 */

class factory;

#ifndef DRUBEZARNA_FACTORY_H
#define DRUBEZARNA_FACTORY_H

#include <iostream>
#include <vector>

#include "chicken.h"


class factory {
private:
    double BR1FoodAmount;    /* kilos */
    double BR2FoodAmount;    /* kilos */
    double BR3FoodAmount;    /* kilos */

    int iterationCount;

    /*
     * constants
     */
    const int INITIAL_FOOD_AMOUNT = 100000; /* kilos of food */

public:
    /*
     * variables
     */

    int     dayOfWork;
    int     harvestedChicken;   /* total count of harvested chicken */
    int     destroyedChicken;   /* total count of destroyed chicken */

    double  BR1foodAmountUsed;  /* food amount used in KGs */
    double  BR2foodAmountUsed;  /* food amount used in KGs */
    double  BR3foodAmountUsed;  /* food amount used in KGs */

    double  totalFoodUsed;

    double totalWaterUsed;          /* total water used */

    std::vector<int> BR1foodDelivery;
    std::vector<int> BR2foodDelivery;
    std::vector<int> BR3foodDelivery;


    /*
     * methods
     */
    factory();
    void harvestChick(chicken*);
    void destroyChick();
    void addFood(int, int);
    void substractFood(float, int);
    void nextDay(std::vector<chicken> *);
    void statistics();


};


#endif //DRUBEZARNA_FACTORY_H
