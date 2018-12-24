#include "Parser.h"
#include "factoryExpressionCommand.h"

Parser::Parser(const vector<string> &vectorInfo, mapCommand* commandMap) {

    Parser::vectorInfo = vectorInfo;
    Parser::index = 0;
    Parser::commandmap = commandMap;

}

const vector<string> &Parser::getVector() const {
    return vectorInfo;
}

double Parser::getIndex() const {
    return index;
}

void Parser::setParser(const vector<string> &vector) {
    Parser::vectorInfo = vector;
}


void Parser::setMap(mapCommand *map) {
    Parser::commandmap = map;
}

vector<commandExpression*> Parser::doParser(int stopCase) {
    vector<commandExpression*> expressionVector;
    factoryExpressionCommand factoryExpressionCommand(commandmap);

    while (index <= stopCase){

        commandExpression* e = factoryExpressionCommand.creatExpressionCommand(vectorInfo[(int)index]);
        expressionVector.push_back(e);
        e->calculate();
        index++;
    }
    return expressionVector;

}