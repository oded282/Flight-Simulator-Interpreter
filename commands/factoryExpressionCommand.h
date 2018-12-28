#ifndef FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
#define FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H


#include <string>
#include "../expressions/commandExpression.h"
#include "../utils/ConditionCounter.h"

using namespace std;

/*
 * This class is the factory of all factories.
 * it checks which expression need to create and call the right factory to execute
 * the creation of the exp.
 */
class factoryExpressionCommand {

    mapCommand* commandMap;
    ConditionCounter* counter;
public:
    factoryExpressionCommand(ConditionCounter*,mapCommand*);
    commandExpression* creatExpressionCommand(string str);
    ~factoryExpressionCommand(){}
};





#endif //FLIGHT_SIMULATOR_FACTORYEXPRESSIONCOMMAND_H
