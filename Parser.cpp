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



void Parser::doParser() {

    factoryExpressionCommand  factoryExpressionCommand(commandmap);

    while (index <= vectorInfo.size()){

        Expression* e = factoryExpressionCommand.creatExpressionCommand(vectorInfo[(int)index]);

        index += e->calculate();


    }

}