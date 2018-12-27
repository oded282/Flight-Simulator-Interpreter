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

void Parser::setParser(const vector<string> &vector) {
    Parser::vectorInfo = vector;
}


void Parser::setMap(mapCommand *map) {
    Parser::commandmap = map;
}

vector<commandExpression*> Parser::doParser(int stopCase) {
    vector<commandExpression*> expressionVector;
    factoryExpressionCommand factoryExpressionCommand(counter,commandmap);
    stopCase += index;
    while (index < stopCase){
        if(stopCase > vectorInfo.size()){
            stopCase = (int)vectorInfo.size();
        }
        //cout <<"check parser" << index << endl;
        commandExpression* e = factoryExpressionCommand.creatExpressionCommand(vectorInfo[(int)index]);
        expressionVector.push_back(e);
        index++;
        e->calculate();
    }
    return expressionVector;

}