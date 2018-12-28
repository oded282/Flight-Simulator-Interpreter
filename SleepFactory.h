//
// Created by oded on 12/27/18.
//

#ifndef FLIGHT_SIMULATOR_SLEEPFACTORY_H
#define FLIGHT_SIMULATOR_SLEEPFACTORY_H


#include "commands/Commands.h"
#include "utils/Parser.h"

/**
 * This class creates new sleep commands
 */
class SleepFactory : public Commands {
    ConditionCounter* counter;
    Parser* parser;
public:
    SleepFactory(ConditionCounter* counter,Parser* parser,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard);
    void setCommand(string& str);
    int execute();
    ConditionCounter* getCounter();
};


#endif //FLIGHT_SIMULATOR_SLEEPFACTORY_H
