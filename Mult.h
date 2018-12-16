#ifndef FILGHT_SIMULATOR_MULT_H
#define FILGHT_SIMULATOR_MULT_H


#include "Expression.h"

class Mult : Expression
{
    Expression* left;
    Expression* right;

public:
    Mult(Expression* ,Expression*);
    virtual double calculate();
};

#endif //FILGHT_SIMULATOR_MULT_H
