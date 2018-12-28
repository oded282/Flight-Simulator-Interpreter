

#ifndef FLIGHT_SIMULATOR_BINARYEXPRESSION_H
#define FLIGHT_SIMULATOR_BINARYEXPRESSION_H


#include "Expression.h"

/**
 * This class used as an abstract class to all expressions.
 * it hold two expressions as members to all binary expressions.
 * the calculation of two expressions works as an recursions, due to
 * expression can be one big complex expression made up of couple expressions.
 */
class binaryExpression : public Expression {

protected:
    Expression* left;
    Expression* right;


public:
    binaryExpression(Expression *left, Expression *right);
    virtual float calculate();
    ~binaryExpression(){}

};

/*
 * This class use to calculate the multiplication of two expressions.
 */
class Mult : public binaryExpression
{

public:
    Mult(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual float calculate();
};

/*
 * This class use to calculate the deviation of two expressions.
 */
class Div : public binaryExpression{


public:
    virtual float calculate();
    Div(Expression* left, Expression* right) : binaryExpression(left , right){};

};

/*
 * This class use to calculate the sum of two expressions.
 */
class Plus : public binaryExpression
{
public:
    Plus(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual float calculate();

};

/*
 * This class use to calculate the subtraction of one expressionfrom the other.
 */
class Minus : public binaryExpression{


public:
    Minus(Expression* left, Expression* right) : binaryExpression(left , right){};
    virtual float calculate();
};


#endif //FLIGHT_SIMULATOR_BINARYEXPRESSION_H
