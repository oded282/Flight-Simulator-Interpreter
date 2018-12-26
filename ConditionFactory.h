//
// Created by oded on 12/26/18.
//

#ifndef FLIGHT_SIMULATOR_CONDITIONFACTORY_H
#define FLIGHT_SIMULATOR_CONDITIONFACTORY_H


#include "Commands.h"
#include "Parser.h"
#include "ConditionParser.h"

class ConditionFactory : public Commands {
    Parser* parser;


public:
    ConditionFactory(Parser* parser,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard)
    : Commands (commandTable,varTable,shuntingYard){
        this->parser = parser;
    }
    commandExpression* creatCondition(string str);
};


#endif //FLIGHT_SIMULATOR_CONDITIONFACTORY_H
