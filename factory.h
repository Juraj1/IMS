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
    double totalChickWeight;
    /*
     * constants
     */
    const int INITIAL_FOOD_AMOUNT   = 100000;   /* kilos of food */
    const int ITER_LENGTH           = 42;       /* iteration length */



public:
    /*
     * variables
     */
    int pricePerYoungChick  ;        /* czech crowns per 1 1 day chick */
    int chickPricePerKg     ;        /* 65kc/kg */
    int BR1PricePerKg       ;        /* 15kc/kg */
    int BR2PricePerKg       ;
    int BR3PricePerKg       ;
    int employeeCount       ;
    double waterCostPerL;     /* price per liter, data from 2015 */

    double averagePayPerIteration;

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
    void nextDay(std::vector<chicken> *);
    void statistics(std::vector<chicken> *);


};


#endif //DRUBEZARNA_FACTORY_H
