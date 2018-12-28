//
// Created by oded on 12/26/18.
//

#ifndef FLIGHT_SIMULATOR_CONDITIONFACTORY_H
#define FLIGHT_SIMULATOR_CONDITIONFACTORY_H


#include "Commands.h"
#include "../utils/Parser.h"
#include "../ConditionParser.h"

/*
 * This class is a factory to all commands who uses conditions.
 * while and if commands for example.
 */
class ConditionFactory : public Commands {
    Parser* parser;
    ConditionCounter* counter;

public:
    ConditionFactory(ConditionCounter* counter,Parser* parser,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard)
    : Commands (commandTable,varTable,shuntingYard){
        this->parser = parser;
        this->counter = counter;
    }
    commandExpression* creatCondition(string str);
    virtual void setCommand(string& str);
    virtual int execute();
    ConditionCounter* getCounter();
};


#endif //FLIGHT_SIMULATOR_CONDITIONFACTORY_H
