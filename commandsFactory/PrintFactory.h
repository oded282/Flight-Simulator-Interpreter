

#ifndef FLIGHT_SIMULATOR_PRINTFACTORY_H
#define FLIGHT_SIMULATOR_PRINTFACTORY_H


#include "../commands/Commands.h"
#include "../utils/ConditionCounter.h"
#include "../utils/Parser.h"


/**
 * This class creates new print commands
 */
class PrintFactory : public Commands {
    ConditionCounter* counter;
    Parser* parser;

public:
    PrintFactory(ConditionCounter* counter,Parser* parser,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard);
    void setCommand(string& str);
    int execute();
    ConditionCounter* getCounter();
};


#endif //FLIGHT_SIMULATOR_PRINTFACTORY_H
