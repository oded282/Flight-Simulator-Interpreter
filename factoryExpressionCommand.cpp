#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "commandExpression.h"


factoryExpressionCommand::factoryExpressionCommand(mapCommand *mapCommand) {

    factoryExpressionCommand::commandMap = mapCommand;
}


commandExpression *factoryExpressionCommand::creatExpressionCommand(string str) {

    istringstream iss(str);
    vector<string> result(istream_iterator<std::string>{iss},
                          istream_iterator<std::string>());


    if (commandMap->getCommandExpression((result[0])) == nullptr) {
        throw "Invalid Command!";
    }
    commandExpression *commandExpression;
    if (result[1] == "=") {
        commandExpression = commandMap->getCommandExpression("=");
    } else {
        commandExpression = commandMap->getCommandExpression(result[0]);
    }
    //initialize command expression.
    commandExpression->getCommand()->setCommand(str);

    return commandExpression;


}