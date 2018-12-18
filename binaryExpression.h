

#ifndef FLIGHT_SIMULATOR_BINARYEXPRESSION_H
#define FLIGHT_SIMULATOR_BINARYEXPRESSION_H


#include "Expression.h"

class binaryExpression : public Expression {

protected:
    Expression* left;
    Expression* right;


public:
    binaryExpression(Expression *left, Expression *right);
    virtual double calculate();

};


#endif //FLIGHT_SIMULATOR_BINARYEXPRESSION_H
