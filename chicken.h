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
    int weight;             /* in grams */
    int currentWaterUsage;  /* in liters per 1000 chicks */
    bool readyForDeath;     /* ready for death flag */

    /*
     * constants
     */

    /*
     * 1 object is simulating 1000 chicks
     */
    const int CHICKEN_COUNT = 1000;

    /*
     * average daily food requirement
     */
    const float AVG_DAILY_FOOD_INCOME   = 95.24;

    const int BR1_END   = 10; /* border between BR1 and BR2 swap */
    const int BR2_END   = 25; /* border between BR2 and BR3 swap */

    /*
     * starting weight of chicks in grams
     */
    const int starting_weight   = 40;

    /*
     * average weight gain per day
     */
    const int WEIGHT_GAIN_DAY_7   = 18;
    const int WEIGHT_GAIN_DAY_14  = 28;
    const int WEIGHT_GAIN_DAY_21  = 37;
    const int WEIGHT_GAIN_DAY_28  = 46;
    const int WEIGHT_GAIN_DAY_35  = 53;
    const int WEIGHT_GAIN_DAY_42  = 58;

    /*
     * weight border constants
     */
    const int DAY_7     = 7;    /* day 7 */
    const int DAY_14    = 112;  /* day 14 */
    const int DAY_21    = 171;  /* day 21 */
    const int DAY_28    = 237;  /* day 28 */
    const int DAY_35    = 278;  /* day 35 */
    const int DAY_42    = 336;  /* day 42 */

    /*
     * water usage constant
     * everything is in liters for 1000 chicks with temperature 21 degrees of Celsius
     * water usage is to certain age
     * =>   chicks younger than 7 days uses 65 liters of water/day
     *      chicks younger than 14 days uses 106 liters of water/day etc.
     */
    const int WATER_DAY_7   = 65;   /* day 7 */
    const int WATER_DAY_14  = 112;  /* day 14 */
    const int WATER_DAY_21  = 171;  /* day 21 */
    const int WATER_DAY_28  = 237;  /* day 28 */
    const int WATER_DAY_35  = 278;  /* day 35 */
    const int WATER_DAY_42  = 336;  /* day 42 */

    /*
     * water nipples per 1000 chicks
     */
    const int water_nipple_count    = 83;

    /*
     * death probability of each chick
     */
    const float deathProbability    = 0.02;  /* around 2% of total chicken will die */

    /*
     * 42 days to feed up a broiler,
     * source: en.aviagen.com/assets/Tech_Center/BB_Foreign_Language_Docs/Czech_aTechDocs/CZECH-Broiler-for-CDsmall.pdf
     */
    const int FinalDay              = 42;
    typedef enum{
        BR1_starter                 = 1,    /* feeding from 0 to 10th day of age */
        BR2_grower,                         /* feeding from 11th to 26th day of age */
        BR3_finisher,                       /* feeding from 26th to 42th day of age where broilers are killed */
    }food;

public:
    /*
     * method declarations
     */
    chicken();
    void    chickenInit();         /* chicken is delivered at age 0 for feeding */
    void    die(bool, factory*);   /* if false is set, it dies from disease, if true, it was killed by a man */
    void    feed(factory*);        /* feed everyday by specified time */
    void    addWeight();           /* adds weight based on dayOfLife */
    void    nextDay(factory*);     /* swaps discrete time to next day */
    bool    checkDeathMark();      /* returns status of chick's death mark */
    int     getDay();

};

#endif //DRUBEZARNA_CHICKEN_H
