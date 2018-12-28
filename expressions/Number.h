#ifndef FLIGHT_SIMULATOR_NUMBER_H
#define FLIGHT_SIMULATOR_NUMBER_H


#include "Expression.h"

/*
 * This class in the number expression.
 */
class Number: public Expression{

    float number;

public:
    Number(float number);
    virtual float calculate();
     ~Number(){}
};


#endif //FLIGHT_SIMULATOR_NUMBER_H
