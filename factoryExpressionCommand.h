#ifndef FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
#define FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H


#include <string>
#include "Expression.h"
#include "symbolTable.h"
#include "mapCommand.h"

using namespace std;


class factoryExpressionCommand {

    mapCommand* commandMap;

public:
    factoryExpressionCommand(mapCommand*);
    commandExpression* creatExpressionCommand(string str);
    ~factoryExpressionCommand(){}
};





#endif //FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
