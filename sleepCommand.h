#ifndef FLIGHT_SIMULATOR_SLEEPCOMMAND_H
#define FLIGHT_SIMULATOR_SLEEPCOMMAND_H


#include "Commands.h"

class sleepCommand : public Commands {

public:

    sleepCommand(mapCommand* commandMap , symbolTable* varTable) : Commands(commandMap,varTable) {}
    int execute(string);

};



#endif //FLIGHT_SIMULATOR_SLEEPCOMMAND_H
