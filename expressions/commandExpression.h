#ifndef FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
#define FLIGHT_SIMULATOR_COMMANDEXPRESSION_H


#include <cstdlib>
#include "Expression.h"
#include "../commands/Commands.h"


class commandExpression : public Expression {

    Commands* command;

public:
    commandExpression(Commands* command);
    double calculate();

    Commands* getCommand();

    ~commandExpression(){
        delete command;
    }
};

#endif //FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
