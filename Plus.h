#ifndef FILGHT_SIMULATOR_PLUS_H
#define FILGHT_SIMULATOR_PLUS_H


#include "Expression.h"
#include "binaryExpression.h"

class Plus : public binaryExpression
{
public:
    virtual double calculate();

};


#endif //FILGHT_SIMULATOR_PLUS_H
