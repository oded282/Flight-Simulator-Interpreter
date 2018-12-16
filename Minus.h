

#ifndef FLIGHT_SIMULATOR_MINUS_H
#define FLIGHT_SIMULATOR_MINUS_H


#include "Expression.h"

class Minus : public Expression{

    Expression* left;
    Expression* right;

public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();
};




#endif //FLIGHT_SIMULATOR_MINUS_H
