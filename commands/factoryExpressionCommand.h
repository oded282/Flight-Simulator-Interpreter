#ifndef FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
#define FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H


#include <string>
#include "../expressions/commandExpression.h"
#include "../ConditionCounter.h"

using namespace std;


class factoryExpressionCommand {

    mapCommand* commandMap;
    ConditionCounter* counter;
public:
    factoryExpressionCommand(ConditionCounter*,mapCommand*);
    commandExpression* creatExpressionCommand(string str);
    ~factoryExpressionCommand(){}
};





#endif //FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
