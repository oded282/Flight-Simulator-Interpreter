#ifndef FLIGHT_SIMULATOR_SLEEPCOMMAND_H
#define FLIGHT_SIMULATOR_SLEEPCOMMAND_H


#include "Commands.h"

class sleepCommand : public Commands {
    int time;
public:

    sleepCommand(mapCommand* commandMap , symbolTable* varTable, ShuntingYard* shuntingYard) :
    Commands(commandMap,varTable, shuntingYard) {
        sleepCommand::time = 0;
    }
    int execute();
    void setCommand(string&);
    ~sleepCommand(){}

};



#endif //FLIGHT_SIMULATOR_SLEEPCOMMAND_H
