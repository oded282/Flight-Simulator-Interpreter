
#ifndef FLIGHT_SIMULATOR_ASSIGNFACTORY_H
#define FLIGHT_SIMULATOR_ASSIGNFACTORY_H


#include "../commands/Commands.h"
#include "../utils/ConditionCounter.h"
#include "../commands/connectCommand.h"
#include "../utils/Parser.h"

class AssignFactory : public Commands {

    Parser* parser;
    ConditionCounter* counter;
    connectCommand* connect;

public:
    AssignFactory(ConditionCounter* counter,Parser* parser, connectCommand *connect,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard);
    void setCommand(string& str);
    int execute();
    ConditionCounter* getCounter();



};


#endif //FLIGHT_SIMULATOR_ASSIGNFACTORY_H
