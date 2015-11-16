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
    double foodAmountGrams; /* grams */

    /*
     * constants
     */
    const int INITIAL_FOOD_AMOUNT_TONNES    = 100000; /* tonnes of food */
    const int CHICK_CAPACITY                = 10000;

public:
    /*
     * variables
     */
    
    int dayOfWork;

    /*
     * methods
     */
    factory();
    void harvestChick(chicken*);
    void destroyChick(chicken*);
    void addFood(int);
    void substractFood(float);
    void nextDay(std::vector<chicken> *);

};


#endif //DRUBEZARNA_FACTORY_H
