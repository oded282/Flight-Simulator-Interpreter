#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include <string>
#include "Expression.h"
#include "Commands.h"

class openServerCommand : public Commands {

public:
    openServerCommand(mapCommand* commandMap , symbolTable* varTable) : Commands(commandMap,varTable) {}
    bool checkLegality(string);
    int execute(string);


};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H

