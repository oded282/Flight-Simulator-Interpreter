#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "../expressions/commandExpression.h"
#include "varFactory.h"
#include "../utils/ConditionCounter.h"


factoryExpressionCommand::factoryExpressionCommand(ConditionCounter* counter,mapCommand* mapCommand) {
    factoryExpressionCommand::counter = counter;
    factoryExpressionCommand::commandMap = mapCommand;
}


commandExpression *factoryExpressionCommand::creatExpressionCommand(string str) {

    istringstream iss(str); // clean the string whitespaces and put each sentence inside vector.
    vector<string> result(istream_iterator<std::string>{iss},
                          istream_iterator<std::string>());


    if (commandMap->getCommandExpression((result[0])) == nullptr) {
        throw "Invalid Command!";
    }
    commandExpression *commandEx;
    if (result[1] == "=") { // case need to create assign command.
        commandEx = commandMap->getCommandExpression("AssignFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[1] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "var"){ // casr need to create variable.

        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[1]);
    }else if(result[0] == "while" || result[0] == "if"){ // case need to create condition command.
        commandEx = commandMap->getCommandExpression("ConditionFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "print"){ // case need to create print command.
        commandEx = commandMap->getCommandExpression("PrintFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }else if(result[0] == "sleep"){ // case need to create sleep command
        commandEx = commandMap->getCommandExpression("SleepFactory");
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[0] + to_string(counter->getCount()));
        counter->addCounter(1);
    }
    else { // case we need to create some other command
        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
    }
    //initialize command expression.
    return commandEx;
}