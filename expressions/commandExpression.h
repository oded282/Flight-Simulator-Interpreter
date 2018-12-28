#ifndef FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
#define FLIGHT_SIMULATOR_COMMANDEXPRESSION_H


#include <cstdlib>
#include "Expression.h"
#include "../commands/Commands.h"

/**
 * This class used as and adapter command.
 * the class holds a command as a member and rap the command so
 * we earn hard polymorphism to work with.
 */
class commandExpression : public Expression {

    Commands* command;

public:
    commandExpression(Commands* command);
    float calculate();

    Commands* getCommand();

    ~commandExpression(){
        delete command;
    }
};

#endif //FLIGHT_SIMULATOR_COMMANDEXPRESSION_H
