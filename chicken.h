/**
 * author: Jiri Zahradnik
 * date: November 2015
 * brief: header file for chicken class
 */


class chicken;

#ifndef DRUBEZARNA_CHICKEN_H
#define DRUBEZARNA_CHICKEN_H

#include "factory.h"



class chicken {
private:
    /*
     * variables changing throughout life of the chicken
     */
    int dayOfLife;
    int weight;                 /* in grams */
    double currentWaterUsage;   /* in liters per chick */


    /*
     * constants
     */

    /*
     * average daily food requirement
     */
    const float AVG_DAILY_FOOD_INCOME   = 0.09524;

    const int BR1_END   = 10; /* border between BR1 and BR2 swap */
    const int BR2_END   = 25; /* border between BR2 and BR3 swap */

    /*
     * starting weight of chicks in grams
     */
    const int STARTING_WEIGHT = 40;

    /*
     * average weight gain per day
     */
    const int WEIGHT_GAIN_DAY_7   = 25;
    const int WEIGHT_GAIN_DAY_14  = 38;
    const int WEIGHT_GAIN_DAY_21  = 45;
    const int WEIGHT_GAIN_DAY_28  = 58;
    const int WEIGHT_GAIN_DAY_35  = 60;
    const int WEIGHT_GAIN_DAY_42  = 70;

    /*
     * weight border constants
     */
    const int DAY_7     = 7;    /* day 7 */
    const int DAY_14    = 15;  /* day 14 */
    const int DAY_21    = 21;  /* day 21 */
    const int DAY_28    = 28;  /* day 28 */
    const int DAY_35    = 35;  /* day 35 */
    const int DAY_42    = 42;  /* day 42 */

    /*
     * water usage constant
     * everything is in liters for 1000 chicks with temperature 21 degrees of Celsius
     * water usage is to certain age
     * =>   chicks younger than 7 days uses 65 liters of water/day
     *      chicks younger than 14 days uses 106 liters of water/day etc.
     */
    const float WATER_DAY_7   = 0.065;   /* day 7 */
    const float WATER_DAY_14  = 0.112;  /* day 14 */
    const float WATER_DAY_21  = 0.171;  /* day 21 */
    const float WATER_DAY_28  = 0.237;  /* day 28 */
    const float WATER_DAY_35  = 0.278;  /* day 35 */
    const float WATER_DAY_42  = 0.336;  /* day 42 */



    /*
     * death probability of each chick
     */
    const float deathProbability    = 2;  /* around 2% of total chicken will die */

    /*
     * 42 days to feed up a broiler,
     * source: en.aviagen.com/assets/Tech_Center/BB_Foreign_Language_Docs/Czech_aTechDocs/CZECH-Broiler-for-CDsmall.pdf
     */



public:
    /*
     * constants
     */


    const int BR1_starter   = 1;    /* feeding from 0 to 10th day of age */
    const int BR2_grower    = 2;    /* feeding from 11th to 26th day of age */
    const int BR3_finisher  = 3;    /* feeding from 26th to 42th day of age where broilers are killed */


    /*
     * water nipples per chick
     */
    const float water_nipple_count    = 0.083;

    double usedWater;           /* total water used */
    double BR1usedFood;         /* food used in grams */
    double BR2usedFood;         /* food used in grams */
    double BR3usedFood;         /* food used in grams */
    double totalFoodUsed;


    /*
     * method declarations
     */
    chicken();
    void    die(bool, factory*);    /* if false is set, it dies from disease, if true, it was killed by a man */
    void    feed(factory*);         /* feed everyday by specified time */
    void    addWeight();            /* adds weight based on dayOfLife */
    void    nextDay(factory*);      /* swaps discrete time to next day */
    int     getDay();               /* returns age of chicken in days */

};

#endif //DRUBEZARNA_CHICKEN_H
