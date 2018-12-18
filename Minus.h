

#ifndef FLIGHT_SIMULATOR_MINUS_H
#define FLIGHT_SIMULATOR_MINUS_H


#include "Expression.h"
#include "binaryExpression.h"

class Minus : public binaryExpression{


public:
    virtual double calculate();
};




#endif //FLIGHT_SIMULATOR_MINUS_H
