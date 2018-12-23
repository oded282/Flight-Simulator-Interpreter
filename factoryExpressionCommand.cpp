#include <iterator>
#include <sstream>
#include "factoryExpressionCommand.h"
#include "commandExpression.h"


Expression* factoryExpressionCommand::creatExpressionCommand(string str) {

    istringstream iss(str);
    vector<string> result(istream_iterator<std::string>{iss},
                               istream_iterator<std::string>());

    commandMap.getCommand(result[0])->setCommand(str);

    Expression* c = new commandExpression(commandMap.getCommand(result[0]));

    return c;



}