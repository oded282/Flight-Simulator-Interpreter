

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


class Mult : public binaryExpression
{

public:
    Mult(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual double calculate();
};


class Div : public binaryExpression{


public:
    virtual double calculate();
    Div(Expression* left, Expression* right) : binaryExpression(left , right){};

};

class Plus : public binaryExpression
{
public:
    Plus(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual double calculate();

};


class Minus : public binaryExpression{


public:
    Minus(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual double calculate();
};


#endif //FLIGHT_SIMULATOR_BINARYEXPRESSION_H
