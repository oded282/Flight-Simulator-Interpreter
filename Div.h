#ifndef FILGHT_SIMULATOR_DIV_H
#define FILGHT_SIMULATOR_DIV_H


#include "Expression.h"

class Div : public Expression{

    Expression* left;
    Expression* right;

public:
    Div(Expression* , Expression*);
    virtual double calculate();

};


#endif //FILGHT_SIMULATOR_DIV_H
