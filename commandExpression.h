#ifndef FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
#define FLIGHT_SIMULATOR_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Commands.h"

class commandExpression : public Expression {

    Commands* command;

public:
    commandExpression(Commands* command){ this->command = command;}

    double calculate();

};








#endif //FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
