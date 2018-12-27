#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "../expressions/commandExpression.h"
#include "varFactory.h"
#include "../ConditionCounter.h"


factoryExpressionCommand::factoryExpressionCommand(ConditionCounter* counter,mapCommand* mapCommand) {
    factoryExpressionCommand::counter = counter;
    factoryExpressionCommand::commandMap = mapCommand;
}


commandExpression *factoryExpressionCommand::creatExpressionCommand(string str) {

    istringstream iss(str);
    vector<string> result(istream_iterator<std::string>{iss},
                          istream_iterator<std::string>());


    if (commandMap->getCommandExpression((result[0])) == nullptr) {
        throw "Invalid Command!";
    }
    commandExpression *commandEx;
    if (result[1] == "=") {
        commandEx = commandMap->getCommandExpression("AssignFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[1] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "var"){

        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[1]);
    }else if(result[0] == "while" || result[0] == "if"){
        commandEx = commandMap->getCommandExpression("ConditionFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "print"){
        commandEx = commandMap->getCommandExpression("PrintFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "sleep"){
        commandEx = commandMap->getCommandExpression("SleepFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }
    else {
        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
    }
    //initialize command expression.
    return commandEx;
}