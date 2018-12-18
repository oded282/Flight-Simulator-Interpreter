#ifndef FILGHT_SIMULATOR_DIV_H
#define FILGHT_SIMULATOR_DIV_H


#include "Expression.h"
#include "binaryExpression.h"

class Div : public binaryExpression{


public:
    virtual double calculate();
    Div(Expression* left, Expression* right) : binaryExpression(left , right){};

};


#endif //FILGHT_SIMULATOR_DIV_H
