#ifndef FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
#define FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H


#include <string>
#include "../expressions/commandExpression.h"

using namespace std;


class factoryExpressionCommand {

    mapCommand* commandMap;

public:
    factoryExpressionCommand(mapCommand*);
    commandExpression* creatExpressionCommand(string str);
    ~factoryExpressionCommand(){}
};





#endif //FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
