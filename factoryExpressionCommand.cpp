#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "commandExpression.h"


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
    } else {
        commandEx = commandMap->getCommandExpression(result[0]);
    }
    //initialize command expression.
    commandEx->getCommand()->setCommand(str);

    return commandEx;


}