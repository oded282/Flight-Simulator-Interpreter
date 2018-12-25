#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "commandExpression.h"
#include "varFactory.h"


factoryExpressionCommand::factoryExpressionCommand(mapCommand* mapCommand) {

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
        commandEx = commandMap->getCommandExpression("=");
        commandEx->getCommand()->setCommand(str);
    }else if(result[0] == "var"){

        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
        commandEx = commandMap->getCommandExpression(result[1]);
    }
    else {
        commandEx = commandMap->getCommandExpression(result[0]);
        commandEx->getCommand()->setCommand(str);
    }
    //initialize command expression.
    return commandEx;


}