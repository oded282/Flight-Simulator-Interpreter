#include <iostream>
#include "Parser.h"
#include "../commands/factoryExpressionCommand.h"

Parser::Parser(ConditionCounter* counter,const vector<string> &vectorInfo, mapCommand* commandMap) {
    Parser::counter = counter;
    Parser::vectorInfo = vectorInfo;
    Parser::index = 0;
    Parser::commandmap = commandMap;

}

vector<string> &Parser::getVector()  {
    return vectorInfo;
}

double Parser::getIndex() {
    return index;
}

void Parser::setIndex(int newIndex) {
    Parser::index = newIndex;
}

void Parser::setParser(const vector<string> &vector) {
    Parser::vectorInfo = vector;
}


void Parser::setMap(mapCommand *map) {
    Parser::commandmap = map;
}

/*
 * This func parse all the information from the file/user.
 */
vector<commandExpression*> Parser::doParser(int stopCase, bool isCalcNeeded) {
    vector<commandExpression*> expressionVector;
    factoryExpressionCommand factoryExpressionCommand(counter,commandmap);
    stopCase += index;
    while (index < stopCase){ // number of lines needed to be execute
        if(stopCase > vectorInfo.size()){ // case there is line deleted.
            stopCase = (int)vectorInfo.size();
        }
        commandExpression* e = factoryExpressionCommand.creatExpressionCommand(vectorInfo[(int)index]);
        expressionVector.push_back(e);
        index++;
        if(isCalcNeeded) { // case parsing only needed.
            e->calculate();
        }
    }
    return expressionVector;

}