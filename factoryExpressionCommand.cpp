#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "commandExpression.h"


factoryExpressionCommand::factoryExpressionCommand(mapCommand * mapCommand) {

    factoryExpressionCommand::commandMap = mapCommand;
}


Expression* factoryExpressionCommand::creatExpressionCommand(string str) {

    istringstream iss(str);
    vector<string> result(istream_iterator<std::string>{iss},
                               istream_iterator<std::string>());

    if (commandMap->getCommand((result[0])) == nullptr){
        throw "Invalid Command!";
    }

    commandMap->getCommand(result[0])->setCommand(str);

    Expression* c = new commandExpression(commandMap->getCommand(result[0]));

    return c;



}