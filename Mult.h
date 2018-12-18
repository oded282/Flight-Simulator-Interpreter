#ifndef FILGHT_SIMULATOR_MULT_H
#define FILGHT_SIMULATOR_MULT_H


#include "Expression.h"
#include "binaryExpression.h"

class Mult : binaryExpression
{

public:
    virtual double calculate();
};

#endif //FILGHT_SIMULATOR_MULT_H
