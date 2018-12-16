#ifndef FILGHT_SIMULATOR_PLUS_H
#define FILGHT_SIMULATOR_PLUS_H


#include "Expression.h"

class Plus : public Expression
{
    Expression* left;
    Expression* right;
public:
    Plus(Expression* , Expression*);
    virtual double calculate();

};


#endif //FILGHT_SIMULATOR_PLUS_H
