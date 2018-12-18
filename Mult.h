#ifndef FILGHT_SIMULATOR_MULT_H
#define FILGHT_SIMULATOR_MULT_H
#include "binaryExpression.h"

class Mult : binaryExpression
{

public:
    Mult(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual double calculate();
};

#endif //FILGHT_SIMULATOR_MULT_H
